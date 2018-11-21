//
// EPITECH PROJECT, 2018
// Indie
// File description:
// Indie
//

#include "Core.hpp"

Core::Core(const bool &multiplayer, IndieWindow *win,
	IndieEventReceiver &receiver)
	: _window(win), _receiver(receiver), _multiplayer(multiplayer),
	_width(15), _height(15)
{
	BasicPlayer *p1 = new PC(win, 1, irr::core::vector2df(1.5, _height - 1.5));
	BasicPlayer *p2;
	BasicPlayer *p3 = new NPC(win, 3, irr::core::vector2df(1.5, 1.5));
	BasicPlayer *p4 = new NPC(win, 4, irr::core::vector2df(_width - 1.5, 1.5));
	if (multiplayer == true)
		p2 = new PC(win, 2, irr::core::vector2df(_width - 1.5,
							_height - 1.5));
	else
		p2 = new NPC(win, 2, irr::core::vector2df(_width - 1.5,
							_height - 1.5));
	_players.push_back(p1);
	_players.push_back(p2);
	_players.push_back(p3);
	_players.push_back(p4);
	initFloor();
	_map = new Map(win, _width, _height);
}

Core::~Core()
{
	for (auto& it : _players)
		delete it;
	delete _map;
	delete _floor;
}

void	Core::initFloor()
{
	irr::core::vector3df	scale(B_SIZE * _width, B_SIZE,
					B_SIZE * _height);
	irr::core::vector3df	pos(scale.X / 2 - B_SIZE / 2, -B_SIZE - 2,
					-scale.Z / 2 + B_SIZE / 2 + 5);
	
	Info3d	info(pos, 1);
	info.setScale(scale);
	_floor = new GraphObj(_window, "Floor", info);
}

void Core::addPowerup(BasicPlayer *player, int x, int y)
{
	IObject *obj = _map->getObject(x, y);
	int type = obj->getType();
	switch (type) {
	case 0 :
		player->setMaxBomb(player->getMaxBomb() + 1);
		_map->removeObject(x, y);
		break;
	case 1 :
		player->setSpeed(player->getSpeed() + 0.01);
		_map->removeObject(x, y);
		break;
	case 2 :
		player->setPower(player->getPower() + 1);
		_map->removeObject(x, y);
		break;
	case 3 :
		player->setNoClip(true);
		_map->removeObject(x, y);
		break;
	}
}

bool Core::playerNoClipped(int x, int y)
{
	bool ret = false;
	IObject *obj = _map->getObject(x, y);
	if (obj != NULL && obj->getType() == BLOCK)
		ret = true;
	return ret;
}

int Core::offset(float pos, float add)
{
	float tmp = add;
	float offset = 0.2;
	if (tmp < 0)
		offset = offset * (-1);
	if (tmp != 0)
		tmp += offset;
	float ret = (int)(pos + tmp);
	return (ret);
}

bool Core::playerOffset(BasicPlayer *player, float ax, float ay)
{
	bool ret = false;
	float x = player->getPos().X;
	float y = player->getPos().Y;
	IObject *obj = _map->getObject(offset(x, ax), offset(y, ay));
	if (obj != NULL && obj->getType() == BLOCK
	&& player->getNoClip() == false)
		ret = true;
	else if (obj != NULL && obj->getType() == WALL)
		ret = true;
	return (ret);
}

void Core::movePlayer(BasicPlayer *player, direction dir)
{
	float x = player->getPos().X;
	float y = player->getPos().Y;
	float dist = player->getSpeed();
	float ax = (dir == LEFT ? (dist * (-1)) : (dir == RIGHT ? dist : 0));
	float ay = (dir == UP ? (dist * (-1)) : (dir == DOWN ? dist : 0));
	if (playerOffset(player, ax, ay) == true)
		return;
	IObject *obj = _map->getObject((int)(x + ax), (int)(y + ay));
	player->run();
	if (obj != NULL && obj->getType() == BLOCK
	&& player->getNoClip() == true) {
		player->setPos(irr::core::vector2df((x + ax), (y + ay)));
	} else if (obj == NULL || obj->getType() <= WALL_PASS) {
		if (obj != NULL)
			addPowerup(player, (int)(x + ax), (int)(y + ay));
		if (playerNoClipped((int)(x), (int)(y)) == true)
			player->setNoClip(false);
		player->setPos(irr::core::vector2df((x + ax), (y + ay)));
	} else if ((int)(x + ax) == (int)(x) && (int)(y + ay) == (int)(y))
		player->setPos(irr::core::vector2df((x + ax), (y + ay)));
}

void Core::placeBomb(BasicPlayer *player)
{
	int x = (int)((player->getPos()).X);
	int y = (int)((player->getPos()).Y);
	if (_map->getObject(x, y) == NULL) {
		IObject *newBomb = new Bomb(_window, player->getPower(),
					irr::core::vector2di(x, y));
		_map->addObject(x, y, newBomb);
		player->setBomb();
	}
}

void Core::updatePlayer(BasicPlayer *player)
{
	if (player->isPlayer() == true) {
		PC *pcCast = static_cast<PC *>(player);
		pcCast->updatePlayer(_receiver);
	} else {
		NPC *npcCast = static_cast<NPC *>(player);
		npcCast->updatePlayer(_map, _players);
	}
	if (player->getDir(false) != NONE)
		movePlayer(player, player->getDir(true));
	else
		player->stand();
	if (player->canPlaceBomb() == true) {
		placeBomb(player);
	}
}

bool Core::getMultiplayer()
{
	return (_multiplayer);
}

bool Core::isOver()
{
	if (_multiplayer == true) {
		if (_players[0]->isActive() == false
		    && _players[1]->isActive() == false) {
			_window->getMenu()->loseMenu();
			return (true);
		} else if (_players[2]->isActive() == false
			&& _players[3]->isActive() == false) {
			_window->getMenu()->winMenu();
			return (true);
		}
	} else {
		if (_players[0]->isActive() == false) {
			_window->getMenu()->loseMenu();
			return (true);
		} else if (_players[1]->isActive() == false
			&& _players[2]->isActive() == false
			&& _players[3]->isActive() == false) {
			_window->getMenu()->winMenu();
			return (true);
		}
	}
	return (false);
}

bool Core::exec()
{
	if (isOver() == true)
		return (false);
        for (auto it = _players.begin(); it != _players.end(); it++)
		if ((*it)->isActive() == true)
			updatePlayer(*it);
	_map->updateBombs(_players);
	return (true);
}

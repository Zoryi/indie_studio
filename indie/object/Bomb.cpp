//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Bomb
//

#include "Bomb.hpp"

Bomb::Bomb(IndieWindow *indie, size_t power, irr::core::vector2di pos)
{
	Info3d	info(irr::core::vector3df(pos.X * B_SIZE, -5, -pos.Y * B_SIZE),
			(float)B_SIZE / 18);
	
	_t = stdclock::now();
	_graphObj = new GraphObj(indie, "Bomb", info);
	_power = power;
	_pos = pos;
	_explode = false;
	_window = indie;
}

Bomb::~Bomb()
{
	for (auto& it : _anims)
		delete it;
	if (_graphObj)
		delete _graphObj;
}

unsigned long long Bomb::getTimer()
{
	unsigned long long dif;
	dif = std::chrono::duration_cast<ms>(stdclock::now() - _t).count();
	return (dif);
}

bool Bomb::isWall(Map *map, std::vector<BasicPlayer *> &players,
		const size_t &x, const size_t &y)
{
	IObject *obj = map->getObject(x, y);
	if (obj != NULL) {
		objType type = obj->getType();
		if (type == BLOCK) {
			breakItem(map, players, x, y);
			return (true);
		} else if (type == WALL)
			return (true);
	}
	return (false);
}

void Bomb::breakItem(Map *map, std::vector<BasicPlayer *> &players,
		const size_t &x, const size_t &y)
{
	IObject *obj = map->getObject(x, y);
	float fx = (float)x;
	float fy = (float)y;
        Info3d  info(irr::core::vector3df(fx * B_SIZE, -5, -fy * B_SIZE),
		     (float)B_SIZE / 100);

        _anims.push_back(new AnimFireExplo(_window, info));
	if (obj != NULL) {
		objType type = obj->getType();
		if (type == BLOCK)
			map->removeObject(x, y);
		else if (type == BOMB && obj != this &&
			 !((Bomb*)obj)->getExplode())
			((Bomb*)obj)->explode(map, players);
	}
	for (auto& it : players) {
		auto pos = it->getPos();
		if ((int)pos.X == (int)x && (int)pos.Y == (int)y) {
			_window->getSound()->playSound("media/Die.ogg");
			it->deletePlayer();
		}
	}
}

void Bomb::explode(Map *map, std::vector<BasicPlayer *> &players)
{
	int	x = _pos.X;
	int	y = _pos.Y;

	_explode = true;
	_window->getSound()->playSound("media/Explo.ogg");
	delete _graphObj;
	_graphObj = NULL;
	breakItem(map, players, x, y);
	for (int posx = x + 1; posx <= x + (int)(_power)
		&& isWall(map, players, posx, y) == false; posx++)
		breakItem(map, players, posx, y);
	for (int posx = x - 1; posx >= x - (int)(_power)
		&& isWall(map, players, posx, y) == false; posx--)
		breakItem(map, players, posx, y);
	for (int posy = y + 1; posy <= y + (int)(_power)
		&& isWall(map, players, x, posy) == false; posy++)
		breakItem(map, players, x, posy);
	for (int posy = y - 1; posy >= y - (int)(_power)
		&& isWall(map, players, x, posy) == false; posy--)
		breakItem(map, players, x, posy);
}

bool	Bomb::getExplode()
{
	return _explode;
}

objType	Bomb::getType()
{
	return BOMB;
}

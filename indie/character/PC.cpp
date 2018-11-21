//
// EPITECH PROJECT, 2018
// Indie
// File description:
// Indie
//

#include "PC.hpp"

PC::PC(IndieWindow *indie, const int &id, irr::core::vector2df pos)
	: BasicPlayer(id, pos, true), _runing(false)
{
	Info3d	info(irr::core::vector3df((pos.X - 0.5) * B_SIZE, 0,
			-(pos.Y - 0.5) * B_SIZE), (float)B_SIZE / 40);
	irr::core::vector3df	tmpPos(20, 20, -210);

	_graphObj = new GraphObj(indie, "Player", info);
	if (id == 2)
		tmpPos.X = 150;
	_ui = new UI(indie, tmpPos, this);
}

PC::~PC()
{
	if (_graphObj)
		delete _graphObj;
	if (_ui)
		delete _ui;
}

void PC::deletePlayer()
{
	_active = false;
	_pos.X = -1;
	_pos.Y = -1;
	if (_graphObj)
		delete _graphObj;
	_graphObj = NULL;
	if (_ui)
		delete _ui;
	_ui = NULL;
}

void	PC::setPos(irr::core::vector2df pos)
{
	_pos.X = pos.X;
	_pos.Y = pos.Y;
	if (_graphObj)
		_graphObj->setPos(irr::core::vector3df((pos.X - 0.5) * B_SIZE,
					0, -(pos.Y - 0.5) * B_SIZE));
}

void    PC::setDir(direction dir)
{
 	irr::core::vector3df    rot(_graphObj->getRotate());

        _dir = dir;
	if (dir != NONE)
                rot.Y = -dir * 90;
        _graphObj->setRotate(rot);
}


int PC::catchP1(IndieEventReceiver &receiver)
{
	if (receiver.IsKeyDown(irr::KEY_UP))
		return (1);
	else if (receiver.IsKeyDown(irr::KEY_DOWN))
		return (2);
	else if (receiver.IsKeyDown(irr::KEY_LEFT))
		return (3);
	else if (receiver.IsKeyDown(irr::KEY_RIGHT))
		return (4);
	else if (receiver.IsKeyDown(irr::KEY_RSHIFT))
		return (5);
	return (0);
}

int PC::catchP2(IndieEventReceiver &receiver)
{
	if (receiver.IsKeyDown(irr::KEY_KEY_Z))
		return (1);
	else if (receiver.IsKeyDown(irr::KEY_KEY_S))
		return (2);
	else if (receiver.IsKeyDown(irr::KEY_KEY_Q))
		return (3);
	else if (receiver.IsKeyDown(irr::KEY_KEY_D))
		return (4);
	else if (receiver.IsKeyDown(irr::KEY_KEY_E))
		return (5);
	return (0);
}

void PC::updatePlayer(IndieEventReceiver &receiver)
{
	direction dir = NONE;
	int input;
	updateCooldown();
	if (_playerID == 1)
		input = catchP1(receiver);
	else if (_playerID == 2)
		input = catchP2(receiver);
	if (input > 0 && input < 5)
		dir = (input == 1 ? UP : (input == 2 ? DOWN :
					(input == 3 ? LEFT : RIGHT)));
	setDir(dir);
	if (input == 5) {
		placeBomb();
	}
	_ui->update();
}

void	PC::run()
{
	if (!_runing){
		_graphObj->setAnim(irr::scene::EMAT_RUN);
		_runing = true;
	}
}

void	PC::stand()
{
	if (_runing){
		_graphObj->setAnim(irr::scene::EMAT_STAND);
		_runing = false;
	}
}

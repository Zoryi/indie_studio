//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// UI.cpp
//

#include "UI.hpp"

UI::UI(IndieWindow *win, irr::core::vector3df pos, PC *player)
	: _win(win), _pos(pos), _player(player)
{
	if (pos.X < 0)
		initTexts(1);
	else
		initTexts(-1);
}

UI::~UI()
{
	for (auto& a : _texts)
		delete a;
	delete _maxBomb;
	delete _power;
}

void	UI::initTexts(int id)
{
	Info3d	info(_pos, 10);
	irr::core::vector3df	tmpPos(_pos);

	id = id;
	info.setRotate(90, 0, 0);
	_texts.push_back(new GraphObj(_win, "MaxBomb", info));
	tmpPos.X += 50;
	info.setPos(tmpPos);
	_maxBomb = new GraphNb(_win, _player->getMaxBomb(), info);
	tmpPos.X -= 50;
	tmpPos.Z -= 10;
	info.setPos(tmpPos);
	_texts.push_back(new GraphObj(_win, "Power", info));
	tmpPos.X += 30;
	info.setPos(tmpPos);
	_power = new GraphNb(_win, _player->getPower(), info);
	tmpPos.X -= 30;
}

void	UI::update()
{
	_power->changeNb(_player->getPower());
	_maxBomb->changeNb(_player->getMaxBomb());
}

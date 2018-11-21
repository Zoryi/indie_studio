//
// EPITECH PROJECT, 2018
// indie_studio
// File description:
// BombUp.cpp
//

#include "BombUp.hpp"

BombUp::BombUp(IndieWindow *indie, irr::core::vector2di pos)
{
	Info3d	info(irr::core::vector3df(pos.X * B_SIZE, -5, -pos.Y * B_SIZE),
			(float)B_SIZE / 18);
		     
	_graphObj = new GraphObj(indie, "BombUp", info);
	_pos = pos;
}

BombUp::~BombUp()
{
	delete _graphObj;
}

objType	BombUp::getType()
{
	return BOMB_UP;
}

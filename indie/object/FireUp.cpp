//
// EPITECH PROJECT, 2018
// indie_studio
// File description:
// FireUp.cpp
//

#include "FireUp.hpp"

FireUp::FireUp(IndieWindow *indie, irr::core::vector2di pos)
{
	Info3d	info(irr::core::vector3df(pos.X * B_SIZE, -5, -pos.Y * B_SIZE),
			(float)B_SIZE / 18);
	
	_graphObj = new GraphObj(indie, "FireUp", info);
	_pos = pos;
}

FireUp::~FireUp()
{
	delete _graphObj;
}

objType	FireUp::getType()
{
	return FIRE_UP;
}

//
// EPITECH PROJECT, 2018
// indie_studio
// File description:
// WallPass.cpp
//

#include "WallPass.hpp"

WallPass::WallPass(IndieWindow *indie, irr::core::vector2di pos)
{
	Info3d	info(irr::core::vector3df(pos.X * B_SIZE, -5, -pos.Y * B_SIZE),
			(float)B_SIZE / 18);
	
	_graphObj = new GraphObj(indie, "WallPass", info);
	_pos = pos;
}

WallPass::~WallPass()
{
	delete _graphObj;
}

objType	WallPass::getType()
{
	return WALL_PASS;
}

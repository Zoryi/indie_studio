//
// EPITECH PROJECT, 2018
// indie_studio
// File description:
// Block.cpp
//

#include "Block.hpp"

Block::Block(IndieWindow *indie, bool breakable, irr::core::vector2di pos) :
	_breakable(breakable)
{
	Info3d	info(irr::core::vector3df(pos.X * B_SIZE, 0, -pos.Y * B_SIZE),
			B_SIZE);
	
	_graphObj = new GraphObj(indie, (breakable ? "Block2" : "Block1"),
				 info);
	_pos = pos;
}

Block::~Block()
{
	delete _graphObj;
}

objType	Block::getType()
{
	if (_breakable)
		return BLOCK;
	else
		return WALL;
}

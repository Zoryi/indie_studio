//
// EPITECH PROJECT, 2018
// indie_studio
// File description:
// SpeedUp.cpp
//

#include "SpeedUp.hpp"

SpeedUp::SpeedUp(IndieWindow *indie, irr::core::vector2di pos)
{
	Info3d	info(irr::core::vector3df(pos.X * B_SIZE, -5, -pos.Y * B_SIZE),
			(float)B_SIZE / 18);
	
        _graphObj = new GraphObj(indie, "SpeedUp", info);
	_pos = pos;
}

SpeedUp::~SpeedUp()
{
	delete _graphObj;
}

objType	SpeedUp::getType()
{
	return SPEED_UP;
}

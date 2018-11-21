//
// EPITECH PROJECT, 2018
// indie_studio
// File description:
// Info3d.cpp
//

#include "Info3d.hpp"

Info3d::Info3d(irr::core::vector3df pos, irr::f32 scale) :
	_pos(pos), _scale(scale, scale, scale), _rotate(0, 0, 0)
{	
}

Info3d::~Info3d()
{
}

irr::core::vector3df	Info3d::getPos()
{
	return _pos;
}

void	Info3d::setPos(irr::core::vector3df pos)
{
        _pos = pos;
}

irr::core::vector3df	Info3d::getScale()
{
	return _scale;
}

void	Info3d::setScale(irr::core::vector3df scale)
{
        _scale = scale;
}

irr::core::vector3df	Info3d::getRotate()
{
	return _rotate;
}

void	Info3d::setRotate(float x, float y, float z)
{
	_rotate.X = x;
	_rotate.Y = y;
	_rotate.Z = z;
}

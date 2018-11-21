//
// EPITECH PROJECT, 2018
// indie_studio
// File description:
// Info3d.hpp
//

#ifndef INFO3D_HPP_
#define INFO3D_HPP_

#include <irrlicht/irrlicht.h>

class Info3d
{
public:
	Info3d(irr::core::vector3df pos, irr::f32 scale);
	~Info3d();
	irr::core::vector3df	getPos();
	void	setPos(irr::core::vector3df pos);
	irr::core::vector3df	getScale();
	void	setScale(irr::core::vector3df scale);
	irr::core::vector3df	getRotate();
	void	setRotate(float x, float y, float z);
private:
	irr::core::vector3df	_pos;
	irr::core::vector3df	_scale;
	irr::core::vector3df	_rotate;
};

#endif

//
// EPITECH PROJECT, 2018
// indie_studio
// File description:
// FireUp.hpp
//

#ifndef FIREUP_HPP_
#define FIREUP_HPP_

#include "GraphObj.hpp"
#include "IPowerUp.hpp"
#include "Info3d.hpp"

class IPowerUp;

class FireUp : public IPowerUp
{
public:
	FireUp(IndieWindow *indie, irr::core::vector2di pos);
	~FireUp();
	objType	getType() override;
private:
	GraphObj	*_graphObj;
	irr::core::vector2di	_pos;
};
#endif

//
// EPITECH PROJECT, 2018
// indie_studio
// File description:
// WallPass.hpp
//

#ifndef WALLPASS_HPP_
#define WALLPASS_HPP_

#include "GraphObj.hpp"
#include "IPowerUp.hpp"
#include "Info3d.hpp"

class WallPass : public IPowerUp
{
public:
	WallPass(IndieWindow* indie, irr::core::vector2di pos);
	~WallPass();
	objType	getType() override;
private:
	GraphObj	*_graphObj;
	irr::core::vector2di	_pos;
};

#endif

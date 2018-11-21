//
// EPITECH PROJECT, 2018
// indie_studio
// File description:
// BombUp.hpp
//

#ifndef BOMBUP_HPP_
#define BOMBUP_HPP_

#include "GraphObj.hpp"
#include "IPowerUp.hpp"
#include "Info3d.hpp"

class BombUp : public IPowerUp
{
public:
	BombUp(IndieWindow *indie, irr::core::vector2di pos);
	~BombUp();
	objType		getType() override;
private:
	GraphObj	*_graphObj;
	irr::core::vector2di	_pos;
};

#endif

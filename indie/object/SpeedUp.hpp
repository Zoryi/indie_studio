//
// EPITECH PROJECT, 2018
// indie_studio
// File description:
// SpeedUp.hpp
//

#ifndef SPEEDUP_HPP_
#define SPEEDUP_HPP_

#include "GraphObj.hpp"
#include "IPowerUp.hpp"
#include "Info3d.hpp"

class SpeedUp : public IPowerUp
{
public:
	SpeedUp(IndieWindow *indie, irr::core::vector2di pos);
	~SpeedUp();
	objType	getType() override;
private:
	GraphObj	*_graphObj;
	irr::core::vector2di	_pos;
};

#endif

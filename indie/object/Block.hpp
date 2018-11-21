//
// EPITECH PROJECT, 2018
// indie_studio
// File description:
// Block.hpp
//

#ifndef BLOCK_HPP_
#define BLOCK_HPP_

#include "GraphObj.hpp"
#include "IObject.hpp"
#include "Info3d.hpp"

class Block : public IObject
{
public:
	Block(IndieWindow *indie, bool breakable, irr::core::vector2di pos);
	~Block();
	objType		getType() override;
private:
	GraphObj	*_graphObj;
	bool	_breakable;
	irr::core::vector2di	_pos;
};

#endif

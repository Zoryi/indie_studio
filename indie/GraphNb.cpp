//
// EPITECH PROJECT, 2018
// indie_studio
// File description:
// GraphNb.cpp
//

#include "GraphNb.hpp"

GraphNb::GraphNb(IndieWindow *win, int nb, Info3d pos)
	: _win(win), _nb(nb), _info(pos)
{
	initNb(nb);
}

GraphNb::~GraphNb()
{
	deleteNb();
}

void	GraphNb::changeNb(int nb)
{
	if (nb != _nb){
		deleteNb();
		initNb(nb);
	}
}

void	GraphNb::deleteNb()
{
	for (auto& a : _graphNb)
		delete a;
	_graphNb.clear();
	_nb = 0;
}

void	GraphNb::initNb(int nb)
{	
	Info3d	info(_info);
	std::string	sNb = std::to_string(nb);
	irr::core::vector3df	myPos(info.getPos());
	std::string	tmp;
	
	_nb = nb;
	_size = sNb.length();
	for (int i = 0 ; i < _size ; i++){
		tmp.push_back(sNb[i]);
		_graphNb.push_back(new GraphObj(_win, tmp,
						info));
		myPos.X += 6;
		info.setPos(myPos);
		tmp.clear();
	}
}

void	GraphNb::setPos(irr::core::vector3df pos)
{
	irr::core::vector3df	tmpPos = pos;
	
	_info.setPos(pos);
	for (auto& a : _graphNb){
		a->setPos(tmpPos);
		tmpPos.X += 6;
	}
}

irr::core::vector3df	GraphNb::getPos()
{
	return _info.getPos();
}

//
// EPITECH PROJECT, 2018
// indie_studio
// File description:
// GraphNb.hpp
//

#ifndef GRAPHNB_HPP_
#define GRAPHNB_HPP_

#include "IndieWindow.hpp"
#include "GraphObj.hpp"

class GraphNb
{
public:
	GraphNb(IndieWindow *win, int nb, Info3d pos);
	~GraphNb();
	void	changeNb(int nb);
	void	setPos(irr::core::vector3df pos);
	irr::core::vector3df	getPos();
private:
	void	initNb(int nb);
	void	deleteNb();
	IndieWindow	*_win;
	int	_nb;
	Info3d	_info;
	int	_size;
	std::vector<GraphObj*>	_graphNb;
};

#endif

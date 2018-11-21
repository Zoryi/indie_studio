//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// UI.hpp
//

#ifndef UI_HPP_
#define UI_HPP_

#include "IndieWindow.hpp"
#include "GraphNb.hpp"
#include "PC.hpp"

class PC;
class GraphNb;

class UI
{
public:
	UI(IndieWindow *win, irr::core::vector3df pos, PC *player);
	~UI();
	void	update();
private:
	void	initTexts(int id);
	IndieWindow	*_win;
	irr::core::vector3df	_pos;
	PC	*_player;
	GraphNb		*_score;
	GraphNb		*_maxBomb;
	GraphNb		*_power;
	std::vector<GraphObj *>	_texts;
};

#endif

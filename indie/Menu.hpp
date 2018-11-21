//
// EPITECH PROJECT, 2018
// Indie
// File description:
// Indie
//

#ifndef MENU_HPP_
#define MENU_HPP_

#include <irrlicht/irrlicht.h>
#include <vector>
#include "IndieWindow.hpp"
#include "GraphObj.hpp"
#include "GraphNb.hpp"

class	IndieWindow;
class	GraphObj;
class	GraphNb;

class Menu
{
public:
	Menu(IndieWindow* window);
	~Menu();
	void	clearMenu();
	void	startMenu();
	void	pauseMenu();
	void	optionMenu();
	void	winMenu();
	void	loseMenu();
        void	setNb(Info3d pos);
        void    resetNb();
	void	setBlock(int nb);
	void	changeBlock(int nb);
	void	changeBlockEnd(int nb);
	void	setGraphObjs();
	int	getSelect();
	void	doSceneMenuEvent();
	void	doScenePauseEvent();
	void	doSceneOptionEvent();
	void	doSceneEndEvent();
	void	checkEventMoveOption();
	void	checkEventSoundOption();
	void	checkEventMuteOption();
	bool	getMenuStart();
	bool	getOption();
	bool	getPause();
	bool	getWin();
	bool	getLose();
private:
	IndieWindow	*_window;
	int		_select;
	std::vector<GraphObj*>	_objs;
	std::vector<std::string>	_nameObjs;
	irr::video::ITexture*	_textselected;
	irr::video::ITexture*	_textother;
	bool			_menustart;
	bool			_option;
	bool			_pause;
	bool			_win;
	bool			_lose;
	GraphNb		*_nbmus;
	GraphNb		*_nbsnd;
	GraphNb		*_nbmute;
};

#endif

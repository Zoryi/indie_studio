//
// EPITECH PROJECT, 2018
// Indie
// File description:
// Indie
//

#include "Menu.hpp"

Menu::Menu(IndieWindow* window)
	: _window(window), _select(0)
{
	_menustart = true;
	_option = false;
	_pause = false;
	_win = false;
	_lose = false;
	_textselected = _window->getDriver()->getTexture("./obj/Menu/SelectedText.jpeg");
	_textother = _window->getDriver()->getTexture("./obj/Menu/Text.jpeg");
	setGraphObjs();
        startMenu();
	_window->getSound()->playMusic("media/Music.ogg");
}

Menu::~Menu()
{
	for (auto& it : _objs)
		delete it;
	_objs.clear();
}

void	Menu::clearMenu()
{
	_select = 0;
	for (auto& it : _objs)
		delete it;
	_objs.clear();
	if (_option){
		delete _nbmus;
		delete _nbsnd;
		delete _nbmute;
	}
}

void	Menu::startMenu()
{
	setBlock(1);
}

void	Menu::pauseMenu()
{
	setBlock(3);
	_pause = true;
}

void	Menu::optionMenu()
{
	setBlock(2);
}

void	Menu::winMenu()
{
	_win = true;
	_select = 1;
	setBlock(4);
	_objs[0]->setTexture(_textselected);
}

void	Menu::loseMenu()
{
	_lose = true;
	_select = 1;
	setBlock(5);
	_objs[0]->setTexture(_textselected);
}

void	Menu::setNb(Info3d pos)
{
	irr::core::vector3df	tmp = pos.getPos();
	Info3d	nbpos(tmp, 10);

	tmp.X += 30;
	nbpos.setPos(tmp);
        nbpos.setRotate(45, 0, 0);
	_nbmus = new GraphNb(_window, _window->getSound()->getVolumeMusic()
			     * 10, nbpos);
	tmp.Y -= 8.0f;
	tmp.Z -= 5.0f;
	nbpos.setPos(tmp);
	_nbsnd = new GraphNb(_window, _window->getSound()->getVolumeSound()
			     * 10, nbpos);
	tmp.Y -= 8.0f;
	tmp.Z -= 5.0f;
	nbpos.setPos(tmp);
	_nbmute = new GraphNb(_window, _window->getSound()->getMute("All"),
			      nbpos);
}
void	Menu::resetNb()
{
	_nbmus->changeNb(_window->getSound()->getVolumeMusic() * 10);
	_nbsnd->changeNb(_window->getSound()->getVolumeSound() * 10);
	_nbmute->changeNb(_window->getSound()->getMute("All"));
}

void	Menu::setBlock(int nb)
{
	irr::core::vector3df	tmp(90.0f, 80.0f, -200.0f);
	Info3d	pos(tmp, 10);
	int	i = 0;
        
	pos.setRotate(45, 0, 0);
	if (nb == 2)
		setNb(pos);
        for (auto& it : _nameObjs) {
		if (i < nb * 4 && i >= (nb - 1) * 4) {
			_objs.push_back(new GraphObj(_window, it, pos));
			if (i % 4 == _select)
				_objs.back()->setTexture(_textselected);
			tmp.Y -= 8.0f;
			tmp.Z -= 5.0f;
			pos.setPos(tmp);
		}
		i++;
        }
}

void	Menu::setGraphObjs()
{
	_nameObjs.push_back(std::string("1Player"));
	_nameObjs.push_back(std::string("2Players"));
	_nameObjs.push_back(std::string("Sound"));
	_nameObjs.push_back(std::string("Exit"));
	_nameObjs.push_back(std::string("Music"));
	_nameObjs.push_back(std::string("Sound"));
	_nameObjs.push_back(std::string("Mute"));
	_nameObjs.push_back(std::string("Back"));
	_nameObjs.push_back(std::string("Continue"));
	_nameObjs.push_back(std::string("Restart"));
	_nameObjs.push_back(std::string("Sound"));
	_nameObjs.push_back(std::string("Menu"));
	_nameObjs.push_back(std::string("Win")); // You Win
	_nameObjs.push_back(std::string("Restart")); // Restart
	_nameObjs.push_back(std::string("Sound")); // Load
	_nameObjs.push_back(std::string("Menu")); // Menu
	_nameObjs.push_back(std::string("Lose"));// You Loose
	_nameObjs.push_back(std::string("Restart")); // Restart
	_nameObjs.push_back(std::string("Sound")); // Load
	_nameObjs.push_back(std::string("Menu")); // Menu
}

void	Menu::changeBlock(int nb)
{
	if ((nb == 0 && _select > 0) || (nb == 1 && _select < 3))
		_window->getSound()->playSound(
			"media/Switch.ogg");
	_objs[_select]->setTexture(_textother);
	if (nb == 0 && _select > 0)
		_select -= 1;	
	else if (nb == 1 && _select < 3)
		_select += 1;
	_objs[_select]->setTexture(_textselected);
}

void	Menu::changeBlockEnd(int nb)
{
	if ((nb == 0 && _select > 0) || (nb == 1 && _select < 3))
		_window->getSound()->playSound(
			"media/Switch.ogg");
	_objs[_select]->setTexture(_textother);
	if (nb == 0 && _select > 1)
		_select -= 1;	
	else if (nb == 1 && _select < 3)
		_select += 1;
	_objs[_select]->setTexture(_textselected);
}

int	Menu::getSelect()
{
	return _select;
}

void	Menu::doSceneMenuEvent()
{
	if (getSelect() < 2) {
		_menustart = false;
		_window->initGame(getSelect() + 1);
		clearMenu();
	}else if (getSelect() == 2) {
	        clearMenu();
		optionMenu();
		_option = true;
	} else if (getSelect() == 3) {
		clearMenu();
		_window->getDevice()->closeDevice();
	}
}

void	Menu::doScenePauseEvent()
{
	int	nbP = _window->getCore()->getMultiplayer();
	
        if (getSelect() == 0) {
		_pause = false;
		clearMenu();
	} else if (getSelect() == 1){
		_pause = false;
		clearMenu();
		_window->stopGame();
		_window->initGame(nbP == 1 ? 0 : 1);
	}else if (getSelect() == 2) {
	        clearMenu();
		optionMenu();
		_option = true;
	} else if (getSelect() == 3) {
		_window->stopGame();
		clearMenu();
		startMenu();
		_pause = false;
		_menustart = true;
	}
}

void	Menu::doSceneEndEvent()
{
	int	nbP = _window->getCore()->getMultiplayer();

	if (getSelect() == 1){
		clearMenu();
		_window->stopGame();
		_window->initGame(nbP == 1 ? 0 : 1);
		_win = false;
		_lose = false;
	}else if (getSelect() == 2) {
	        clearMenu();
		optionMenu();
		_option = true;
	} else if (getSelect() == 3) {
		_window->stopGame();
		clearMenu();
		startMenu();
		_win = false;
		_lose = false;
		_menustart = true;
	}
}

void	Menu::doSceneOptionEvent()
{
	if (getSelect() == 3 && _menustart) {
		clearMenu();
		startMenu();
		_option = false;
	} else if (getSelect() == 3 && _pause) {
		clearMenu();
		pauseMenu();
		_option = false;
	} else if (getSelect() == 3 && _win) {
		clearMenu();
	        winMenu();
		_option = false;
	} else if (getSelect() == 3 && _lose) {
		clearMenu();
	        loseMenu();
		_option = false;
	}
}

void	Menu::checkEventSoundOption()
{
	resetNb();
	if (getSelect() == 0 &&
		_window->getReleased(irr::KEY_LEFT))
		_window->getSound()->setVolumeMusic(0);
	else if (getSelect() == 0 &&
		 _window->getReleased(irr::KEY_RIGHT))
		_window->getSound()->setVolumeMusic(1);
	else if (getSelect() == 1 &&
		 _window->getReleased(irr::KEY_LEFT))
		_window->getSound()->setVolumeSound(0);
	else if (getSelect() == 1 &&
		 _window->getReleased(irr::KEY_RIGHT))
		_window->getSound()->setVolumeSound(1);
	checkEventMuteOption();
}

void	Menu::checkEventMuteOption()
{
	if (getSelect() == 0 &&
	    _window->getReleased(irr::KEY_KEY_M))
		_window->getSound()->muteMusic();
	else if (getSelect() == 1 &&
		 _window->getReleased(irr::KEY_KEY_M))
		_window->getSound()->muteSound();
	else if (getSelect() == 2 &&
		 _window->getReleased(irr::KEY_SPACE))
		_window->getSound()->muteAll();
}

void	Menu::checkEventMoveOption()
{
	if ((!_win && !_lose) || _option) {
		if (_window->getReleased(irr::KEY_DOWN))
			changeBlock(1);
		else if (_window->getReleased(irr::KEY_UP))
			changeBlock(0);
	} else {
		if (_window->getReleased(irr::KEY_DOWN))
			changeBlockEnd(1);
		else if (_window->getReleased(irr::KEY_UP))
			changeBlockEnd(0);	
	}
}

bool	Menu::getMenuStart()
{
	return _menustart;
}

bool	Menu::getOption()
{
	return _option;
}

bool	Menu::getPause()
{
	return _pause;
}

bool	Menu::getWin()
{
	return _win;
}

bool	Menu::getLose()
{
	return _lose;
}

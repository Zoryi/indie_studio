//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// IndieWindow
//

#ifndef INDIEWINDOW_HPP_
# define INDIEWINDOW_HPP_

#include <map>
#include <irrlicht/irrlicht.h>
#include "IndieRendering.hpp"
#include "IndieEventReceiver.hpp"
#include "Core.hpp"
#include "Menu.hpp"
#include "Sound.hpp"

class Menu;
class Core;

class IndieWindow
{
public:
	IndieWindow();
	~IndieWindow();
	void	initGame(size_t nbPlayer);
	void	stopGame();
	void	loop();
	void 	doBackground();
        void	doScene();
	int	doSceneMenu();
	void	doSceneGame();
	irr::scene::ISceneManager	*getSceneManager();
	irr::video::IVideoDriver	*getDriver();
	irr::IrrlichtDevice		*getDevice();
	std::pair<irr::scene::IAnimatedMesh*,
		  irr::video::ITexture*>	getFile(std::string name);
        irr::scene::IAnimatedMesh*		getMenuFile(std::string name);
	bool					getReleased(irr::EKEY_CODE keyCode);
	Sound	*getSound();
	Core	*getCore();
	Menu	*getMenu();
private:
	void	initFiles();
	void	initUIFiles(irr::scene::ISceneManager *sMana,
			irr::video::IVideoDriver *driv);
	void	initMenuFiles(irr::scene::ISceneManager *sMana,
			irr::video::IVideoDriver *driv);
	irr::IrrlichtDevice *_device;
	irr::video::ITexture	*_img;
	IndieEventReceiver _receiver;
	std::map<std::string, std::pair<irr::scene::IAnimatedMesh*,
		irr::video::ITexture*>>	_files;
	std::map<std::string, irr::scene::IAnimatedMesh*> _menufiles;
	Menu	*_menu;
	Sound	_sound;
	Core	*_core;
};

#endif

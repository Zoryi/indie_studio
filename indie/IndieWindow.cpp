//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// IndieWindow

#include "IndieWindow.hpp"

IndieWindow::IndieWindow()
{
	_device = irr::createDevice(irr::video::EDT_OPENGL,
				irr::core::dimension2d<irr::u32>(1920, 1080),
				32, false, true, true, &_receiver);
	getSceneManager()->addCameraSceneNode(0,
			        irr::core::vector3df(100, 100, -220),
				irr::core::vector3df(100, 0, -150));
	initFiles();
	_menu = new Menu(this);
}

IndieWindow::~IndieWindow()
{
	_device->drop();
}

void	IndieWindow::initGame(size_t nbPlayer)
{
	_core = new Core(nbPlayer == 1 ? false : true, this, _receiver);
}

void	IndieWindow::stopGame()
{
	delete _core;
	_core = NULL;
}
void	IndieWindow::loop()
{	
	while (_device->run()) {
		if (_device->isWindowActive())
			doScene();
		else
			_device->yield();
	}
}

void	IndieWindow::doBackground()
{
	_img = getDriver()->getTexture("obj/Img/back.jpg");
	getDriver()->draw2DImage(_img,
		irr::core::position2d<irr::s32>(0,0),
		irr::core::rect<irr::s32>(0,0,1920,1080),
		0,
		irr::video::SColor (255,255,255,255),
		true);
}

void	IndieWindow::doScene()
{
	IndieRendering	scene(getDriver());

	doBackground();
	if (_menu->getMenuStart() || _menu->getPause() ||
	    _menu->getWin() || _menu->getLose())
		doSceneMenu();
	else
		doSceneGame();
	getSceneManager()->drawAll();
}

int	IndieWindow::doSceneMenu()
{
        _menu->checkEventMoveOption();
	if (_menu->getOption())
		_menu->checkEventSoundOption();
	if (_receiver.IsKeyReleased(irr::KEY_SPACE)) {
		if (_menu->getMenuStart() && !_menu->getOption())
			_menu->doSceneMenuEvent();
		else if (_menu->getPause() && !_menu->getOption())
			_menu->doScenePauseEvent();
		else if (_menu->getOption())
			_menu->doSceneOptionEvent();
		else if (_menu->getWin() || _menu->getLose())
			_menu->doSceneEndEvent();
		return 1;
	}
	return -1;
}

void	IndieWindow::doSceneGame()
{
	_core->exec();
	if (_receiver.IsKeyReleased(irr::KEY_ESCAPE)){
		_menu->pauseMenu();
	}
}

irr::IrrlichtDevice	*IndieWindow::getDevice()
{
	return _device;
}

irr::scene::ISceneManager	*IndieWindow::getSceneManager()
{
	return _device->getSceneManager();
}

irr::video::IVideoDriver	*IndieWindow::getDriver()
{
	return _device->getVideoDriver();
}

std::pair<irr::scene::IAnimatedMesh*,
		irr::video::ITexture*>	IndieWindow::getFile(std::string name)
{
	return _files[name];
}

irr::scene::IAnimatedMesh*	IndieWindow::getMenuFile(std::string name)
{
	return _menufiles[name];
}

void	IndieWindow::initFiles()
{
	irr::scene::ISceneManager	*sMana = getSceneManager();
	irr::video::IVideoDriver	*driv = getDriver();
	
	initMenuFiles(sMana, driv);
	initUIFiles(sMana, driv);
	_files["Player"].first = sMana->getMesh("./obj/Player/faerie.md2");
	_files["Player"].second = driv->getTexture("./obj/Player/faerie2.bmp");
	_files["Bomb"].first = sMana->getMesh("./obj/Bomb/Bomb.obj");
	_files["Bomb"].second = driv->getTexture("./obj/Bomb/texture.png");
	_files["Block1"].first = sMana->getMesh("./obj/Block/Cube.obj");
	_files["Block1"].second = driv->getTexture("./obj/Block/Block1.png");
	_files["Block2"].first = _files["Block1"].first;
	_files["Block2"].second = driv->getTexture("./obj/Block/Block2.jpg");
	_files["Floor"].first = _files["Block1"].first;
	_files["Floor"].second = driv->getTexture("./obj/Block/Floor.jpg");
	_files["WallPass"].first = sMana->getMesh("./obj/PU/WallPass.obj");
	_files["WallPass"].second = driv->getTexture("./obj/PU/WallPass.png");
	_files["WallPass"].first = sMana->getMesh("./obj/PU/WallPass.obj");
	_files["BombUp"].first = sMana->getMesh("./obj/PU/BombUp/BombUp.obj");
	_files["FireUp"].first = sMana->getMesh("./obj/PU/FireUp/FireUp.obj");
	_files["SpeedUp"].first =
		sMana->getMesh("./obj/PU/SpeedUp/SpeedUp.obj");
}

void	IndieWindow::initUIFiles(irr::scene::ISceneManager *sMana,
			irr::video::IVideoDriver *driv)
{
	_files["0"].first = sMana->getMesh("./obj/UI/0.obj");
	_files["0"].second = driv->getTexture("./obj/Menu/SelectedText.jpeg");
	_files["1"].first = sMana->getMesh("./obj/UI/1.obj");
	_files["1"].second = _files["0"].second;
	_files["2"].first = sMana->getMesh("./obj/UI/2.obj");
	_files["2"].second = _files["0"].second;
	_files["3"].first = sMana->getMesh("./obj/UI/3.obj");
	_files["3"].second = _files["0"].second;
	_files["4"].first = sMana->getMesh("./obj/UI/4.obj");
	_files["4"].second = _files["0"].second;
	_files["5"].first = sMana->getMesh("./obj/UI/5.obj");
	_files["5"].second = _files["0"].second;
	_files["6"].first = sMana->getMesh("./obj/UI/6.obj");
	_files["6"].second = _files["0"].second;
	_files["7"].first = sMana->getMesh("./obj/UI/7.obj");
	_files["7"].second = _files["0"].second;
	_files["8"].first = sMana->getMesh("./obj/UI/8.obj");
	_files["8"].second = _files["0"].second;
	_files["9"].first = sMana->getMesh("./obj/UI/9.obj");
	_files["9"].second = _files["0"].second;
	_files["Score"].first = sMana->getMesh("./obj/UI/Score.obj");
	_files["Score"].second = _files["0"].second;
	_files["MaxBomb"].first = sMana->getMesh("./obj/UI/MaxBomb.obj");
	_files["MaxBomb"].second = _files["0"].second;
	_files["Power"].first = sMana->getMesh("./obj/UI/Power.obj");
	_files["Power"].second = _files["0"].second;
}

void	IndieWindow::initMenuFiles(irr::scene::ISceneManager *sMana,
		        irr::video::IVideoDriver *driv)
{
	_files["1Player"].first = sMana->getMesh("./obj/Menu/1Player.obj");
	_files["1Player"].second = driv->getTexture("./obj/Menu/Text.jpeg");
	_files["2Players"].first = sMana->getMesh("./obj/Menu/2Player.obj");
	_files["2Players"].second = _files["1Player"].second;
	_files["Sound"].first = sMana->getMesh("./obj/Menu/Sound.obj");
	_files["Sound"].second = _files["1Player"].second;
	_files["Exit"].first = sMana->getMesh("./obj/Menu/Exit.obj");
	_files["Exit"].second = _files["1Player"].second;
	_files["Continue"].first = sMana->getMesh("./obj/Menu/Continue.obj");
	_files["Continue"].second = _files["1Player"].second;
	_files["Restart"].first = sMana->getMesh("./obj/Menu/Restart.obj");
	_files["Restart"].second = _files["1Player"].second;
	_files["Menu"].first = sMana->getMesh("./obj/Menu/Menu.obj");
	_files["Menu"].second = _files["1Player"].second;
	_files["Music"].first = sMana->getMesh("./obj/Menu/Music.obj");
	_files["Music"].second = _files["1Player"].second;
	_files["Sound"].first = sMana->getMesh("./obj/Menu/Sound.obj");
	_files["Sound"].second = _files["1Player"].second;
	_files["Mute"].first = sMana->getMesh("./obj/Menu/Mute.obj");
	_files["Mute"].second = _files["1Player"].second;
	_files["Back"].first = sMana->getMesh("./obj/Menu/Back.obj");
	_files["Back"].second = _files["1Player"].second;
	_files["Win"].first = sMana->getMesh("./obj/Menu/Win.obj");
	_files["Win"].second = _files["1Player"].second;
	_files["Lose"].first = sMana->getMesh("./obj/Menu/Lose.obj");
	_files["Lose"].second = _files["1Player"].second;
}

bool	IndieWindow::getReleased(irr::EKEY_CODE keyCode)
{
	return _receiver.IsKeyReleased(keyCode);
}

Sound*	IndieWindow::getSound()
{
	return &_sound;
}

Core	*IndieWindow::getCore()
{
	return _core;
}

Menu	*IndieWindow::getMenu()
{
	return _menu;
}

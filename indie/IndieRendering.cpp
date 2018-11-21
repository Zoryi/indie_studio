//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// IndieRendering
//

#include "IndieRendering.hpp"

IndieRendering::IndieRendering(irr::video::IVideoDriver *driver)
	: _driver(driver)
{
	_driver->beginScene(true, true,
		irr::video::SColor(255, 55, 100, 155));

}

IndieRendering::~IndieRendering()
{
	_driver->endScene();
}

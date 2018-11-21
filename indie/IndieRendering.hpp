//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// IndieRendering
//

#ifndef INDIERENDERING_HPP_
# define INDIERENDERING_HPP_

#include <irrlicht/irrlicht.h>

class IndieRendering
{
public:
	IndieRendering(irr::video::IVideoDriver *driver);
	~IndieRendering();
private:
	irr::video::IVideoDriver *_driver;
};

#endif

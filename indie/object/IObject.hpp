//
// EPITECH PROJECT, 2018
// Indie
// File description:
// Indie
//

#ifndef IOBJECT_HPP_
# define IOBJECT_HPP_

# include <functional>
# include <algorithm>
# include <exception>
# include <stdexcept>
# include <iterator>
# include <cerrno>
# include <string>
# include <cstring>
# include <vector>
# include <irrlicht/irrlicht.h>
# include <map>

#define B_SIZE 15

class GraphObj;
class IndieWindow;

enum direction {
	UP = 1,
	DOWN = -1,
	LEFT = 2,
	RIGHT = 0,
	NONE = -2
};

enum objType {
	BOMB_UP,
	SPEED_UP,
	FIRE_UP,
	WALL_PASS,
	BOMB,
	BLOCK,
	WALL
};

class IObject
{
public:
	virtual	        ~IObject() = default;
	virtual objType		getType() = 0;
};

#endif

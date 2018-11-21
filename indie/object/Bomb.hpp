//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Bomb
//

#ifndef BOMB_HPP_
# define BOMB_HPP_

#include <irrlicht/irrlicht.h>
#include <chrono>
#include "GraphObj.hpp"
#include "Map.hpp"
#include "BasicPlayer.hpp"
#include "IndieWindow.hpp"
#include "IObject.hpp"
#include "Info3d.hpp"
#include "AnimFireExplo.hpp"

typedef std::chrono::steady_clock stdclock;
typedef std::chrono::milliseconds ms;
class Map;
class BasicPlayer;
class AnimFireExplo;

class Bomb : public IObject
{
public:
	Bomb(IndieWindow *indie, size_t power, irr::core::vector2di pos);
	~Bomb();
	objType	getType() override;
	unsigned long long getTimer();
	bool isWall(Map *map, std::vector<BasicPlayer *> &players,
		const size_t &x, const size_t &y);
	void breakItem(Map *map, std::vector<BasicPlayer *> &players,
		const size_t &x, const size_t &y);
	void explode(Map *map, std::vector<BasicPlayer *> &players);
	bool	getExplode();
private:
	GraphObj	*_graphObj;
	stdclock::time_point _t;
	size_t	_power;
	bool	_explode;
	IndieWindow*	_window;
	irr::core::vector2di	_pos;
	std::vector<AnimFireExplo *> _anims;
};

#endif

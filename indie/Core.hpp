//
// EPITECH PROJECT, 2018
// Indie
// File description:
// Indie
//

#ifndef CORE_HPP_
# define CORE_HPP_
# include "BasicPlayer.hpp"
# include "IndieEventReceiver.hpp"
# include "NPC.hpp"
# include "PC.hpp"
# include "Map.hpp"

class Core
{
public:
	Core(const bool &multiplayer, IndieWindow *window,
	IndieEventReceiver &receiver);
	~Core();
	bool exec();
	bool getMultiplayer();
private:
	bool isOver();
	void initFloor();
	void addPowerup(BasicPlayer *player, int x, int y);
	bool playerNoClipped(int x, int y);
	int offset(float pos, float add);
	bool playerOffset(BasicPlayer *player, float ax, float ay);
	void movePlayer(BasicPlayer *player, direction dir);
	void placeBomb(BasicPlayer *player);
	void updatePlayer(BasicPlayer *player);
	std::vector<BasicPlayer *> _players;
	GraphObj*	_floor;
	IndieWindow *_window;
	IndieEventReceiver &_receiver;
	bool _multiplayer;
	size_t _width;
	size_t _height;
	Map *_map;
};

#endif

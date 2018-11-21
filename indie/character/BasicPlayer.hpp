//
// EPITECH PROJECT, 2018
// Indie
// File description:
// Indie
//

#ifndef PLAYER_HPP_
# define PLAYER_HPP_

# include "Info3d.hpp"
# include "IPowerUp.hpp"
#include <chrono>

typedef std::chrono::steady_clock stdclock;
typedef std::chrono::milliseconds ms;
class Map;

class BasicPlayer
{
public:
	BasicPlayer(const int &id,
		irr::core::vector2df pos,
		const bool &player);
	virtual ~BasicPlayer();
	virtual void	setDir(direction dir);
	void	updateCooldown();
	unsigned long long	getCooldown();
	void	setBomb();
	void	placeBomb();
	direction	getDir(bool reset);
	bool	canPlaceBomb();
	virtual void	deletePlayer();
	bool	isActive();
	irr::core::vector2df getPos();
	virtual void	setPos(irr::core::vector2df pos);
	float	getSpeed();
	void	setSpeed(float value);
	size_t	getMaxBomb();
	void	setMaxBomb(size_t value);
	size_t	getPower();
	void	setPower(size_t value);
	bool	getNoClip();
	void	setNoClip(bool value);
	bool	isPlayer();
	virtual void	run() = 0;
	virtual void	stand() = 0;
protected:
	direction	_dir;
	bool	_active;
	irr::core::vector2df _pos;
	size_t	_bombs;
	float	_speed;
	size_t	_maxBomb;
	size_t	_power;
	bool	_noClip;
	int	_playerID;
	bool	_player;
	bool	_placingBomb;
	stdclock::time_point _t;
};

#endif

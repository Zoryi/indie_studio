//
// EPITECH PROJECT, 2018
// Indie
// File description:
// Indie
//

#include "BasicPlayer.hpp"

BasicPlayer::BasicPlayer(const int &id,
			irr::core::vector2df pos,
			const bool &player)
	: _dir(NONE), _active(true), _pos(pos), _bombs(1), _speed(0.05),
	_maxBomb(1), _power(2), _noClip(false),
	_playerID(id), _player(player), _placingBomb(false)
{
	_t = stdclock::now();
}

BasicPlayer::~BasicPlayer()
{
}

void	BasicPlayer::setPos(irr::core::vector2df pos)
{
	_pos.X = pos.X;
	_pos.Y = pos.Y;
}

void BasicPlayer::setDir(direction dir)
{
	_dir = dir;
}

direction BasicPlayer::getDir(bool reset)
{
	direction dir = _dir;
	if (reset == true)
		_dir = NONE;
	return (dir);
}

void BasicPlayer::updateCooldown()
{
	if (_bombs < _maxBomb && getCooldown() >= 3500) {
		_bombs += 1;
		_t = stdclock::now();
	}
}

unsigned long long BasicPlayer::getCooldown()
{
	unsigned long long dif;
	dif = std::chrono::duration_cast<ms>(stdclock::now() - _t).count();
	return (dif);
}

void BasicPlayer::setBomb()
{
	if (_bombs == _maxBomb)
		_t = stdclock::now();
	_bombs -= 1;
}

void BasicPlayer::placeBomb()
{
	if (_bombs > 0)
		_placingBomb = true;
}

bool BasicPlayer::canPlaceBomb()
{
	bool ret = false;
	if (_placingBomb == true) {
		_placingBomb = false;
		ret = true;
	}
	return (ret);
}

void BasicPlayer::deletePlayer()
{
	_active = false;
	_pos.X = -1;
	_pos.Y = -1;
}

bool BasicPlayer::isActive()
{
	return (_active);
}

irr::core::vector2df BasicPlayer::getPos()
{
	return _pos;
}

float	BasicPlayer::getSpeed()
{
	return _speed;
}

void	BasicPlayer::setSpeed(float value)
{
	_speed = value;
}

size_t	BasicPlayer::getMaxBomb()
{
	return _maxBomb;
}

void	BasicPlayer::setMaxBomb(size_t value)
{
	if (value == (_maxBomb + 1))
		_bombs += 1;
	_maxBomb = value;
}

size_t	BasicPlayer::getPower()
{
	return _power;
}

void	BasicPlayer::setPower(size_t value)
{
	_power = value;
}

bool	BasicPlayer::getNoClip()
{
	return _noClip;
}

void	BasicPlayer::setNoClip(bool value)
{
	_noClip = value;
}

bool	BasicPlayer::isPlayer()
{
	return _player;
}

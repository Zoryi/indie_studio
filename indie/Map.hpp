//
// EPITECH PROJECT, 2018
// Indie
// File description:
// Indie
//

#ifndef MAP_HPP_
# define MAP_HPP_

# include "Bomb.hpp"
# include "Block.hpp"
# include "BombUp.hpp"
# include "FireUp.hpp"
# include "SpeedUp.hpp"
# include "WallPass.hpp"
# include "IObject.hpp"
# include "BasicPlayer.hpp"

class Map
{
public:
	Map(IndieWindow *win, const size_t &, const size_t &);
	~Map();
	IObject *getObject(const size_t &, const size_t &);
	void removeObject(const size_t &, const size_t &);
	bool addObject(const size_t &, const size_t &,
		       IObject *);
	void updateBombs(std::vector<BasicPlayer *> &players);
private:
	void	initEmptyMap();
	void	initMap();
	bool	updateBomb(std::vector<BasicPlayer *> &players, IObject *obj);
	size_t _width;
	size_t _height;
	IndieWindow	*_window;
	std::vector<std::vector<IObject *>> _map;
	IObject	*randPU(irr::core::vector2di pos);
	IObject *Random(irr::core::vector2di pos);
	int getRand(int min, int max);
	std::string mapg;
};

#endif

//
// EPITECH PROJECT, 2018
// Indie
// File description:
// Indie
//

#ifndef NPC_HPP_
# define NPC_HPP_

# include <cstdlib>
# include "BasicPlayer.hpp"
# include "IndieWindow.hpp"

class NPC : public BasicPlayer
{
public:
	NPC(IndieWindow* indie, const int &id, irr::core::vector2df pos);
	~NPC();
	void deletePlayer() override;
	void updatePlayer(Map *map, std::vector<BasicPlayer *> &players);
	void	setPos(irr::core::vector2df pos) override;
	void    setDir(direction dir) override;
	void	run() override;
	void	stand() override;
private:
	int getRand(int min, int max);
	void getRandomDir(Map *map);
	int getObjectType(Map *map, int x, int y);
	direction reverseDir(direction dir);
	direction isThreatened(Map *map);
	direction escapeSelfBomb(Map *map);
	direction isFree(Map *map, direction dir, int add);
	direction escapeBomb(Map *map, direction dir, int add);
	direction escapeSingleBomb(Map *map, direction dir);
	direction escapeDoubleBomb(Map *map, direction dir);
	int getSecondBombDir(Map *map, direction dir);
	direction getIndicator(Map *map, int nb);
	direction getEvenIndicator(Map *map, int nb);
	int getBombNb(Map *map);
	int getBombDistance(Map *map, direction dir);
	int getBlockDistance(Map *map, direction dir);
	int getWallDistance(Map *map, direction dir);
	bool nearEnemy(Map *map, std::vector<BasicPlayer *> &players);
	bool enemyInRange(Map *map, BasicPlayer *player);
	bool nearBlock(Map *map);
	direction pathToEnemy(Map *map, std::vector<BasicPlayer *> &players);
	direction findPathInit(Map *map, BasicPlayer *player);
	bool findPath(Map *map, BasicPlayer *player,
		irr::core::vector2di pos);
	bool wasChecked(irr::core::vector2di pos);
	std::vector<irr::core::vector2di> _path;
	direction	_bombDir;
	direction	_randDir;
	int	_bombIt;
	GraphObj	*_graphObj;
	bool		_runing;
};

#endif

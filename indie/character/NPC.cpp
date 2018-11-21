//
// EPITECH PROJECT, 2018
// Indie
// File description:
// Indie
//

#include "NPC.hpp"

NPC::NPC(IndieWindow* indie, const int &id, irr::core::vector2df pos)
	: BasicPlayer(id, pos, false), _randDir(NONE), _runing(false)
{
	Info3d	info(irr::core::vector3df((pos.X - 0.5) * B_SIZE, 0,
				-(pos.Y - 0.5) * B_SIZE), (float)B_SIZE / 40);
	
	_graphObj = new GraphObj(indie, "Player", info);
	_bombIt = 0;
}

NPC::~NPC()
{
	if (_graphObj)
		delete _graphObj;
}

void NPC::deletePlayer()
{
	_active = false;
	_pos.X = -1;
	_pos.Y = -1;
	if (_graphObj){
		delete _graphObj;
		_graphObj = NULL;
	}
}

void	NPC::setPos(irr::core::vector2df pos)
{
	_pos.X = pos.X;
	_pos.Y = pos.Y;
	_graphObj->setPos(irr::core::vector3df((pos.X - 0.5) * B_SIZE, 0,
					-(pos.Y - 0.5) * B_SIZE));
}

void    NPC::setDir(direction dir)
{
        irr::core::vector3df    rot(_graphObj->getRotate());

        _dir = dir;
        if (dir != NONE)
                rot.Y = -dir * 90;
        _graphObj->setRotate(rot);
}

int NPC::getObjectType(Map *map, int x, int y)
{
	IObject *obj = map->getObject(x, y);
	if (obj == NULL)
		return (-1);
	return (obj->getType());
}

direction NPC::reverseDir(direction dir)
{
	direction newDir = NONE;
	newDir = (dir == LEFT ? RIGHT : (dir == RIGHT ? LEFT : NONE));
	newDir = (dir == UP ? DOWN : (dir == DOWN ? UP : newDir));
	return (newDir);
}

direction NPC::escapeSelfBomb(Map *map)
{
	int x = (int)(_pos.X);
	int y = (int)(_pos.Y);
	if (getObjectType(map, x, y - 1) <= WALL_PASS)
		return (UP);
	else if (getObjectType(map, x, y + 1) <= WALL_PASS)
		return (DOWN);
	else if (getObjectType(map, x - 1, y) <= WALL_PASS)
		return (LEFT);
	else
		return (RIGHT);
}

int NPC::getBombDistance(Map *map, direction dir)
{
	int x = (int)(_pos.X);
	int y = (int)(_pos.Y);
	for (int nx = x - 1;
	dir == LEFT && getObjectType(map, nx, y) < BLOCK; nx--)
		if (getObjectType(map, nx, y) == BOMB)
			return (x - nx);
	for (int nx = x + 1;
	dir == RIGHT && getObjectType(map, nx, y) < BLOCK; nx++)
		if (getObjectType(map, nx, y) == BOMB)
			return (nx - x);
	for (int ny = y - 1;
	dir == DOWN && getObjectType(map, x, ny) < BLOCK; ny--)
		if (getObjectType(map, x, ny) == BOMB)
			return (y - ny);
	for (int ny = y + 1;
	dir && UP && getObjectType(map, x, ny) < BLOCK; ny++)
		if (getObjectType(map, x, ny) == BOMB)
			return (ny - y);
	return (-1);
}

int NPC::getBlockDistance(Map *map, direction dir)
{
	int x = (int)(_pos.X);
	int y = (int)(_pos.Y);
	for (int nx = x - 1;
	dir == LEFT && getObjectType(map, nx, y) <= BLOCK; nx--)
		if (getObjectType(map, nx, y) == BLOCK)
			return (x - nx);
	for (int nx = x + 1;
	dir == RIGHT && getObjectType(map, nx, y) <= BLOCK; nx++)
		if (getObjectType(map, nx, y) == BLOCK)
			return (nx - x);
	for (int ny = y - 1;
	dir == DOWN && getObjectType(map, x, ny) <= BLOCK; ny--)
		if (getObjectType(map, x, ny) == BLOCK)
			return (y - ny);
	for (int ny = y + 1;
	dir && UP && getObjectType(map, x, ny) <= BLOCK; ny++)
		if (getObjectType(map, x, ny) == BLOCK)
			return (ny - y);
	return (-1);
}

int NPC::getWallDistance(Map *map, direction dir)
{
	int x = (int)(_pos.X);
	int y = (int)(_pos.Y);
	for (int nx = x - 1;
	dir == LEFT && getObjectType(map, nx, y) <= WALL; nx--)
		if (getObjectType(map, nx, y) >= BLOCK)
			return (x - nx);
	for (int nx = x + 1;
	dir == RIGHT && getObjectType(map, nx, y) <= WALL; nx++)
		if (getObjectType(map, nx, y) >= BLOCK)
			return (nx - x);
	for (int ny = y - 1;
	dir == DOWN && getObjectType(map, x, ny) <= WALL; ny--)
		if (getObjectType(map, x, ny) >= BLOCK)
			return (y - ny);
	for (int ny = y + 1;
	dir && UP && getObjectType(map, x, ny) <= WALL; ny++)
		if (getObjectType(map, x, ny) >= BLOCK)
			return (ny - y);
	return (-1);
}

int NPC::getBombNb(Map *map)
{
	int ret = 0;
	int lB = getBombDistance(map, LEFT);
	int rB = getBombDistance(map, RIGHT);
	int dB = getBombDistance(map, DOWN);
	int uB = getBombDistance(map, UP);
	if (lB > 0)
		ret++;
	if (rB > 0)
		ret++;
	if (dB > 0)
		ret++;
	if (uB > 0)
		ret++;
	return (ret);
}

direction NPC::getEvenIndicator(Map *map, int nb)
{
	int lB = getBombDistance(map, LEFT);
	int rB = getBombDistance(map, RIGHT);
	int dB = getBombDistance(map, DOWN);
	int uB = getBombDistance(map, UP);
	direction ret = NONE;
	if (nb == 2) {
		ret = (lB > 0 && rB > 0) ? (lB <= rB ? LEFT : RIGHT) : ret;
		ret = (uB > 0 && dB > 0) ? (uB <= dB ? UP : DOWN) : ret;
		ret = (lB > 0 && uB > 0) ? (lB <= uB ? LEFT : RIGHT) : ret;
		ret = (rB > 0 && dB > 0) ? (rB <= dB ? LEFT : RIGHT) : ret;
		ret = (lB > 0 && dB > 0) ? (lB <= dB ? LEFT : RIGHT) : ret;
		ret = (rB > 0 && uB > 0) ? (rB <= uB ? LEFT : RIGHT) : ret;
	} else {
		ret = (lB >= rB && lB >= dB && lB >= uB) ? LEFT : ret;
		ret = (rB >= lB && rB >= dB && lB >= uB) ? RIGHT : ret;
		ret = (dB >= lB && dB >= rB && dB >= uB) ? DOWN : ret;
		ret = (uB >= lB && uB >= rB && uB >= dB) ? UP : ret;
	}
	return (ret);
}

direction NPC::getIndicator(Map *map, int nb)
{
	int lB = getBombDistance(map, LEFT);
	int rB = getBombDistance(map, RIGHT);
	int dB = getBombDistance(map, DOWN);
	if (nb == 1 || nb == 3)
		return (lB != -1 ? LEFT :
			(rB != -1 ? RIGHT : (dB != -1 ? DOWN : UP)));
	else
		return (getEvenIndicator(map, nb));
}

direction NPC::isFree(Map *map, direction dir, int add)
{
	int x = (int)(_pos.X);
	int y = (int)(_pos.Y);
	int newx = (dir == LEFT ? x - add : (dir == RIGHT ? x + add : x));
	int newy = (dir == UP ? y - add : (dir == DOWN ? y + add : y));
	if (getObjectType(map, newx, newy) < BOMB)
		return (dir);
	return (reverseDir(dir));
}

direction NPC::escapeBomb(Map *map, direction dir, int add)
{
	int x = (int)(_pos.X);
	int y = (int)(_pos.Y);
	if (dir == LEFT || dir == RIGHT) {
		if (getObjectType(map, x, y + add) < BOMB)
			return (DOWN);
		else if (getObjectType(map, x, y - add) < BOMB)
			return (UP);
		else if (dir == LEFT)
			return (isFree(map, RIGHT, add));
		return (isFree(map, LEFT, add));
	} else if (dir == UP || dir == DOWN) {
		if (getObjectType(map, x + add, y) < BOMB)
			return (RIGHT);
		else if (getObjectType(map, x - add, y) < BOMB)
			return (LEFT);
		else if (dir == UP)
			return (isFree(map, DOWN, add));
		return (isFree(map, UP, add));
	}
	return (NONE);
}

direction NPC::escapeSingleBomb(Map *map, direction dir)
{
	return (escapeBomb(map, dir, 1));
}

int NPC::getSecondBombDir(Map *map, direction dir)
{
	int rB = getBombDistance(map, RIGHT);
	int dB = getBombDistance(map, DOWN);
	if (dir == LEFT) {
		return ((dB > 0 ? -1 : 1));
	} else if (dir == RIGHT) {
		return ((dB > 0 ? -1 : 1));
	} else if (dir == DOWN) {
		return ((rB > 0 ? -1 : 1));
	} else if (dir == UP) {
		return ((rB > 0 ? -1 : 1));
	} else
		return (1);
	
}

direction NPC::escapeDoubleBomb(Map *map, direction dir)
{
	int sB = getSecondBombDir(map, dir);
	return (escapeBomb(map, dir, sB));
}


direction NPC::isThreatened(Map *map)
{
	int x = (int)(_pos.X);
	int y = (int)(_pos.Y);
	if (getObjectType(map, x, y) == BOMB)
		return (escapeSelfBomb(map));
	int lB = getBombDistance(map, LEFT);
	int rB = getBombDistance(map, RIGHT);
	int dB = getBombDistance(map, DOWN);
	int uB = getBombDistance(map, UP);
	if (lB == rB && dB == uB && lB == uB)
		return (NONE);
	int nb = getBombNb(map);
	direction dir = getIndicator(map, nb);
	if (nb == 1)
		return (escapeSingleBomb(map, dir));
	else if (nb == 2)
		return (escapeDoubleBomb(map, dir));
	else if (nb == 3 || nb == 4)
		return (dir);
	return (NONE);
}

int NPC::getRand(int min, int max)
{
        time_t seed;
	static time_t oldseed = 0;
        seed = time(NULL) + oldseed;
        oldseed = seed;
        srand(seed);
        int n = max - min + 1;
        int i = rand() % n;
        if (i < 0)
		i = -i;
        return min + i;
}

bool NPC::nearBlock(Map *map)
{
	int lB = getBlockDistance(map, LEFT);
	int rB = getBlockDistance(map, RIGHT);
	int dB = getBlockDistance(map, DOWN);
	int uB = getBlockDistance(map, UP);
	bool ret = false;
	if (lB >= 0 && (int)(lB - (int)_power) < 1)
		ret = true;
	else if (rB >= 0 && (int)(rB - (int)_power) < 1)
		ret = true;
	else if (dB >= 0 && (int)(dB - (int)_power) < 1)
		ret = true;
	else if (uB >= 0 && (int)(uB - (int)_power) < 1)
		ret = true;
	return (ret);
}

bool NPC::enemyInRange(Map *map, BasicPlayer *player)
{
	int x = (int)(player->getPos().X);
	int y = (int)(player->getPos().Y);
	if (x == (int)(_pos.X) && y == (int)(_pos.Y)) {
		return (true);
	} else if (x == (int)(_pos.X)) {
		direction dir = (y < (int)(_pos.Y) ? UP : DOWN);
		int bDist = getWallDistance(map, dir);
		int pDist = (int)(_pos.Y) - y;
		pDist = (pDist < 0 ? -pDist : pDist);
		if (pDist <= bDist && (pDist - (int)(_power) <= 0))
			return (true);
	} else if (y == (int)(_pos.Y)) {
		direction dir = (x < (int)(_pos.X) ? LEFT : RIGHT);
		int bDist = getWallDistance(map, dir);
		int pDist = (int)(_pos.X) - x;
		pDist = (pDist < 0 ? -pDist : pDist);
		if (pDist <= bDist && (pDist - (int)(_power) <= 0))
			return (true);
	}
	return (false);
}

bool NPC::nearEnemy(Map *map, std::vector<BasicPlayer *> &players)
{
	bool ret = false;
	for (auto it = players.begin(); it != players.end(); it++) {
		auto pos = (*it)->getPos();
		if (pos.X != _pos.X || pos.Y != _pos.Y)
			ret = enemyInRange(map, (*it));
		if (ret == true)
			break;
	}
	return (ret);
}	

void NPC::getRandomDir(Map *map)
{
	if (_randDir == NONE) {
		int r = getRand(0, 3);
		_randDir = (r == 0 ? LEFT : (r == 1 ? RIGHT :
				(r == 2 ? UP : DOWN)));
	} else {
		int x = (int)(_pos.X);
		int y = (int)(_pos.Y);
		int newx = (_randDir == LEFT ? x - 1 :
			(_randDir == RIGHT ? x + 1 : x));
		int newy = (_randDir == UP ? y - 1 :
			(_randDir == DOWN ? y + 1 : y));
		if (getObjectType(map, newx, newy) >= BLOCK)
			_randDir = NONE;
	}
	setDir(_randDir);
}

bool NPC::wasChecked(irr::core::vector2di pos)
{
	for (auto it = _path.begin(); it != _path.end(); it++) {
		if ((*it).X == pos.X && (*it).Y == pos.Y)
			return (true);
	}
	return (false);
}

bool NPC::findPath(Map *map, BasicPlayer *player,
		irr::core::vector2di pos)
{
	if (wasChecked(pos) == true)
		return (false);
	_path.push_back(pos);
	if (getObjectType(map, pos.X, pos.Y) >= BLOCK)
		return (false);
	if (player->getPos().X == pos.X && player->getPos().Y == pos.Y)
		return (true);
	if (findPath(map, player,
		irr::core::vector2di(pos.X - 1, pos.Y)) == true)
		return (true);
	if (findPath(map, player,
		irr::core::vector2di(pos.X, pos.Y - 1)) == true)
		return (true);
	if (findPath(map, player,
		irr::core::vector2di(pos.X + 1, pos.Y)) == true)
		return (true);
	return (findPath(map, player, irr::core::vector2di(pos.X, pos.Y + 1))
		== true ? true : false);
}

direction NPC::findPathInit(Map *map, BasicPlayer *player)
{
	_path.clear();
	irr::core::vector2di pos;
	pos = irr::core::vector2di((int)(_pos.X), (int)(_pos.Y));
	_path.push_back(pos);
	if ((int)(player->getPos().X) == pos.X
	&& (int)(player->getPos().Y) == pos.Y)
		return (NONE);
	if (findPath(map, player,
		irr::core::vector2di(pos.X - 1, pos.Y)) == true)
		return (LEFT);
	if (findPath(map, player,
		irr::core::vector2di(pos.X, pos.Y - 1)) == true)
		return (UP);
	if (findPath(map, player,
		irr::core::vector2di(pos.X + 1, pos.Y)) == true)
		return (RIGHT);
	if (findPath(map, player,
		irr::core::vector2di(pos.X, pos.Y + 1)) == true)
		return (DOWN);
	return (NONE);
}

direction NPC::pathToEnemy(Map *map, std::vector<BasicPlayer *> &players)
{
	float dist = -1;
	int playerPos = -1;
	direction dir = NONE;
	for (int i = 0; i < 4; i++) {
		float distX = _pos.X - players[i]->getPos().X;
		float distY = _pos.Y - players[i]->getPos().Y;
		distX = (distX < 0 ? -distX : distX);
		distY = (distY < 0 ? -distY : distY);
		if (dist == -1 || distX + distY < dist) {
			dist = distX + distY;
			playerPos = i;
		}
	}
	if (playerPos != -1)
		dir = findPathInit(map, players[playerPos]);
	return (dir);
}

void NPC::updatePlayer(Map *map, std::vector<BasicPlayer *> &players)
{
	updateCooldown();
	direction dir = isThreatened(map);
	if (dir != NONE) {
		_bombDir = dir;
		setDir(dir);
	} else if (_bombs == _maxBomb && nearEnemy(map, players) == true) {
		placeBomb();
	} else if (_bombDir != NONE) {
		setDir(_bombDir);
		_bombDir = (_bombIt + 1 == 8 ? NONE : _bombDir);
		_bombIt = (_bombIt + 1 == 8 ? 0 : _bombIt + 1);
	} else {
		dir = pathToEnemy(map, players);
		if (dir != NONE)
			setDir(dir);
		else if (_bombs == _maxBomb && nearBlock(map) == true)
			placeBomb();
		else if (_bombs == _maxBomb)
			getRandomDir(map);
	}
}

void	NPC::run()
{
	if (!_runing){
		_graphObj->setAnim(irr::scene::EMAT_RUN);
		_runing = true;
	}
}

void    NPC::stand()
{
	if (_runing){
		_graphObj->setAnim(irr::scene::EMAT_STAND);
		_runing = false;
	}
}

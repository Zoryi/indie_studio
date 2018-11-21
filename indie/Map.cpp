//
// EPITECH PROJECT, 2018
// Indie
// File description:
// Indie
//

#include "Map.hpp"

Map::Map(IndieWindow *win, const size_t &width, const size_t &height)
	: _width(width), _height(height)
{
	_window = win;
        switch(getRand(0, 2))
	{
	case 0 : mapg = "XXXXXXXXXXXXXXXXP##XOOOOOX##PXX###OOAOAOO###X";
		mapg += "X###AAOOOAA###XXXOOXAAOAAXOOXXXOAAXOOXAAXOOOX";
		mapg +=	"XOOOAAAXAAAOOOXXOOOOXXXXXOOOOXXOAOOOAXAOOOAOX";
		mapg +=	"XOAOXAAXOOXAAOXXXAAXOOOAAXOOXXX###AOOOOOA###X";
		mapg +=	"X###OOAOAOO###XXP##XOOOOOX##PXXXXXXXXXXXXXXXX";
		break;
	case 1 : mapg = "XXXXXXXXXXXXXXXXP##AOOXOOA##PXX###OXAOAXO###X";
		mapg += "X###OXAOAXO###XXOOXXAAOAAXXOOXXOAAXOXXXOXAAOX";
		mapg +=	"XOAOOOAXOOAOOOXXOOOXXOXOXXOOOXXOOOAOOXOOAOOOX";
		mapg +=	"XOAAXOOXAAXOOOXXAAXXAAOOOXXAAXX###OXAOAXO###X";
		mapg +=	"X###OXAOAXO###XXP##AOOXOOA##PXXXXXXXXXXXXXXXX";
		break;
	case 2 : mapg = "XXXXXXXXXXXXXXXXP##OOOAOOO##PXX###OOOAOOO###X";
		mapg += "X###OOOAOOO###XXOAOOOOOOOOOAOXXOXOOXOOOOOOXOX";
		mapg +=	"XOXOOOXOOOOXOOXXOXOOOXOOOOXOOXXOXAOOOXAAXOOOX";
		mapg +=	"XOXXXOOOXXOOOOXXOAOOOOOOOOOAOXX###OOOAOOO###X";
		mapg +=	"X###OOOAOOO###XXP##OOOAOOO##PXXXXXXXXXXXXXXXX";
		break;
	}
	initEmptyMap();
	initMap();
}

Map::~Map()
{
	for (size_t y = 0; y < _height; y++) {
		for (size_t x = 0; x < _width; x++)
			if (_map[y][x] != NULL)
				delete _map[y][x];
	}
}

void	Map::initEmptyMap()
{
	for (size_t y = 0 ; y < _height ; y++){
		_map.push_back(std::vector<IObject*>());
		for (size_t x = 0 ; x < _width ; x++)
			_map[y].push_back(NULL);
	}
}

void	Map::initMap()
{
	size_t k = 0;
	irr::core::vector2di	pos(0, 0);
	for (size_t y = 0; y < _height; y++) {
		for (size_t x = 0; x < _width; x++)
		{
			pos = irr::core::vector2di(x, y);
			switch(mapg[k]) {
			case 'X' : _map[y][x] = new Block(_window, false, pos);
				break;
			case '#' : _map[y][x] = NULL;
				break;
		        case 'O' : _map[y][x] = new Block(_window, true, pos);
				break;
			case 'A' : _map[y][x] = Random(pos);
				break;
			default :
				break;
			}
			k++;
		}
	}
}

IObject *Map::getObject(const size_t &posx, const size_t &posy)
{
	size_t x = (posx >= _width ? (_width - 1) : posx);
	size_t y = (posy >= _height ? (_height - 1) : posy);
	return (_map[y][x]);
}

void Map::removeObject(const size_t &posx, const size_t &posy)
{
	size_t x = (posx >= _width ? (_width - 1) : posx);
	size_t y = (posy >= _height ? (_height - 1) : posy);
	IObject *obj = _map[y][x];
	if (obj != NULL) {
		int rand = getRand(0, 100);
		if (obj->getType() != BLOCK || rand <= 66)
			_map[y][x] = NULL;
		else
			_map[y][x] = randPU(irr::core::vector2di(posx, posy));
		delete obj;
	}
}

bool Map::addObject(const size_t &posx, const size_t &posy,
			IObject *ptr)
{
	size_t x = (posx >= _width ? (_width - 1) : posx);
	size_t y = (posy >= _height ? (_height - 1) : posy);
	IObject *obj = _map[y][x];
	bool success = false;
	if (obj == NULL) {
		_map[y][x] = ptr;
		success = true;
	}
	return (success);
}

bool Map::updateBomb(std::vector<BasicPlayer *> &players, IObject *obj)
{
	bool ret = false;

	if (obj == NULL)
		return ret;
	if (obj->getType() == BOMB) {
		Bomb *bombCast = dynamic_cast<Bomb *>(obj);
	        if (bombCast->getTimer() >= 3000 &&
		    bombCast->getExplode() == false)
			bombCast->explode(this, players);
		else if (bombCast->getTimer() >= 3500)
			ret = true;
	}
	return ret;
}

void Map::updateBombs(std::vector<BasicPlayer *> &players)
{
	for (size_t y = 0; y < _height; y++) {
		for (size_t x = 0; x < _width; x++) {
			if (updateBomb(players, _map[y][x]) == true)
				removeObject(x, y);
		}
	}
}

int Map::getRand(int min, int max)
{
        time_t seed;
	static time_t oldseed = 0;
	
        seed = time(NULL) + oldseed;
        oldseed = seed;
 
        srand(seed);
 
        int n = max - min + 1;
        int i = rand() % n;
 
        if(i < 0)
		i = -i;
 
        return min + i;
}

IObject	*Map::randPU(irr::core::vector2di pos)
{
	IObject *obj;

	switch(getRand(0, 3)) {
	case 0 : obj = new BombUp(_window, pos);
		break;
	case 1 : obj = new FireUp(_window, pos);
		break;
	case 2 : obj = new SpeedUp(_window, pos);
		break;
	case 3 : obj = new WallPass(_window, pos);
		break;
	}
	return obj;
}

IObject *Map::Random(irr::core::vector2di pos)
{
	int i;
	IObject *obj;
	i = getRand(0, 2);
	if (i == 2)
	{
		switch(getRand(0, 3)) {
		case 0 : obj = new BombUp(_window, pos);
			break;
		case 1 : obj = new FireUp(_window, pos);
			break;
		case 2 : obj = new SpeedUp(_window, pos);
			break;
		case 3 : obj = new WallPass(_window, pos);
			break;
		}
	}
	else
		switch(i) {
		case 0 : obj = NULL;
			break;
		case 1 : obj = new Block(_window, true, pos);
			break;
		}
	return (obj);
}

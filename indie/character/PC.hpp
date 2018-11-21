//
// EPITECH PROJECT, 2018
// Indie
// File description:
// Indie
//

#ifndef PC_HPP_
# define PC_HPP_

# include "BasicPlayer.hpp"
# include "IndieWindow.hpp"
# include "UI.hpp"

class UI;

class PC : public BasicPlayer
{
public:
	PC(IndieWindow *indie, const int &id, irr::core::vector2df pos);
	~PC();
	void	deletePlayer() override;
	void	updatePlayer(IndieEventReceiver &receiver);
	void	setPos(irr::core::vector2df pos) override;
	void	setDir(direction dir) override;
	void	run() override;
	void	stand() override;
private:
	int catchP1(IndieEventReceiver &receiver);
	int catchP2(IndieEventReceiver &receiver);
	GraphObj	*_graphObj;
	bool		_runing;
	UI		*_ui;
};

#endif

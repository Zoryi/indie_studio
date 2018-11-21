//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// IndieEventReceiver
//

#ifndef INDIEEVENTRECEIVER_HPP_
# define INDIEEVENTRECEIVER_HPP_

#include <irrlicht/Keycodes.h>
#include <irrlicht/IEventReceiver.h>

class IndieEventReceiver : public irr::IEventReceiver
{
public:
	IndieEventReceiver();
	~IndieEventReceiver();
	bool	OnEvent(const irr::SEvent &event) override;
	bool	IsKeyDown(irr::EKEY_CODE keyCode) const;
	bool	IsKeyReleased(irr::EKEY_CODE keyCode);
private:
	bool	KeyIsDown[irr::KEY_KEY_CODES_COUNT];
	bool	KeyIsReleased[irr::KEY_KEY_CODES_COUNT];
};

#endif

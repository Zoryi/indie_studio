//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// IndieEventReceiver
//

#include "IndieEventReceiver.hpp"

IndieEventReceiver::IndieEventReceiver()
{
	for (irr::u32 i = 0; i < 0xFF; i++) {
		KeyIsDown[i] = false;
	}
	for (irr::u32 i = 0; i < 0xFF; i++) {
		KeyIsReleased[i] = false;
	}
}

IndieEventReceiver::~IndieEventReceiver()
{}

bool	IndieEventReceiver::OnEvent(const irr::SEvent &event)
{
	if (event.EventType == irr::EET_KEY_INPUT_EVENT) {
		KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
		if (!event.KeyInput.PressedDown)
			KeyIsReleased[event.KeyInput.Key] = true;
	}
	return false;
}

bool	IndieEventReceiver::IsKeyDown(irr::EKEY_CODE keyCode) const
{
	return KeyIsDown[keyCode];
}

bool	IndieEventReceiver::IsKeyReleased(irr::EKEY_CODE keyCode)
{
	
	if (KeyIsReleased[keyCode])
		KeyIsReleased[keyCode] = false;
	else
		return false;
	return true;
}

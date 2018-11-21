//
// EPITECH PROJECT, 2018
// Indie
// File description:
// Sound
//

#include "Sound.hpp"

Sound::Sound()
{
	engine_msc = irrklang::createIrrKlangDevice();
	engine_snd = irrklang::createIrrKlangDevice();
	vol_msc = 0.6;
	vol_snd = 0.6;
	setVolumeMusic(vol_msc);
	setVolumeSound(vol_snd);
	mute["All"] = 0;
	mute["Music"] = 0;
	mute["Sound"] = 0;
}

Sound::~Sound()
{
	engine_msc->drop();
	engine_snd->drop();
	mute.clear();
}

void	Sound::playMusic(std::string path)
{
	if (!mute["All"] && !mute["Music"])
		engine_msc->play2D(path.c_str(), true);
}

void	Sound::playSound(std::string path)
{
	if (!mute["All"] && !mute["Sound"])
		engine_snd->play2D(path.c_str());
}

void	Sound::muteMusic()
{
	if (!mute["All"] && !mute["Music"]) {
		engine_msc->setAllSoundsPaused();
		mute["Music"] = 1;
        } else if (mute["Music"]) {
		engine_msc->setAllSoundsPaused(0);
		mute["Music"] = 0;
		if (mute["All"])
			mute["All"] = 0;
	}
}

void	Sound::muteSound()
{
	if (!mute["All"] && !mute["Sound"]) {
		engine_snd->setAllSoundsPaused();
		mute["Sound"] = 1;
        } else if (mute["Sound"]) {
		engine_snd->setAllSoundsPaused(0);
		mute["Sound"] = 0;
		if (mute["All"])
			mute["All"] = 0;
	}
}

void	Sound::muteAll()
{
	if (!mute["All"]) {
		engine_snd->setAllSoundsPaused();
		engine_msc->setAllSoundsPaused();
		mute["All"] = 1;
		mute["Music"] = 1;
		mute["Sound"] = 1;
	} else {
		engine_snd->setAllSoundsPaused(0);
		engine_msc->setAllSoundsPaused(0);
		mute["All"] = 0;
		mute["Music"] = 0;
		mute["Sound"] = 0;
	}
}

void	Sound::setVolumeMusic(int nb)
{
	if (mute["Music"])
		if ((nb == 0 && vol_msc > 0.0) ||
		    (nb == 1 && vol_msc < 1.0))
		        muteMusic();
        if (nb == 0 && vol_msc >= 0.1)
		vol_msc -= 0.1;
	else if (nb == 1 && vol_msc < 1.0)
		vol_msc += 0.1;
	if (vol_msc > 0.0)
		engine_msc->setSoundVolume(vol_msc);
}

void	Sound::setVolumeSound(int nb)
{
	if (mute["Sound"])
		if ((nb == 0 && vol_snd > 0.0) ||
		    (nb == 1 && vol_snd < 1.0))
			muteSound();
        if (nb == 0 && vol_snd >= 0.1)
		vol_snd -= 0.1;
	else if (nb == 1 && vol_snd < 1.0)
		vol_snd += 0.1;
	if (vol_snd > 0.0)
		engine_snd->setSoundVolume(vol_snd);
}

float	Sound::getVolumeMusic()
{
	return vol_msc;
}

float	Sound::getVolumeSound()
{
	return vol_snd;
}

irrklang::ISoundEngine*	Sound::getEngine()
{
	return engine_msc;
}

int	Sound::getMute(std::string name)
{
	return mute[name];
}

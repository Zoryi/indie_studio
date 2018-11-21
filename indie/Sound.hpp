//
// EPITECH PROJECT, 2018
// Indie
// File description:
// Sound
//

#include <string>
#include <map>
#include <irrKlang.h>
#include "conio.h"

class Sound
{
public:
	Sound();
	~Sound();
	void	playMusic(std::string path);
	void	playSound(std::string path);
        void	muteMusic();
	void	muteSound();
	void	muteAll();
	void	setVolumeMusic(int nb);
	void	setVolumeSound(int nb);
	float	getVolumeMusic();
	float	getVolumeSound();
	irrklang::ISoundEngine*	getEngine();
	int	getMute(std::string name);
private:
	std::map<std::string, int> mute;
	float			vol_msc;
	float			vol_snd;
	irrklang::ISoundEngine* engine_msc;
	irrklang::ISoundEngine* engine_snd;
};

//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// AnimFireExplo
//

#ifndef ANIMFIREEXPLO_HPP_
# define ANIMFIREEXPLO_HPP_

#include "IndieWindow.hpp"
#include "Info3d.hpp"

class AnimFireExplo
{
	public:
	AnimFireExplo(IndieWindow *window, Info3d &info3d);
	~AnimFireExplo();
	void	doAnimFire(void);
	private:
	irr::scene::ISceneManager		*_scene;
	irr::video::IVideoDriver		*_driver;
	irr::scene::IParticleSystemSceneNode	*_pS;
	irr::scene::IParticleEmitter		*_pE;
	irr::scene::IParticleAffector		*_pA;
	irr::core::vector3df			_pos;
	irr::core::vector3df			_scale;
};

#endif /* !ANIMFIREEXPLO_HPP_ */

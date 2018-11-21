//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// AnimFireExplo
//

#include "AnimFireExplo.hpp"

AnimFireExplo::AnimFireExplo(IndieWindow *window, Info3d &info3d)
{
	_scene = window->getSceneManager();
	_driver = window->getDriver();
	_pS = _scene->addParticleSystemSceneNode(false);
	_pE = _pS->createBoxEmitter(
		irr::core::aabbox3d<irr::f32>(-3,0,-3,20,1,20),
		irr::core::vector3df(0.0f,0.06f,0.0f),
		2000,2500,
		irr::video::SColor(0,255,255,255),
		irr::video::SColor(0,255,255,255),
		100,200,0,
		irr::core::dimension2df(10.f,10.f),
		irr::core::dimension2df(20.f,20.f));
	_pS->setEmitter(_pE);
	_pE->drop();
	_pA = _pS->createFadeOutParticleAffector();
	_pS->addAffector(_pA);
	_pA->drop();
	_pos = info3d.getPos();
	_scale = info3d.getScale();
	doAnimFire();
}

AnimFireExplo::~AnimFireExplo()
{
	_scene->addToDeletionQueue(_pS);
}

void	AnimFireExplo::doAnimFire(void)
{
	_pS->setPosition(_pos);
	_pS->setScale(_scale);
	_pS->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_pS->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
	_pS->setMaterialTexture(0, _driver->getTexture("obj/Bomb/fire.bmp"));
	_pS->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
}

//
// EPITECH PROJECT, 2018
// indie_studio
// File description:
// GraphObj.cpp
//

#include "GraphObj.hpp"

GraphObj::GraphObj(IndieWindow *indieW, std::string name,
			Info3d info3d)
{
	irr::core::vector3df	pos = info3d.getPos();
	irr::core::vector3df	rotation = info3d.getRotate();
	irr::core::vector3df	scale = info3d.getScale();

	_sceneManager = indieW->getSceneManager();
	_mesh = indieW->getFile(name).first;
	_sceneNode = _sceneManager->addAnimatedMeshSceneNode(_mesh, nullptr, 0,
				        pos, rotation, scale);
	_sceneNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	if (indieW->getFile(name).second)
		_sceneNode->setMaterialTexture(0,
				        indieW->getFile(name).second);
}

GraphObj::~GraphObj()
{
	_sceneManager->addToDeletionQueue(_sceneNode);
}

void	GraphObj::setTexture(irr::video::ITexture* texture)
{
	_sceneNode->setMaterialTexture(0, texture);
}

irr::core::vector3df	GraphObj::getPos()
{
	return _sceneNode->getPosition();
}

void	GraphObj::setPos(irr::core::vector3df pos)
{
	_sceneNode->setPosition(pos);
}

irr::core::vector3df	GraphObj::getRotate()
{
	return _sceneNode->getRotation();
}

void	GraphObj::setRotate(irr::core::vector3df pos)
{
	return _sceneNode->setRotation(pos);
}

void	GraphObj::setAnim(irr::scene::EMD2_ANIMATION_TYPE anim)
{
	_sceneNode->setMD2Animation(anim);
}

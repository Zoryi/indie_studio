//
// EPITECH PROJECT, 2018
// indie_studio
// File description:
// GraphObj.hpp
//

#ifndef GRAPHOBJ_HPP_
#define GRAPHOBJ_HPP_

#include <irrlicht/irrlicht.h>
#include "IndieWindow.hpp"
#include "Info3d.hpp"

class IndieWindow;

class GraphObj
{
public:
	GraphObj(IndieWindow *indieW, std::string name,	Info3d pos);
	~GraphObj();
	void	setTexture(irr::video::ITexture* texture);
	irr::core::vector3df	getPos();
	void			setPos(irr::core::vector3df pos);
	irr::core::vector3df	getRotate();
	void			setRotate(irr::core::vector3df pos);
	void			setAnim(irr::scene::EMD2_ANIMATION_TYPE type);
private:
	irr::scene::IAnimatedMesh	*_mesh;
	irr::scene::IAnimatedMeshSceneNode	*_sceneNode;
	irr::scene::ISceneManager	*_sceneManager;
};

#endif

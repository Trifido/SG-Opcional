#ifndef SCENE_H
#define SCENE_H

#include <osg/Group>
#include <osg/Texture2D>
#include <osg/MatrixTransform>
#include <osg/PositionAttitudeTransform>
#include <osgDB/ReadFile>

#include <osgViewer/Viewer>

#include "Esfera.h"

class Scene:public osg::Group{
	private:
		osg::ref_ptr<Esfera> background;
		osg::ref_ptr<osg::MatrixTransform> sBack;
		void addBackground();
		void addTextures();
	public:
		Scene();	
}

#endif
#ifndef ESFERA_H
#define ESFERA_H
#include <osg/Geode>
#include <osg/ShapeDrawable>

class Esfera:public osg::Geode{
public:
	Esfera();
    Esfera(float posX, float posY, float posZ, float radio);  
};

#endif
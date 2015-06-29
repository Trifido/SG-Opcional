#ifndef ESFERA_H
#define ESFERA_H
#include <osg/Geode>
#include <osg/ShapeDrawable>
#include <osg/Material>

class Esfera:public osg::Geode{
private:
	osg::ref_ptr<osg::Material> material;
public:
	Esfera();
    Esfera(float posX, float posY, float posZ, float radio, std::string nombre);  
};

#endif
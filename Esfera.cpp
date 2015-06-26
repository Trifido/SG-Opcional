#include "Esfera.h"

Esfera::Esfera(float posX, float posY, float posZ, float radio){     	

    osg::ref_ptr<osg::Sphere> geo = new osg::Sphere(osg::Vec3(posX,posY,posZ), radio);//geometria

	osg::ref_ptr<osg::ShapeDrawable> draw = new osg::ShapeDrawable(geo);//crear drawable

	this->addDrawable(draw);    
}

Esfera::Esfera(){
	osg::ref_ptr<osg::Sphere> geo = new osg::Sphere(osg::Vec3(0,0,0), 1);//geometria

	osg::ref_ptr<osg::ShapeDrawable> draw = new osg::ShapeDrawable(geo);//crear drawable

	this->addDrawable(draw); 
}
#include "Esfera.h"

Esfera::Esfera(){     	

    osg::ref_ptr<osg::Sphere> geo = new osg::Sphere(osg::Vec3(0.0f,0.0f,0.0f), 1);//geometria

	osg::ref_ptr<osg::ShapeDrawable> draw = new osg::ShapeDrawable(geo);//crear drawable

	this->addDrawable(draw);    
}
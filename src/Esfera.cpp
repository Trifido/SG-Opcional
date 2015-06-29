#include "Esfera.h"

Esfera::Esfera(float posX, float posY, float posZ, float radio, std::string nombre){     	

    osg::ref_ptr<osg::Sphere> geo = new osg::Sphere(osg::Vec3(posX,posY,posZ), radio);//geometria

	osg::ref_ptr<osg::ShapeDrawable> draw = new osg::ShapeDrawable(geo);//crear drawable

	material = new osg::Material;
	material->setAmbient( osg::Material::FRONT, osg::Vec4(0.1f, 0.1f, 0.1f, 1.0f) );
	//

	if(nombre=="sol"){
		material->setEmission(osg::Material::FRONT_AND_BACK, osg::Vec4(1.0,1.0f,1.0f,1.0f));
		material->setShininess( osg::Material::FRONT, 50.0f );
	}

	this->getOrCreateStateSet()->setAttributeAndModes(material, osg::StateAttribute::ON);

	this->addDrawable(draw);    
}

Esfera::Esfera(){
	osg::ref_ptr<osg::Sphere> geo = new osg::Sphere(osg::Vec3(0,0,0), 1);//geometria

	osg::ref_ptr<osg::ShapeDrawable> draw = new osg::ShapeDrawable(geo);//crear drawable

	this->addDrawable(draw); 
}
#include "Astro.h"
#include <osgDB/ReadFile>

Astro::Astro(std::string nombre, float radio, float posX, float posY, float posZ, float vRotEje, float vTras){
	this->radio= radio;
	esfera= new Esfera(0.0f, 0.0f, 0.0f, radio);
	
	addRama(posX, posY, posZ, vTras, vRotEje);
	addTexture(nombre);
}

void Astro::addRama(float posX, float posY, float posZ, float vTras, float vRotEje){
	orbita = new osg::MatrixTransform();
	traslacion = new osg::MatrixTransform();
	rotarEje = new osg::MatrixTransform();

	orbita->setMatrix(osg::Matrix::rotate(0,1,0,vTras));
	traslacion->setMatrix(osg::Matrix::translate(posX, posY, posZ));
	rotarEje->setMatrix(osg::Matrix::rotate(0,1,0,vRotEje));

	rotarEje->addChild(esfera);
	traslacion->addChild(rotarEje);
	orbita->addChild(traslacion);
	this->addChild(orbita);
}

void Astro::addTexture(std::string nombre){
	osg::ref_ptr<osg::Image> img= osgDB::readImageFile(nombre+".jpg");
	textura= new osg::Texture2D;
	textura->setImage(img.get());

	osg::ref_ptr<osg::StateSet> stateOnePlaneta = new osg::StateSet();

   	stateOnePlaneta->setTextureAttributeAndModes(0,textura,osg::StateAttribute::ON);
   	esfera->setStateSet(stateOnePlaneta);
}

void Astro::addSatelite(Astro satelite){
	traslacion->addChild(satelite.asGroup());
}
/*    
void Astro::addAnillo( Anillo ring){
    position.addChild(ring.getBranchGroup());  
}
*/
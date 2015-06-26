#include "Astro.h"
#include <osgDB/ReadFile>

Astro::Astro(int id, float posX, float posY, float posZ, float vRotEje, float vTras){
	osg::ref_ptr<osg::Image> img;
	float radio;

	switch(id){	//Los satelites se añaden en la escena a los planetas correspondientes.
		case 1:	//SOL
			radio= 27.0f;
			img= osgDB::readImageFile("./imgs/sol.jpg");
			break;
		case 2:	//MERCURIO
			radio= 0.5f;
			img= osgDB::readImageFile("./imgs/mercurio.jpg");
			break;
		case 3:	//VENUS
			radio= 1.2f;
			img= osgDB::readImageFile("./imgs/venus.jpg");
			break;
		case 4:	//TIERRA
			radio= 1.5f;
			img= osgDB::readImageFile("./imgs/tierra.jpg");
			break;
		case 5:	//LUNA
			radio= 0.5f;
			img= osgDB::readImageFile("./imgs/luna.jpg");
			break;
		case 6:	//MARTE
			radio= 1.3f;
			img= osgDB::readImageFile("./imgs/marte.jpg");
			break;
		case 7:	//PHOBOS
			radio= 0.4f;
			img= osgDB::readImageFile("./imgs/phobos.jpg");
			break;
		case 8:	//DEIMOS
			radio= 0.4f;
			img= osgDB::readImageFile("./imgs/deimos.jpg");
			break;
		case 9:	//JUPITER
			radio= 9.0f;
			img= osgDB::readImageFile("./imgs/jupiter.jpg");
			break;
		case 10: //IO
			radio= 0.53f;
			img= osgDB::readImageFile("./imgs/io.jpg");
			break;
		case 11: //EUROPA
			radio= 0.48f;
			img= osgDB::readImageFile("./imgs/europa.jpg");
			break;
		case 12:	//GANIMEDES
			radio= 0.6f;
			img= osgDB::readImageFile("./imgs/ganimedes.jpg");
			break;
		case 13:	//CALISTO
			radio= 0.57f;
			img= osgDB::readImageFile("./imgs/calisto.jpg");
			break;
		case 14:	//SATURNO   los anillos habría que añadirlos en la escena
			radio= 7.0f;
			img= osgDB::readImageFile("./imgs/saturno.jpg");
			break;
		case 15:	//URANO
			radio= 4.5f;
			img= osgDB::readImageFile("./imgs/urano.jpg");
			break;
		case 16:	//TITANIA
			radio= 0.53f;
			img= osgDB::readImageFile("./imgs/titania.jpg");
			break;
		case 17:	//OBERON
			radio= 0.48f;
			img= osgDB::readImageFile("./imgs/oberon.jpg");
			break;
		case 18:	//UMBRIEL
			radio= 0.6f;
			img= osgDB::readImageFile("./imgs/umbriel.jpg");
			break;
		case 19:	//ARIEL
			radio= 0.57f;
			img= osgDB::readImageFile("./imgs/ariel.jpg");
			break;
		case 20:	//MIRANDA
			radio= 0.57f;
			img= osgDB::readImageFile("./imgs/miranda.jpg");
			break;
		case 21:	//NEPTURNO
			radio= 4.5f;
			img= osgDB::readImageFile("./imgs/neptuno.jpg");
			break;
		case 22:	//TRITON
			radio= 0.57f;
			img= osgDB::readImageFile("./imgs/triton.jpg");
			break;
		default:
			radio= 1.0f;
			img= osgDB::readImageFile("./imgs/tierra.jpg");
			break;
	}

	esfera= new Esfera(0.0f, 0.0f, 0.0f, radio);
	
	addRama(posX, posY, posZ, vTras, vRotEje);
	addTexture(img);
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

void Astro::addTexture(osg::ref_ptr<osg::Image> img){
	textura->setImage(img);

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
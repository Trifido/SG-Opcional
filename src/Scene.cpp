#include "Scene.h"
#include "Astro.h"

#include <osg/Light>
#include <osg/LightSource>
#include <osg/LightModel>

Scene::Scene(){
	//BACKGROUND		tal vez una clase background
	background= new Esfera(0.0f, 0.0f, 0.0f, 1.0f,"universo");
	sBack = new osg::MatrixTransform();
	addBackground();
	addTextures();
	
	//SOL
	this->addChild(new Astro("sol", 27.0f, 0.0f, 0.0f, 0.0f, 0.01f, 0.10f));

	//MERCURIO
	this->addChild(new Astro("mercurio", 0.5f, 30.0f, 0.0f, 0.0f, 1.0f, 2.0f));

	//VENUS
	this->addChild(new Astro("venus", 1.2f, 40.0f, 0.0f, 0.0f, 1.0f, 1.5f));

	//TIERRA Y LUNA
	Astro tierra= Astro("tierra", 1.5f, 50.0f, 0.0f, 0.0f, 1.0f, 1.4f);
	Astro luna= Astro("luna", 0.5f, 7.0f, 0.0f, 0.0f, 1.0f, 2.0f);
	tierra.addSatelite(luna);
	this->addChild(tierra.getAstro());	//FUNCIONARÁ??

	//MARTE, PHOBOS Y DEIMOS
	Astro marte= Astro("marte", 1.3f, 70.0f, 0.0f, 0.0f, 1.0f, 1.2f);
	Astro phobos= Astro("phobos", 0.4f, 7.0f, 0.0f , 0.0f, 1.0f, 1.5f);
	Astro deimos= Astro("deimos", 0.4f, 12.0f, 0.0f, 0.0f ,1.0f ,1.6f);
	marte.addSatelite(phobos);
	marte.addSatelite(deimos);
	this->addChild(marte.getAstro());

	//JUPITER, IO, EUROPA, GANIMEDES Y CALISTO
	Astro jupiter= Astro("jupiter", 9.0f, 100.0f, 0.0f, 0.0f, 1.5f, 1.0f);
	Astro io= Astro("io", 0.53f, 16.0f, 0.0f, 0.0f, 1.0f, 1.6f);
	Astro europa= Astro("europa", 0.48f, 20.0f , 0.0f, 0.0f, 1.0f, 1.4f);
	Astro ganimedes= Astro("ganimedes", 0.6f, 25.0f, 0.0f, 0.0f, 1.0f, 1.2f);
	Astro calisto= Astro("calisto", 0.57f, 30.0f, 0.0f, 0.0f, 1.0f, 1.8f);
	jupiter.addSatelite(io);
	jupiter.addSatelite(europa);
	jupiter.addSatelite(ganimedes);
	jupiter.addSatelite(calisto);
	this->addChild(jupiter.getAstro());

	//SATURNO Y ANILLOS
	//Los anillos para otro commit
	Astro saturno= Astro("saturno", 7.0f, 150.0f, 0.0f, 0.0f, 1.3f, 0.8f);
	//saturno.addAnillo(...)
	//saturno.addAnillo(...)
	//saturno.addAnillo(...)
	this->addChild(saturno.getAstro());

	//URANO, TITANIA, OBERON, UMBRIEL, ARIEL Y MIRANDA
	Astro urano= Astro("urano", 4.5f, 190.0f, 0.0f, 0.0f, 1.0f, 0.6f);
	Astro titania= Astro("titania", 0.53f, 17.0f, 0.0f, 0.0f, 1.0f, 1.5f);
	Astro oberon= Astro("oberon", 0.48f, 20.0f, 0.0f, 0.0f, 1.0f, 1.3f);
	Astro umbriel= Astro("umbriel", 0.6f, 12.0f, 0.0f, 0.0f, 1.0f, 1.1f);
	Astro ariel= Astro("ariel", 0.57f, 8.0f, 0.0f, 0.0f, 1.0f, 1.6f);
	Astro miranda= Astro("miranda", 0.57f, 5.0f, 0.0f, 0.0f, 1.0f, 1.0f);

	urano.addSatelite(titania);
	urano.addSatelite(oberon);
	urano.addSatelite(umbriel);
	urano.addSatelite(ariel);
	urano.addSatelite(miranda);
	this->addChild(urano.getAstro());

	//NEPTUNO Y TRITÓN
	Astro neptuno= Astro("neptuno",  4.5f, 220.0f, 0.0f, 0.0f, 1.0f, 0.4f);
	Astro triton= Astro("triton", 0.57f, 9.0f, 0.0f, 0.0f, 1.0f, 2.0f);

	neptuno.addSatelite(triton);
	this->addChild(neptuno.getAstro());

	//AÑADIMOS ILUMINACIÓN
	osg::LightSource* sunLightSource = new osg::LightSource;
	
    osg::Light* sunLight = sunLightSource->getLight();
    sunLight->setPosition( osg::Vec4( 0.0f, 0.0f, 0.0f, 1.0f ) );
    sunLight->setAmbient( osg::Vec4( 0.0f, 0.0f, 0.0f, 1.0f ) );

    sunLightSource->setLight( sunLight );
    sunLightSource->setLocalStateSetModes( osg::StateAttribute::ON );
    sunLightSource->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::ON);

    osg::LightModel* lightModel = new osg::LightModel;
    lightModel->setAmbientIntensity(osg::Vec4(0.0f,0.0f,0.0f,1.0f));
    sunLightSource->getOrCreateStateSet()->setAttribute(lightModel);

    this->addChild(sunLightSource);

    //Cargar Modelo
    osg::Node* rocket = osgDB::readNodeFile("./rocket/rocket.3ds");
    this->addChild(rocket);
}

void Scene::addBackground(){
	sBack->setMatrix(osg::Matrix::scale(1000, 1000, 1000));
	sBack->addChild(background);

	this->addChild(sBack);
}

void Scene::addTextures(){
	//Background
	osg::ref_ptr<osg::Texture2D> textureUniverso = new osg::Texture2D();

	osg::ref_ptr<osg::Image> imgUniverso = osgDB::readImageFile("./imgs/space.jpg");

	textureUniverso->setImage(imgUniverso);

	osg::ref_ptr<osg::StateSet> stateOneUniverse = new osg::StateSet();

   	stateOneUniverse->setTextureAttributeAndModes(0,textureUniverso,osg::StateAttribute::ON);
   	background->setStateSet(stateOneUniverse);
}

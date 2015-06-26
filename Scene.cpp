#include "Scene.h"
#include "Astro.h"

Scene::Scene(){
	//BACKGROUND		tal vez una clase background
	background= new Esfera(0.0f, 0.0f, 0.0f, 1.0f);
	sBack = new osg::MatrixTransform();
	addBackground();
	addTextures();
	
	//SOL
	this->addChild(new Astro(1, 0.0f, 0.0f, 0.0f, 20.0f, 0.0f));

	//MERCURIO
	this->addChild(new Astro(2, 30.0f, 0.0f, 0.0f, 20.0f, 0.0f));

	//VENUS
	this->addChild(new Astro(3, 40.0f, 0.0f, 0.0f, 20.0f, 0.0f));

	//TIERRA Y LUNA
	Astro tierra= Astro(4, 50.0f, 0.0f, 0.0f, 10000.0f, 30000.0f);
	Astro luna= Astro(5, 7.0f, 0.0f, 0.0f, 5000.0f, 5000.0f);
	tierra.addSatelite(luna);
	this->addChild(tierra.asGroup());	//FUNCIONARÁ??

	//MARTE, PHOBOS Y DEIMOS
	Astro marte= Astro(6, 70.0f, 0.0f, 0.0f, 9000.0f, 11000.0f);
	Astro phobos= Astro(7, 7.0f, 0.0f , 0.0f, 8000.0f, 8000.0f);
	Astro deimos= Astro(8, 12.0f, 0.0f, 0.0f ,5000.0f ,5000.0f);
	marte.addSatelite(phobos);
	marte.addSatelite(deimos);
	this->addChild(marte.asGroup());

	//JUPITER, IO, EUROPA, GANIMEDES Y CALISTO
	Astro jupiter= Astro(9, 100.0f, 0.0f, 0.0f, 12000.0f, 23000.0f);
	Astro io= Astro(10, 16.0f, 0.0f, 0.0f, 10000.0f, 5000.0f);
	Astro europa= Astro(11, 20.0f , 0.0f, 0.0f, 10000.0f, 6000.0f);
	Astro ganimedes= Astro(12, 25.0f, 0.0f, 0.0f, 10000.0f, 7000.0f);
	Astro calisto= Astro(13, 30.0f, 0.0f, 0.0f, 10000.0f, 8000.0f);
	jupiter.addSatelite(io);
	jupiter.addSatelite(europa);
	jupiter.addSatelite(ganimedes);
	jupiter.addSatelite(calisto);
	this->addChild(jupiter.asGroup());

	//SATURNO Y ANILLOS
	//Los anillos para otro commit
	Astro saturno= Astro(14, 150.0f, 0.0f, 0.0f, 15000.0f, 10000.0f);
	//saturno.addAnillo(...)
	//saturno.addAnillo(...)
	//saturno.addAnillo(...)
	this->addChild(saturno.asGroup());

	//URANO, TITANIA, OBERON, UMBRIEL, ARIEL Y MIRANDA
	Astro urano= Astro(15, 190.0f, 0.0f, 0.0f, 6000.0f, 16000.0f);
	Astro titania= Astro(16, 17.0f, 0.0f, 0.0f, 8000.0f, 8000.0f);
	Astro oberon= Astro(17, 20.0f, 0.0f, 0.0f, 8000.0f, 9000.0f);
	Astro umbriel= Astro(18, 12.0f, 0.0f, 0.0f, 8000.0f, 7000.0f);
	Astro ariel= Astro(19, 8.0f, 0.0f, 0.0f, 8000.0f, 6000.0f);
	Astro miranda= Astro(20, 5.0f, 0.0f, 0.0f, 8000.0f, 5000.0f);

	urano.addSatelite(titania);
	urano.addSatelite(oberon);
	urano.addSatelite(umbriel);
	urano.addSatelite(ariel);
	urano.addSatelite(miranda);
	this->addChild(urano.asGroup());

	//NEPTUNO Y TRITÓN
	Astro neptuno= Astro(21, 220.0f, 0.0f, 0.0f, 14000.0f, 9000.0f);
	Astro triton= Astro(22, 9.0f, 0.0f, 0.0f, 8000.0f, 8000.0f);

	neptuno.addSatelite(triton);
	this->addChild(neptuno.asGroup());
	
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
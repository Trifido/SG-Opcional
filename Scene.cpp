#include "Scene.h"

Scene::Scene(){
	background= new Esfera();
	sBack = new osg::MatrixTransform();

	addBackground();
	addTextures();
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
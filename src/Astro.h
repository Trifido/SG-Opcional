#ifndef ASTRO_H
#define ASTRO_H


#include "Esfera.h"
#include "rotatecb.h"

#include <osg/MatrixTransform>
#include <osg/Texture2D>
#include <osg/Group>
#include <osg/Node>

#include <osgViewer/Viewer>


class Astro:public osg::Group 
{ 
	private:
		osg::ref_ptr<Esfera> esfera;
		float radio;
		osg::ref_ptr<osg::Texture2D> textura;
		osg::ref_ptr<osg::MatrixTransform> orbita;
		osg::ref_ptr<osg::MatrixTransform> traslacion;	
		osg::ref_ptr<osg::MatrixTransform> rotarEje;
		osg::ref_ptr<osg::StateSet> stateOnePlaneta;

		void addRama(float posX, float posY, float posZ, float vTras, float vRotEje);
		void addTexture(std::string);

	public:
		Astro(){};
		Astro(std::string nombre, float radio, float posX, float posY, float posZ, float vRotEje, float vTras);
		void addSatelite(Astro satelite);
		osg::ref_ptr<osg::MatrixTransform> getAstro();
		//void addAnillo(Anillo ring);
};

#endif

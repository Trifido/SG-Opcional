#ifndef ASTRO_H
#define ASTRO_H


#include "Esfera.h"

#include <osg/MatrixTransform>
#include <osg/Texture2D>
#include <osg/Group>
#include <osg/Node>

#include <osgViewer/Viewer>


class Astro:public osg::Group 
{ 
	private:
		osg::ref_ptr<Esfera> esfera;
		osg::ref_ptr<osg::Texture2D> textura;
		osg::ref_ptr<osg::MatrixTransform> orbita;
		osg::ref_ptr<osg::MatrixTransform> traslacion;	
		osg::ref_ptr<osg::MatrixTransform> rotarEje;

		void addRama(float posX, float posY, float posZ, float vTras, float vRotEje);
		void addTexture(osg::ref_ptr<osg::Image> img);

	public:
		Astro(){};
		Astro(int id, float posX, float posY, float posZ, float vRotEje, float vTras);
		void addSatelite(Astro satelite);
		//void addAnillo(Anillo ring);
};

#endif
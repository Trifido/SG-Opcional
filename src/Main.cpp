#include <osg/Node>
#include <osg/Group>
#include <osg/Geode>
#include <osg/ShapeDrawable>
#include <osg/Material>
#include <osg/Geometry>
#include <osg/Texture2D>
#include <osgDB/ReadFile> 
#include <osgViewer/Viewer>
#include <osg/PositionAttitudeTransform>
#include <osgGA/TrackballManipulator>

#include "Scene.h"
#include "Astro.h"
//#include "mouseeventhandler.h"
#include <new>

using namespace osg;

int main()
{
    osgViewer::Viewer viewer;
	osg::ref_ptr<Scene> escena = new Scene();

    //Material
	/*	osg::ref_ptr<osg::Material> material = new osg::Material;
		material->setColorMode( osg::Material::AMBIENT );
		material->setAmbient( osg::Material::FRONT_AND_BACK, osg::Vec4(0.8f, 0.8f, 0.8f, 1.0f) );
		//material->setDiffuse( osg::Material::FRONT_AND_BACK, color*0.8f );
		//material->setSpecular( osg::Material::FRONT_AND_BACK, color );
		material->setShininess( osg::Material::FRONT_AND_BACK, 1.0f );

		node->getOrCreateStateSet()->setAttributeAndModes( material.get(), osg::StateAttribute::ON|osg::StateAttribute::OVERRIDE );
	*/

	//osg::ref_ptr<MouseEventHandler> pick= new MouseEventHandler();
	//escena->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::ON);
    

    //viewer.addEventHandler(new MouseEventHandler(escena));
    viewer.setSceneData( escena );
    viewer.setCameraManipulator(new osgGA::TrackballManipulator());
    viewer.realize();

	viewer.run();

    return 0;
}

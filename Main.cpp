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
#include <new>

using namespace osg;

int main()
{
    osgViewer::Viewer viewer;
    osg::ref_ptr<osg::Group> root = new osg::Group;
	//osg::ref_ptr<osg::Geode> pyramidGeode = new osg::Geode;
	//osg::ref_ptr<osg::Geometry> pyramidGeometry = new osg::Geometry;
	//osg::ref_ptr<osg::Node> node = new osg::Node;

    //Associate the pyramid geometry with the pyramid geode
    //   Add the pyramid geode to the root node of the scene graph.

	//pyramidGeode->addDrawable(pyramidGeometry.get());
	//root->addChild(pyramidGeode.get());


	osg::ref_ptr<Astro> astro = new Astro("tierra", 1.5f, 50.0f, 0.0f, 0.0f, 10000.0f, 30000.0f);
	//osg::ref_ptr<Esfera> esfera= new Esfera();

	//root->addChild(esfera);
	//viewer.setSceneData(escena);
	
	/*osg::ref_ptr<osg::Sphere> geo = new osg::Sphere(osg::Vec3(0.0f,0.0f,0.0f), 1);
	osg::ref_ptr<osg::ShapeDrawable> draw = new osg::ShapeDrawable(geo);//crear drawable
	pyramidGeode->addDrawable(draw);*/

    //Material
	/*	osg::ref_ptr<osg::Material> material = new osg::Material;
		material->setColorMode( osg::Material::AMBIENT );
		material->setAmbient( osg::Material::FRONT_AND_BACK, osg::Vec4(0.8f, 0.8f, 0.8f, 1.0f) );
		//material->setDiffuse( osg::Material::FRONT_AND_BACK, color*0.8f );
		//material->setSpecular( osg::Material::FRONT_AND_BACK, color );
		material->setShininess( osg::Material::FRONT_AND_BACK, 1.0f );

		node->getOrCreateStateSet()->setAttributeAndModes( material.get(), osg::StateAttribute::ON|osg::StateAttribute::OVERRIDE );
	*/
    // switch off lighting as we haven't assigned any normals.
    root->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF);

    //The final step is to set up and enter a simulation loop.
    viewer.setSceneData( astro );
    viewer.setCameraManipulator(new osgGA::TrackballManipulator());
    viewer.realize();

    while( !viewer.done() )
    {
        viewer.frame();
    }

    return 0;
}

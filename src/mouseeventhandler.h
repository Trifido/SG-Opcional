#ifndef MOUSEEVENTHANDLER_H
#define MOUSEEVENTHANDLER_H

#include <osgGA/GUIEventHandler>
#include <osgViewer/Viewer>
#include <osgUtil/Optimizer>
#include <osg/io_utils>

class MouseEventHandler : public osgGA::GUIEventHandler {
    public:
	    MouseEventHandler(osgART::Scene* scene) : osgGA::GUIEventHandler() {_scene=scene;}
 		bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa);
 	protected:
 		osg::ref_ptr<osg::MatrixTransform> orbita;
};

#endif
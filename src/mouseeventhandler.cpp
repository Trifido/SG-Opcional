	#include "mouseeventhandler.h"

	bool MouseEventHandler::handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa) {
		if (ea.getEventType()!=osgGA::GUIEventAdapter::RELEASE ||
			ea.getButton()!=osgGA::GUIEventAdapter::LEFT_MOUSE_BUTTON ||
			!(ea.getModKeyMask()&osgGA::GUIEventAdapter::MODKEY_CTRL))
				return false;
	
		osgViewer::Viewer* viewer= dynamic_cast<osgViewer::Viewer*>(&aa);
		if (viewer) {
			osg::ref_ptr<osgUtil::LineSegmentIntersector> intersector=
			new osgUtil::LineSegmentIntersector(osgUtil::Intersector::WINDOW, ea.getX(), ea.getY());
			osgUtil::IntersectionVisitor iv(intersector.get());
			// Sólo recorrer aquellos nodos con nodeMask=0x1
			iv.setTraversalMask(~0x1);
			viewer->getCamera()->accept(iv);
			if (intersector->containsIntersections()) {
				//osgUtil::LineSegmentIntersector::Intersection& elegido= *(intersector->getIntersections().begin());
				//orbita= elegido.;
				//std::cout<<"ola k ase\n";
			// Hagamos lo que tengamos que hacer...
			}
		}
		return false;
	}

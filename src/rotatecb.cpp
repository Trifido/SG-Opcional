#include "rotatecb.h"

RotateCB::RotateCB(){
	edges[0] = 1;
	edges[1] = 1;
	edges[2] = 1;
	spd = 0.5;
}

RotateCB::RotateCB(float x, float y, float z){
	edges[0] = x;
	edges[1] = y;
	edges[2] = z;
	spd = 0.5;
}

RotateCB::RotateCB(float x, float y, float z, float speed){
	edges[0] = x;
	edges[1] = y;
	edges[2] = z;
	spd = speed;
}

void RotateCB::operator()( osg::Node* node, osg::NodeVisitor* nv){
	old = static_cast<osg::MatrixTransform*>(node);

	old->setMatrix(osg::Matrix(old->getMatrix() * osg::Matrix::rotate(spd * M_PI /180, edges[0], edges[1], edges[2]))); 

	traverse( node, nv );
}


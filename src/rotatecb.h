#ifndef ROTATECB_H
#define ROTATECB_H
#include <osg/Node>
#include <osg/NodeCallback>
#include <osg/MatrixTransform>
#include <cmath>

class RotateCB:public osg::NodeCallback{
public:
    RotateCB(); 
	RotateCB(float x, float y, float z);
	RotateCB(float x, float y, float z, float spd);
	virtual void operator()( osg::Node* node, osg::NodeVisitor* nv);
	void setSpeed(float speed){spd = speed;}
	float getSpeed(){return spd;}
protected:
	float spd;
	bool edges[3];
	osg::ref_ptr<osg::MatrixTransform> old;
};

#endif

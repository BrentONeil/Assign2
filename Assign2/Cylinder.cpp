#include "Cylinder.hpp"

#define PI 3.14159265

Cylinder::Cylinder() : Shape() {
	depth = 1;
	radius = 1;
	quad = gluNewQuadric();
	spinAngle = 0;
	steerAngle = 0;
}

Cylinder::Cylinder(double depth, double theta) : Shape() {
	this->depth = depth;
	this->radius = theta;
	quad = gluNewQuadric();
	steer = false;
	spin = false;
	spinAngle = 0;
	steerAngle = 0;
}

Cylinder::Cylinder(double x_, double y_, double z_, double depth, double theta) : Shape(x_, y_, z_) {
	this->depth = depth;
	this->radius = theta;
	quad = gluNewQuadric();
	steer = false;
	spin = false;
	spinAngle = 0;
	steerAngle = 0;
}

Cylinder::Cylinder(double x_, double y_, double z_, double depth, double theta, double rotation_) : Shape(x_, y_, z_, rotation_) {
	this->depth = depth;
	this->radius = theta;
	quad = gluNewQuadric();
	steer = false;
	spin = false;
	spinAngle = 0;
	steerAngle = 0;
}

Cylinder::~Cylinder(){
	gluDeleteQuadric(quad);
}

void Cylinder::draw() {
	rotation += steerAngle;
	glPushMatrix();
	positionInGL();
	glRotated(-spinAngle, 0, 0, 1);
	setColorInGL();
	glTranslated(0, 0, -depth*0.5);
	gluDisk(quad, 0, radius, 5, 1);
	gluCylinder(quad, radius, radius, depth, 5, 1);
	glPushMatrix();
	glTranslated(0, 0, depth);
	gluDisk(quad, 0, radius, 5, 1);
	glPopMatrix();
	glPopMatrix();

	rotation -= steerAngle;
}

ShapeInit Cylinder::params() {
	ShapeInit si = Shape::params();
	si.type = CYLINDER;
	si.params.cyl.radius = radius;
	si.params.cyl.depth = depth;
	si.params.cyl.isRolling = spin;
	si.params.cyl.isSteering = steer; //TODO: Implement rolling wheels
	return si;
}

void Cylinder::setWheel(Vehicle* v, bool steer, bool spin) {
	if (steer) {
		v->addSteer(this);
		this->steer = true;
	}
	if (spin) {
		v->addSpin(this);
		this->spin = true;
	}
}

void Cylinder::setSteer(double angle) {
	steerAngle = angle;
}

void Cylinder::addSpin(double speed, double dt) {
	spinAngle += speed * dt * 10;
}
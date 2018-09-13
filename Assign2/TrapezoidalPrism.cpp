#include "TrapezoidalPrism.hpp"

#include "windows.h"
#include "GL/GL.H"
#include "GL/GLU.H"

TrapezoidalPrism::TrapezoidalPrism() : Shape() {
	al = 1;
	bl = 1;
	depth = 1;
	ao = 0;
	height = 1;
}

TrapezoidalPrism::TrapezoidalPrism(double al, double bl, double ao, double depth, double height) : Shape() {
	this->al = al;
	this->bl = bl;
	this->depth = depth;
	this->ao = ao;
	this->height = height;
}

TrapezoidalPrism::TrapezoidalPrism(double x_, double y_, double z_, double al, double bl, double ao, double depth, double height) : Shape(x_, y_, z_) {
	this->al = al;
	this->bl = bl;
	this->depth = depth;
	this->ao = ao;
	this->height = height;
}

TrapezoidalPrism::TrapezoidalPrism(double x_, double y_, double z_, double al, double bl, double ao, double depth, double height, double rotation_) : Shape(x_, y_, z_, rotation_) {
	this->al = al;
	this->bl = bl;
	this->depth = depth;
	this->ao = ao;
	this->height = height;
}

void TrapezoidalPrism::draw() {

	glPushMatrix();
	positionInGL();
	setColorInGL();
	glBegin(GL_QUADS);
	//base
	glVertex3d( 0.5 * al, 0, z + 0.5*depth);
	glVertex3d(- 0.5 * al, 0, - 0.5*depth);
	glVertex3d(- 0.5 * al, 0, z - 0.5*depth);
	glVertex3d( 0.5 * al, 0, z - 0.5*depth);
	//top
	glVertex3d(- 0.5 * al + ao + bl, height, - 0.5*depth);
	glVertex3d(- 0.5 * al + ao, height, z + 0.5*depth);
	glVertex3d(- 0.5 * al + ao, height, z - 0.5*depth);
	glVertex3d(- 0.5 * al + ao + bl, height, z - 0.5*depth);
	//x+ side
	glVertex3d(- 0.5 * al + ao + bl, height, z + 0.5*depth);
	glVertex3d( 0.5 * al, 0, z + 0.5*depth);
	glVertex3d( 0.5 * al, 0, z - 0.5*depth);
	glVertex3d(- 0.5 * al + ao + bl, height, z - 0.5*depth);
	//x- side
	glVertex3d(- 0.5 * al + ao, height, z + 0.5*depth);
	glVertex3d(- 0.5 * al, 0, z + 0.5*depth);
	glVertex3d(- 0.5 * al, 0, z - 0.5*depth);
	glVertex3d(- 0.5 * al + ao, height, z - 0.5*depth);
	//z+ side
	glVertex3d(- 0.5 * al + ao + bl, height, z + 0.5*depth);
	glVertex3d( 0.5 * al, 0, z + 0.5*depth);
	glVertex3d(- 0.5 * al, 0, z + 0.5*depth);
	glVertex3d(- 0.5 * al + ao, height, z + 0.5*depth);
	//z- side
	glVertex3d(- 0.5 * al + ao + bl, height, z - 0.5*depth);
	glVertex3d( 0.5 * al, 0, z - 0.5*depth);
	glVertex3d(- 0.5 * al, 0, z - 0.5*depth);
	glVertex3d(- 0.5 * al + ao, height, z - 0.5*depth);

	glEnd();
	glPopMatrix();
}

ShapeInit TrapezoidalPrism::params() {
	ShapeInit si = Shape::params();
	si.type = TRAPEZOIDAL_PRISM;
	si.params.trap.alen = al;
	si.params.trap.aoff = ao;
	si.params.trap.blen = bl;
	si.params.trap.depth = depth;
	si.params.trap.height = height;
	return si;
}
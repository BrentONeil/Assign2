#include "TriangularPrism.hpp"
#include <cmath>

#include "windows.h"
#include "GL/GL.H"
#include "GL/GLU.H"

#define PI 3.14159265

TriangularPrism::TriangularPrism() : Shape() {
	al = 1;
	bl = 1;
	depth = 1;
	theta = 90;
}

TriangularPrism::TriangularPrism(double al, double bl, double depth, double theta) : Shape() {
	this->al = al;
	this->bl = bl;
	this->depth = depth;
	this->theta = theta;
}

TriangularPrism::TriangularPrism(double x_, double y_, double z_, double al, double bl, double depth, double theta) : Shape(x_, y_, z_) {
	this->al = al;
	this->bl = bl;
	this->depth = depth;
	this->theta = theta;
}

TriangularPrism::TriangularPrism(double x_, double y_, double z_, double al, double bl, double depth, double theta, double rotation_) : Shape(x_, y_, z_, rotation_) {
	this->al = al;
	this->bl = bl;
	this->depth = depth;
	this->theta = theta;
}

void TriangularPrism::draw() {
	x = Shape::x;
	y = Shape::y;
	z = Shape::z;


	glPushMatrix();
	positionInGL();
	setColorInGL();
	glBegin(GL_QUADS);
	//Base
	glVertex3d( 0.5 * al, 0,  0.5*depth);
	glVertex3d( 0.5 * al, 0, - 0.5*depth);
	glVertex3d(- 0.5 * al, 0, - 0.5*depth);
	glVertex3d(- 0.5 * al, 0,  0.5*depth);
	//Front
	glVertex3d( 0.5 * al, 0,  0.5*depth);
	glVertex3d( 0.5 * al, 0, - 0.5*depth);
	glVertex3d(
		- 0.5 * al + bl*cos(theta * PI / 180), 
		 bl*sin(theta * PI / 180),
		- 0.5*depth);
	glVertex3d(
		- 0.5 * al + bl * cos(theta * PI / 180),
		 bl * sin(theta * PI / 180),
		 0.5*depth);
	//
	//
	//Back
	glVertex3d(- 0.5 * al, 0, - 0.5*depth);
	glVertex3d(- 0.5 * al, 0,  0.5*depth);
	glVertex3d(
		- 0.5 * al + bl * cos(theta * PI / 180),
		 bl * sin(theta * PI / 180),
		- 0.5*depth);
	glVertex3d(
		- 0.5 * al + bl * cos(theta * PI / 180),
		 bl * sin(theta * PI / 180),
		 0.5*depth);

	glEnd();
	glBegin(GL_TRIANGLES);
	//Front
	glVertex3d( 0.5 * al, 0,  0.5*depth);
	glVertex3d(- 0.5 * al, 0,  0.5*depth);
	glVertex3d(
		- 0.5 * al + bl * cos(theta * PI / 180),
		 bl * sin(theta * PI / 180),
		 0.5*depth);
	//Back
	glVertex3d( 0.5 * al, 0, - 0.5*depth);
	glVertex3d(- 0.5 * al, 0, - 0.5*depth);
	glVertex3d(
		- 0.5 * al + bl * cos(theta * PI / 180),
		 bl * sin(theta * PI / 180),
		- 0.5*depth);

	glEnd();
	glPopMatrix();
}

ShapeInit TriangularPrism::params() {
	ShapeInit si = Shape::params();
	si.type = TRIANGULAR_PRISM;
	si.params.tri.alen = al;
	si.params.tri.angle = theta;
	si.params.tri.blen = bl;
	si.params.tri.depth = depth;
	return si;
}
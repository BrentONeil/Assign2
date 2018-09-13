#include "RectangularPrism.hpp"
#include "Messages.hpp"

#include "windows.h"
#include "GL/GL.H"
#include "GL/GLU.H"

RectangularPrism::RectangularPrism() : Shape(){
	xl = 1;
	yl = 1;
	zl = 1;
}

RectangularPrism::RectangularPrism(double xl, double yl, double zl) : Shape() {
	this->xl = xl;
	this->yl = yl;
	this->zl = zl;
}

RectangularPrism::RectangularPrism(double x_, double y_, double z_, double xl, double yl, double zl) : Shape(x_, y_, z_) {
	this->xl = xl;
	this->yl = yl;
	this->zl = zl;
}

RectangularPrism::RectangularPrism(double x_, double y_, double z_, double xl, double yl, double zl, double rotation_) : Shape(x_, y_, z_, rotation_){
	this->xl = xl;
	this->yl = yl;
	this->zl = zl;
}

void RectangularPrism::draw() {
	double yt = y + yl;
	glPushMatrix();
	positionInGL();
	setColorInGL();
	glBegin(GL_QUADS);

	glVertex3d( 0.5*xl, yl, 0.5 * zl);
	glVertex3d(- 0.5*xl, yl, 0.5 * zl);	
	glVertex3d(- 0.5*xl, 0, 0.5 * zl);
	glVertex3d( 0.5*xl, 0, 0.5 * zl);
	
	glVertex3d(0.5*xl, yl, - 0.5 * zl);
	glVertex3d( 0.5*xl, 0, - 0.5 * zl);
	glVertex3d(- 0.5*xl, 0, - 0.5 * zl);
	glVertex3d(- 0.5*xl, yl, - 0.5 * zl);

	glVertex3d( 0.5*xl, yl, 0.5 * zl);
	glVertex3d( 0.5*xl, 0, 0.5 * zl);
	glVertex3d( 0.5*xl, 0, - 0.5 * zl);
	glVertex3d( 0.5*xl, yl, - 0.5 * zl);

	glVertex3d(- 0.5*xl, yl, 0.5 * zl);
	glVertex3d(- 0.5*xl, 0, 0.5 * zl);
	glVertex3d(- 0.5*xl, 0, - 0.5 * zl);
	glVertex3d(- 0.5*xl, yl, - 0.5 * zl);

	glVertex3d( 0.5*xl, yl, 0.5 * zl);
	glVertex3d(- 0.5*xl, yl, 0.5 * zl);
	glVertex3d(- 0.5*xl, yl, - 0.5 * zl);
	glVertex3d( 0.5*xl, yl, - 0.5 * zl);

	glVertex3d( 0.5*xl, 0.0f, 0.5 * zl);
	glVertex3d(- 0.5*xl, 0.0f, 0.5 * zl);
	glVertex3d(- 0.5*xl, 0.0f, - 0.5 * zl);
	glVertex3d( 0.5*xl, 0.0f, - 0.5 * zl);

	glEnd();
	glPopMatrix();
	return;
}

ShapeInit RectangularPrism::params() {
	ShapeInit si = Shape::params();
	si.type = RECTANGULAR_PRISM;
	si.params.rect.xlen = xl;
	si.params.rect.ylen = yl;
	si.params.rect.zlen = zl;
	return si;
}
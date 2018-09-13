#include "Truck.hpp"
#include "RectangularPrism.hpp"
#include "Cylinder.hpp"
#include "Messages.hpp"
#include "TrapezoidalPrism.hpp"
#include "Shape.hpp"
#include "windows.h"
#include "GL/GL.H"
#include "GL/GLU.H"


Truck::Truck() : Vehicle(){
	Cylinder * FrontWheel = new Cylinder(5,2,0,5,2);
	FrontWheel->setWheel(this, true, true);
	FrontWheel->setColor(0.5, 0.5, 0.5);
	addShape(FrontWheel);

	Cylinder * BackWheel = new Cylinder(-5, 2, 0, 5, 2);
	BackWheel->setWheel(this, false, true);
	BackWheel->setColor(0, 1, 0);
	addShape(BackWheel);

	RectangularPrism * BottomBody = new RectangularPrism(0.0, 3.0, 0.0, 3.0, 1.5, 1.0);
	BottomBody-> setColor(1, 0, 0);
	addShape(BottomBody);
	
	
	/*	Cylinder * FrontWheel = new Cylinder(1.1,2,0,5,2);
	FrontWheel->setWheel(this, true, true);
	FrontWheel->setColor(14, 14, 14);
	addShape(FrontWheel);

	Cylinder * BackWheel = new Cylinder(-5, 2, 0, 5, 2);
	BackWheel->setWheel(this, true, true);
	BackWheel->setColor(14, 14, 14);
	addShape(BackWheel);

	RectangularPrism * BottomBody = new RectangularPrism(0, 3, 0, 11, 0.1, 5);
	BottomBody-> setColor(82, 0, 0);
	addShape(BottomBody);
	*/

}

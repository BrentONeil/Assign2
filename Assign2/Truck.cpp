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
	
	Cylinder * FrontRightWheel = new Cylinder(1.1,0.4,1.1,0.1,0.4);
	FrontRightWheel->setWheel(this, true, true);
	FrontRightWheel->setColor(1.0, 0, 0);
	addShape(FrontRightWheel);

	Cylinder * FrontLeftWheel = new Cylinder(1.1,0.4,-1.1,0.1,0.4);
	FrontLeftWheel->setWheel(this, true, true);
	FrontLeftWheel->setColor(1.0, 0, 0);
	addShape(FrontLeftWheel);

	Cylinder * BackRightWheel = new Cylinder(-1.1,0.8,1.1,0.1,0.8);
	BackRightWheel->setWheel(this, true, true);
	BackRightWheel->setColor(0, 0, 1.0);
	addShape(BackRightWheel);

	Cylinder * BackLeftWheel = new Cylinder(-1.1, 0.8, -1.1, 0.1, 0.8);
	BackLeftWheel->setWheel(this, true, true);
	BackLeftWheel->setColor(0, 0, 1.0);
	addShape(BackLeftWheel);

	RectangularPrism * BottomBody = new RectangularPrism(0, 0.4, 0, 3, 1, 2);
	BottomBody-> setColor(0, 0.6, 0);
	addShape(BottomBody);
	

}

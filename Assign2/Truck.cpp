#include "Truck.hpp"
#include "RectangularPrism.hpp"
#include "Cylinder.hpp"
#include "Messages.hpp"
#include "Shape.hpp"
#include "windows.h"
#include "GL/GL.H"
#include "GL/GLU.H"


Truck::Truck() : Vehicle(){
	Cylinder * c = new Cylinder();
	c->setWheel(this, true, true);
	addShape(c);
	//addShape(new RectangularPrism(1,0.5,0,3, 1,1));
}

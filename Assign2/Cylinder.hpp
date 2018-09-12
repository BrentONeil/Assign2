#pragma once
#include "Shape.hpp"
#include "windows.h"
#include "GL/GL.H"
#include "GL/GLU.H"
#include "Messages.hpp"
#include "Vehicle.hpp"

class Cylinder : public Shape {
public:
	Cylinder();
	Cylinder(double depth, double radius);
	Cylinder(double x_, double y_, double z_, double depth, double radius);
	Cylinder(double x_, double y_, double z_, double depth, double radius, double rotation_);

	void setWheel(Vehicle* v, bool steer, bool spin);
	void setSteer(double angle);
	void addSpin(double speed, double dt);
	~Cylinder();
	void draw();
	
	ShapeInit params();


private:
	GLUquadric* quad;
	double depth, radius;
	bool steer, spin;
	double spinAngle;
	double steerAngle;

};
#pragma once
#include "Shape.hpp"
#include "Messages.hpp"

class TriangularPrism : public Shape {
public:
	TriangularPrism();
	TriangularPrism(double al, double bl, double depth, double theta);
	TriangularPrism(double x_, double y_, double z_, double al, double bl, double depth, double theta);
	TriangularPrism(double x_, double y_, double z_, double al, double bl, double depth, double theta, double rotation_);

	void draw();

	ShapeInit params();
private:

	double al, bl, depth, theta;

};
#pragma once
#include "Shape.hpp"
#include "Messages.hpp"

class RectangularPrism : public Shape {
public:
	RectangularPrism();
	RectangularPrism(double xl, double yl, double zl);
	RectangularPrism(double x_, double y_, double z_, double xl, double yl, double zl);
	RectangularPrism(double x_, double y_, double z_, double xl, double yl, double zl, double rotation_);

	void draw();

	ShapeInit params();
private:

	double xl, yl, zl;

};
#pragma once
#include "Shape.hpp"
#include "Messages.hpp"

class TrapezoidalPrism : public Shape {
public:
	TrapezoidalPrism();
	TrapezoidalPrism(double al, double bl, double ao, double depth, double height);
	TrapezoidalPrism(double x_, double y_, double z_, double al, double bl, double ao, double depth, double height);
	TrapezoidalPrism(double x_, double y_, double z_, double al, double bl, double ao, double depth, double height, double rotation_);

	void draw();

	ShapeInit params();

private:

	double al, bl, ao, depth, height;

};
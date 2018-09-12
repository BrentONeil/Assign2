
#ifndef MTRN3500_VEHICLE_H
#define MTRN3500_VEHICLE_H

#include <iostream>
#include "Shape.hpp"
#include "VectorMaths.hpp"

#include <vector>
class Cylinder;

class Vehicle : public Shape {
	friend void remoteDriver(Vehicle * vehicle, double x, double z, double r, double speed_, double steering_);
public:

	Vehicle();
	virtual ~Vehicle();

	void update(double dt);
	void update(double speed_, double steering_, double dt);

	void draw();

	static const int MAX_FORWARD_SPEED_MPS = 10;
	static const int MAX_BACKWARD_SPEED_MPS = -4;
	static const int MAX_LEFT_STEERING_DEGS = 15;
	static const int MAX_RIGHT_STEERING_DEGS = -15;
	static const int VEHICLE_BOUNDS = 3;

	double getSpeed() const { return speed; }
	double getSteering() const { return steering; }

	void toVehicleModel(VehicleModel* vm);
	void addShape(Shape * shape);
	void addSteer(Cylinder* c);
	void addSpin(Cylinder* c);


	ShapeInit params();
protected:
	double speed;     // m/s
	double steering;  // degrees

	std::vector<Shape *> shapes;
	std::vector<Cylinder *> spin;
	std::vector<Cylinder *> steer;
};

double clamp(double a, double n, double b);

#endif // for MTRN3500_VEHICLE_H


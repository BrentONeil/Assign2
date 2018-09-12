#pragma once

#include "Truck.hpp"
#include "Messages.hpp"

class RemoteVehicle : public Vehicle {
public:
	RemoteVehicle(VehicleModel msg);
};
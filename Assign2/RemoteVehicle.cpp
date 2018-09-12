#pragma once
#include "RemoteVehicle.hpp"
#include "RectangularPrism.hpp"
#include "TriangularPrism.hpp"
#include "TrapezoidalPrism.hpp"
#include "Cylinder.hpp"

RemoteVehicle::RemoteVehicle(VehicleModel vm) : Vehicle() {
	Shape* s = NULL;
	ShapeParameter* sp = NULL;
	for (std::vector<ShapeInit>::iterator it = vm.shapes.begin(); it != vm.shapes.end(); it++) {
		sp = &(*it).params;
		if (it->type == RECTANGULAR_PRISM) {
			s = new RectangularPrism(sp->rect.xlen, sp->rect.ylen, sp->rect.zlen);
		}
		else if (it->type == TRIANGULAR_PRISM) {
			s = new TriangularPrism(sp->tri.alen, sp->tri.blen, sp->tri.depth, sp->tri.angle);
		}
		else if (it->type == CYLINDER) {
			s = new Cylinder(sp->cyl.depth, sp->cyl.radius);
			if (sp->cyl.isRolling) {
				((Cylinder*)s)->setWheel(this, false, true);
			}
			if (sp->cyl.isSteering) {
				((Cylinder*)s)->setWheel(this, true, false);
			}
		}
		else if (it->type == TRAPEZOIDAL_PRISM) {
			s = new TrapezoidalPrism(sp->trap.alen, sp->trap.blen, sp->trap.aoff, sp->trap.depth, sp->trap.height);
		}

		if (s != NULL) {
			s->setPosition(it->xyz[0], it->xyz[1], it->xyz[2]);
			s->setRotation(it->rotation);
			s->setColor(it->rgb[0], it->rgb[1], it->rgb[2]);
			addShape(s);
		}
		s = NULL;
		
	}
}
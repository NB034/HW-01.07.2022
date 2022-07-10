#pragma once
#include "AirVehicle.h"

class Plane :public AirVehicle {
	double wingspan;
public:
	Plane(int maxSpeed, const std::string& model, int cntPass, const std::string& color, double maxHeight, double wingspan);
	void setWingspan(double wingspan);
	double getWingspan() const { return this->wingspan; }
	void info() const;
};



Plane::Plane(int maxSpeed, const std::string& model, int cntPass, const std::string& color, double maxHeight, double wingspan)
	:AirVehicle(maxSpeed, model, cntPass, color, maxHeight) {
	this->setWingspan(wingspan);
}

void Plane::setWingspan(double wingspan) {
	if (wingspan < 0)
		wingspan = 1;
	this->wingspan = wingspan;
}

void Plane::info() const {
	AirVehicle::info();
	std::cout << "Wingspan: " << this->wingspan << std::endl;
}
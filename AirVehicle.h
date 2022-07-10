#pragma once
#include "Vehicles.h"

class AirVehicle :public Vehicles {
	double maxHeight;
public:
	AirVehicle(int maxSpeed, const std::string& model, int cntPass, const std::string& color, double maxHeight);
	void setMaxHeight(double maxHeight);
	double getMaxHeight() const { return this->maxHeight; }
	void info() const;
};



AirVehicle::AirVehicle(int maxSpeed, const std::string& model, int cntPass, const std::string& color, double maxHeight)
	:Vehicles(maxSpeed, model, cntPass, color) {
	this->setMaxHeight(maxHeight);
}

void AirVehicle::setMaxHeight(double maxHeight) {
	if (maxHeight < 0)
		maxHeight = 0;
	this->maxHeight = maxHeight;
}

void AirVehicle::info() const {
	Vehicles::info();
	std::cout << "Max height: " << this->maxHeight << std::endl;
}
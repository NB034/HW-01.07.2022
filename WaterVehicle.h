#pragma once
#include "Vehicles.h"

class WaterVehicle :public Vehicles {
	double surfaceWaterDisplacement;
public:
	WaterVehicle(int maxSpeed, const std::string& model, int cntPass, const std::string& color, double waterDm);
	void setWaterDisplacement(double waterDm);
	double getWaterDisplacement() const { return this->surfaceWaterDisplacement; }
	void info() const;
};



WaterVehicle::WaterVehicle(int maxSpeed, const std::string& model, int cntPass, const std::string& color, double waterDm) 
	:Vehicles(maxSpeed, model, cntPass, color) {
	this->setWaterDisplacement(waterDm);
}

void WaterVehicle::setWaterDisplacement(double waterDm) {
	if (waterDm < 0)
		waterDm = 100;
	this->surfaceWaterDisplacement = waterDm;
}

void WaterVehicle::info() const {
	Vehicles::info();
	std::cout << "Water displacement: " << this->surfaceWaterDisplacement << std::endl;
}
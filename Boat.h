#pragma once
#include "WaterVehicle.h"

class Boat :public WaterVehicle {
	double sideHeight;
public:
	Boat(int maxSpeed, const std::string& model, int cntPass, const std::string& color, double waterDm, double sideHt);
	void setSideHeight(double sideHt);
	double getSideHeight() const { return this->sideHeight; }
	void info() const;
};



Boat::Boat(int maxSpeed, const std::string& model, int cntPass, const std::string& color, double waterDm, double sideHt)
	:WaterVehicle(maxSpeed, model, cntPass, color, waterDm) {
	this->setSideHeight(sideHt);
}

void Boat::setSideHeight(double sideHt) {
	if (sideHt < 0)
		sideHt = 0.5;
	this->sideHeight = sideHt;
}

void Boat::info() const {
	WaterVehicle::info();
	std::cout << "Side height: " << this->sideHeight << std::endl;
}
#pragma once
#include "WaterVehicle.h"

class Submarine :public WaterVehicle {
	double underwaterDisplacement;
	double immersionDepth;
	int autonomousNavigation;
public:
	Submarine(int maxSpeed, const std::string& model, int cntPass, double waterDm, double uWaterDm, double imDepth, int autoNav);

	void setUnderwaterDisplacement(double uWaterDm);
	void setImmersionDepth(double imDepth);
	void setAutonomousNavigation(int autoNav);

	double getUnderwaterDisplacement() const { return this->underwaterDisplacement; }
	double getImmersionDepth() const { return this->immersionDepth; }
	int getAutonomousNavigation() const { return this->autonomousNavigation; }

	void info() const;

	void setColor(std::string& color) = delete;
};



Submarine::Submarine(int maxSpeed, const std::string& model, int cntPass, double waterDm, double uWaterDm, double imDepth, int autoNav)
	:WaterVehicle(maxSpeed, model, cntPass, "Yellow", waterDm) {
	this->setUnderwaterDisplacement(uWaterDm);
	this->setImmersionDepth(imDepth);
	this->setAutonomousNavigation(autoNav);
}

void Submarine::setUnderwaterDisplacement(double uWaterDm) {
	if (uWaterDm < 0)
		uWaterDm = 0;
	this->underwaterDisplacement = uWaterDm;
}

void Submarine::setImmersionDepth(double imDepth) {
	if (imDepth < 0)
		imDepth = 0;
	this->immersionDepth = imDepth;
}

void Submarine::setAutonomousNavigation(int autoNav) {
	if (autoNav < 0)
		autoNav = 0;
	this->autonomousNavigation = autoNav;
}

void Submarine::info() const {
	WaterVehicle::info();
	std::cout << "Underwater displacement: " << this->underwaterDisplacement << std::endl
		<< "Immersion depth: " << this->immersionDepth << std::endl
		<< "Autonomous navigation: " << this->autonomousNavigation << std::endl;

	std::cout << "\nWe all live in a yellow submarine\n"
		<< "Yellow submarine, yellow submarine\n";
}
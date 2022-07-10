#pragma once
#include "AirVehicle.h"

class Helicopter :public AirVehicle {
	double mainRotorDiameter;
public:
	Helicopter(int maxSpeed, const std::string& model, int cntPass, const std::string& color, double maxHeight, double mainRotor);
	void setMainRotorDiameter(double mainRotor);
	double getMainRotorDiameter() const { return this->mainRotorDiameter; }
	void info() const;
};



Helicopter::Helicopter(int maxSpeed, const std::string& model, int cntPass, const std::string& color, double maxHeight, double mainRotor)
	:AirVehicle(maxSpeed, model, cntPass, color, maxHeight) {
	this->setMainRotorDiameter(mainRotor);
}

void Helicopter::setMainRotorDiameter(double mainRotor) {
	if (mainRotor < 0)
		mainRotor = 1;
	this->mainRotorDiameter = mainRotor;
}

void Helicopter::info() const {
	AirVehicle::info();
	std::cout << "Main rotor diameter: " << this->mainRotorDiameter << std::endl;
}
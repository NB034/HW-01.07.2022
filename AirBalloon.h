#pragma once
#include "AirVehicle.h"

class AirBalloon :public AirVehicle {
	double shellVolume;
public:
	AirBalloon(int maxSpeed, const std::string& model, int cntPass, const std::string& color, double maxHeight, double sVol);
	void setShellVolume(double sVol);
	double getShellVolume() const { return this->shellVolume; }
	void info() const;
};



AirBalloon::AirBalloon(int maxSpeed, const std::string& model, int cntPass, const std::string& color, double maxHeight, double sVol)
	:AirVehicle(maxSpeed, model, cntPass, color, maxHeight) {
	this->setShellVolume(sVol);
}

void AirBalloon::setShellVolume(double sVol) {
	if (sVol < 0)
		sVol = 1;
	this->shellVolume = sVol;
}

void AirBalloon::info() const {
	AirVehicle::info();
	std::cout << "Shell volume: " << this->shellVolume << std::endl;
}
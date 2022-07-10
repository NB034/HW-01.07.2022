#pragma once
#include "Bus.h"

class Trolleybus :public Bus {
	double operatingVoltage;
public:
	Trolleybus(int maxSpeed, const std::string& model, int cntPass, const  std::string& color,
		Body bd, Engine eng, int diam, const std::vector <std::string>& route, double voltage);
	void setVoltage(double voltage);
	double getVoltage() const { return this->operatingVoltage; }
	void info() const;
};



Trolleybus::Trolleybus(int maxSpeed, const std::string& model, int cntPass, const  std::string& color,
	Body bd, Engine eng, int diam, const std::vector <std::string>& route, double voltage)
	:Bus(maxSpeed, model, cntPass, color, bd, eng, diam, route) {
	this->setVoltage(voltage);
}

void Trolleybus::setVoltage(double voltage) {
	if (voltage < 0)
		voltage = 400;
	this->operatingVoltage = voltage;
}

void Trolleybus::info() const {
	Bus::info();
	std::cout << "Operating voltage: " << this->operatingVoltage << std::endl;
}
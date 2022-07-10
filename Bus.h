#pragma once
#include "Car.h"
#include <vector>

class Bus :public Car {
	std::vector <std::string> route;
public:
	Bus(int maxSpeed, const  std::string& model, int cntPass, const  std::string& color, Body bd, Engine eng, int diam, const std::vector <std::string>& route);
	void setRoute(std::vector <std::string> route);
	std::vector <std::string> getRoute() const { return this->route; }
	void print() const;
};



Bus::Bus(int maxSpeed, const std::string& model, int cntPass, const  std::string& color, Body bd, Engine eng, int diam, const std::vector <std::string>& route)
	:Car(maxSpeed, model, cntPass, color, Chassis(1), bd, eng, diam) {
	this->route = route;
}

void Bus::setRoute(std::vector <std::string> route) {
	this->route = route;
}

void Bus::print() const {
	Car::info();
	for (size_t i = 0; i < this->route.size(); i++)
		std::cout << this->route[i] << std::endl;
}
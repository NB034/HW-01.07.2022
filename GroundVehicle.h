#pragma once
#include "Vehicles.h"

enum class Chassis {
	crawler,
	wheeled,
	rail
};

class GroundVehicle :public Vehicles {
	Chassis type;
public:
	GroundVehicle(int maxSpeed, const  std::string& model, int cntPass, const  std::string& color, Chassis type);
	void setType(Chassis type);
	Chassis getType() const { return this->type; }
	void info() const;
};



GroundVehicle::GroundVehicle(int maxSpeed, const  std::string& model, int cntPass, const  std::string& color, Chassis type)
	:Vehicles(maxSpeed, model, cntPass, color) {
	this->type = type;
}

void GroundVehicle::setType(Chassis type) {
	this->type = type;
}

void GroundVehicle::info() const {
	Vehicles::info();
	std::cout << "Type:";
	switch (type) {
	case Chassis::crawler:
		std::cout << "crawler" << std::endl;
		break;
	case Chassis::wheeled:
		std::cout << "wheeled" << std::endl;
		break;
	case Chassis::rail:
		std::cout << "rail" << std::endl;
		break;
	default:
		break;
	}
}
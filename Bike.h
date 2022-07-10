#pragma once
#include "GroundVehicle.h"

enum class Type {
	Mountain,
	City,
	BMX
};

class BikeWheel {
	int diam;
public:
	BikeWheel(int diam = 26) { this->diam = diam; }
	void setDiam(int diam) { this->diam = diam; }
	int getDiam()const { return this->diam; }
};

class Bike :public GroundVehicle {
	BikeWheel wheels[2];
	Type tp;
	double weight;
public:
	Bike(int maxSpeed, const  std::string& model, int cntPass, const  std::string& color, Type tp, double weight, double diam = 26);

	void setDiam(double diam);
	void setType(Type tp);
	void setWeight(double weight);

	double getDiam() const { return this->wheels[0].getDiam(); }
	Type getType() const { return this->tp; }
	double getWeight() const { return this->weight; }

	void info() const;

	void setType(Chassis type) = delete;
};



Bike::Bike(int maxSpeed, const  std::string& model, int cntPass, const  std::string& color, Type tp, double weight = 15, double diam = 26)
	:GroundVehicle(maxSpeed, model, cntPass, color, Chassis(1)) {
	this->setDiam(diam);
	this->tp = tp;
	this->setWeight(weight);
}

void Bike::setDiam(double diam) {
	if (diam < 0)
		diam = 26;
	this->wheels[0].setDiam(diam);
	this->wheels[1].setDiam(diam);
}
void Bike::setType(Type tp) {
	this->tp = tp;
}
void Bike::setWeight(double weight) {
	if (weight < 0)
		weight = 15;
	this->weight = weight;
}

void Bike::info() const {
	GroundVehicle::info();
	std::cout << "Wheels' diameter: " << this->getDiam() << std::endl
		<< "Type: ";
	switch (this->tp) {
	case Type::Mountain:
		std::cout << "Mountain\n";
		break;
	case Type::City:
		std::cout << "City\n";
		break;
	case Type::BMX:
		std::cout << "BMX\n";
		break;
	default:
		break;
	}
	std::cout << "Weight: " << this->weight << std::endl;
}
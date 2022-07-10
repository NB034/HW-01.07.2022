#pragma once
#include "GroundVehicle.h"

enum class Body {
	sådan,
	coupe,
	wagon
};

enum class Engine {
	petrol,
	diesel,
	electro
};

class BikeWheel {
	int diam;
public:
	BikeWheel(int diam = 14) { this->diam = diam; }
	void setDiam(int diam) { this->diam = diam; }
	int getDiam()const { return this->diam; }
};

class Car :public GroundVehicle {
	BikeWheel s[4];
	Body bd;
	Engine eng;
public:
	Car(int maxSpeed, const  std::string& model, int cntPass, const  std::string& color, Chassis type, Body bd, Engine eng, int diam = 14);

	void setDiam(int diam);
	void setBody(Body bd);
	void setEngine(Engine eng);

	int getDiam() const { return this->s[0].getDiam(); }
	Body getBody() const { return this->bd; }
	Engine getEngine() const { return this->eng; }

	void info() const;

	void setType(Chassis type) = delete;
};



Car::Car(int maxSpeed, const  std::string& model, int cntPass, const  std::string& color, Chassis type, Body bd, Engine eng, int diam)
	:GroundVehicle(maxSpeed, model, cntPass, color, type) {
	this->bd = bd;
	this->eng = eng;
	this->setDiam(diam);
}

void Car::setDiam(int diam) {
	if (diam < 0)
		diam = 14;
	for (size_t i = 0; i < 4; i++)
		this->s[i].setDiam(diam);
}
void Car::setBody(Body bd) {
	this->bd = bd;
}
void Car::setEngine(Engine eng) {
	this->eng = eng;
}

void Car::info() const {
	GroundVehicle::info();
	std::cout << "Wheels' diameter: " << this->getDiam() << std::endl
		<< "Body type: ";
	switch (this->bd) {
	case Body::sådan:
		std::cout << "sedan" << std::endl;
		break;
	case Body::coupe:
		std::cout << "coupe" << std::endl;
		break;
	case Body::wagon:
		std::cout << "wagon" << std::endl;
		break;
	default:
		break;
	}
	std::cout << "Engine type: ";
	switch (this->eng)
	{
	case Engine::petrol:
		std::cout << "petrol" << std::endl;
		break;
	case Engine::diesel:
		std::cout << "diesel" << std::endl;
		break;
	case Engine::electro:
		std::cout << "electro" << std::endl;
		break;
	default:
		break;
	}
}
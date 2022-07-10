#pragma once
#include "GroundVehicle.h"

class Train :public GroundVehicle {
	int numberOfWagons;
	int serviceLife;
public:
	Train(int maxSpeed, const  std::string& model, int cntPass, const  std::string& color, int numberOfWagons, int serviceLife);

	void setNumberOfWagons(int numberOfWagons);
	void setServiceLife(int serviceLife);

	int getNumberOfWagons() const { return this->numberOfWagons; }
	int getServiceLife() const { return this->serviceLife; }

	void info() const;

	void setType(Chassis type) = delete;
};



Train::Train(int maxSpeed, const  std::string& model, int cntPass, const  std::string& color, int numberOfWagons, int serviceLife)
	:GroundVehicle(maxSpeed, model, cntPass, color, Chassis(2)) {
	this->setNumberOfWagons(numberOfWagons);
	this->setServiceLife(serviceLife);
}

void Train::setNumberOfWagons(int numberOfWagons) {
	if (numberOfWagons < 0)
		numberOfWagons = 0;
	this->numberOfWagons = numberOfWagons;
}

void Train::setServiceLife(int serviceLife) {
	if (serviceLife < 0)
		serviceLife = 5;
	this->serviceLife = serviceLife;
}

void Train::info() const {
	GroundVehicle::info();
	std::cout << "Number of wagons: " << this->numberOfWagons << std::endl
		<< "Service life: " << this->serviceLife << std::endl;
}
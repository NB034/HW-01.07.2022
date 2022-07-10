#pragma once
#include <iostream>
#include <string>

class Vehicles {
	int maxSpeed;
	int cntPass;
	std::string model;
	std::string color;
public:
	Vehicles(int maxSpeed, const std::string& model, int cntPass, const std::string& color);

	void setMaxSpeed(int maxSpeed);
	void setCntPass(int cntPass);
	void setModel(std::string& model);
	void setColor(std::string& color);

	int getMaxSpeed() const { return this->maxSpeed; }
	int getCntPass() const { return this->cntPass; }
	std::string getModel() const { return this->model; }
	std::string getColor() const { return this->color; }

	void info() const;
};



Vehicles::Vehicles(int maxSpeed, const std::string& model, int cntPass, const std::string& color) {
	this->cntPass = cntPass;
	this->color = color;
	this->maxSpeed = maxSpeed;
	this->model = model;
}

void Vehicles::setMaxSpeed(int maxSpeed) {
	this->maxSpeed = maxSpeed;
}
void Vehicles::setCntPass(int cntPass) {
	this->cntPass = cntPass;
}
void Vehicles::setModel(std::string& model) {
	this->model = model;
}
void Vehicles::setColor(std::string& color) {
	this->color = color;
}

void Vehicles::info() const {
	std::cout << "Model: " << this->model << std::endl
		<< "Color: " << this->color << std::endl
		<< "Max amount of passengers: " << this->cntPass << std::endl
		<< "Max speed: " << this->maxSpeed << std::endl;
}
#include "Sport.h"

Sport::Sport(string name, double fee){
	this->name = name;
	this->fee = fee;
}

void Sport::setName(string name){
	this->name = name;
}
void Sport::setFee(double fee){
	this->fee = fee;
}
string Sport::getName(){
	return this->name;
}
double Sport::getFee(){
	return this->fee;
}

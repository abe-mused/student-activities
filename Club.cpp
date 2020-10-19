#include "Club.h"

Club::Club(){
	this->name = "NONE";
	this->meetingDay = " ";
}
Club::Club(string name, string meetingDay){
	this->name = name;
	this->meetingDay = meetingDay;
}

void Club::setName(string name){
	this->name = name;
}
void Club::setMeetingDay(string meetingDay){
	this->meetingDay = meetingDay;
}
string Club::getName(){
	return this->name;
}
string Club::getMeetingDay(){
	return this->meetingDay;
}

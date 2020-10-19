#include "StudentActivity.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

StudentActivity::StudentActivity(string sportName, double sportFee, string clubOneName, string clubOneMettingDay, string clubTwoName, string clubTwoMettingDay,
 int studentId, string studentName): sport(sportName, sportFee), clubOne(clubOneName, clubOneMettingDay), 
 clubTwo(clubTwoName, clubTwoMettingDay){
	this->studentId = studentId;
	this->studentName = studentName;
	this->totalAmountDue = 0;
}

double StudentActivity::calcTotalDue(){
	this->totalAmountDue += this->sport.getFee();
	
	if(clubOne.getName() != "NONE")
		this->totalAmountDue += 55.5;
	if(clubTwo.getName() != "NONE")
		this->totalAmountDue += 35.5;
	
	return this->totalAmountDue;
}

void StudentActivity::displayActivities(){
	cout<<setprecision(2)<<fixed;
	system("cls");
	cout<<endl<<this->studentId<<" "<<this->studentName<<endl<<endl;
	if(sport.getName()!=""){
	cout<<sport.getName()<<" $"<<sport.getFee()<<endl;	
	} else {
		cout<<"you have not registered for any sports."<<endl;
	}
	
	if(clubOne.getName() != "NONE")
	cout<<clubOne.getName()<<" meets on "<<clubOne.getMeetingDay()<<endl;
	if(clubTwo.getName() != "NONE")
	cout<<clubTwo.getName()<<" meets on "<<clubTwo.getMeetingDay()<<endl;
	
	cout<<endl<<"total due is $"<<calcTotalDue()<<endl;
}

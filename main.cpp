#include <iostream>
#include <vector>
#include <iomanip>
#include "Sport.h"
#include "Club.h"
#include "StudentActivity.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
Sport determineSport();
Club determineClub();

int main(int argc, char** argv) {
	cout<<setprecision(2)<<fixed;
	string studentName, sportName = "";
	double sportFees = 0;
	int studentID;
	Club clubOne, clubTwo;
	string registerForSport, joinAClub, joinAnotherClub;
	
	cout<<"Welcome to student actiivities!"<<endl<<"please enter your full name: "<<endl;
	cin>>studentName;
	cout<<"please enter your student ID: "<<endl;
	cin>>studentID;
	
	cout<<"would you like to register for a sport? Y/N"<<endl;
	cin>>registerForSport;
	while(registerForSport!= "y" && registerForSport!= "Y" && registerForSport!= "n" && registerForSport!= "N"){
		cout<<"please enter Y or N"<<endl;
		cin>>registerForSport;
	}
	if(registerForSport == "y" || registerForSport == "Y"){
		Sport tempSport = determineSport();
		sportName = tempSport.getName();
		sportFees = tempSport.getFee();
	}
	
	cout<<endl<<"would you like to join a club? Y/N"<<endl;
	cin>>joinAClub;
	while(joinAClub!= "y" && joinAClub!= "Y" && joinAClub!= "n" && joinAClub!= "N"){
		cout<<"please enter Y or N"<<endl;
		cin>>joinAClub;
	}
	if(joinAClub == "y" || joinAClub == "Y"){
		clubOne = determineClub();
		cout<<endl<<"would you like to join another club? Y/N"<<endl;
		cin>>joinAnotherClub;
		while(joinAnotherClub!= "y" && joinAnotherClub!= "Y" && joinAnotherClub!= "n" && joinAnotherClub!= "N"){
			cout<<"please enter Y or N"<<endl;
			cin>>joinAnotherClub;
		}
		if(joinAnotherClub == "y" || joinAnotherClub == "Y"){
			clubTwo = determineClub();
			while(clubOne.getMeetingDay() == clubTwo.getMeetingDay()){
				int clubToReplace;
				cout<<"you may not join the two clubs meeting on the same day"<<endl;
				cout<<"which club would you like to replace? 1 or 2"<<endl;
				cin>>clubToReplace;
					while(clubToReplace != 1 && clubToReplace != 2){
						cout<<"enter 1 or 2"<<endl;
						cin>>clubToReplace;
					}
				switch(clubToReplace){
					
					case 1:
						clubOne = determineClub();
						break;
					case 2:
						clubTwo = determineClub();
						break;
					default:
						cout<<"error, club not found"<<endl;
				}
			}
		}
	}
	
	StudentActivity studentActivity(sportName, sportFees, clubOne.getName(), clubOne.getMeetingDay(), clubTwo.getName(), clubTwo.getMeetingDay(),
	studentID, studentName);
	
	studentActivity.displayActivities();
	return 0;
}

Sport determineSport(){
	vector<string> sportNames = {"Baseball", "Soccer", "Football", "Swimming"};
	vector<double> sportFees = {525.00, 450.00, 610.00, 375.00};
	int chosenSportNumber;
	
	for(int x=0; x<sportNames.size(); x++){
		cout<<x+1<<") "<<sportNames.at(x)<<"   $"<<sportFees.at(x)<<endl;
	}
	cout<<"please enter the number of the sport you'd like to choose: "<<endl;
	cin>>chosenSportNumber;
	
	return Sport(sportNames.at(chosenSportNumber-1), sportFees.at(chosenSportNumber-1));
}

Club determineClub(){
	vector<string> clubNames = {"Anime", "Chess", "Engineering", "Programming", "Aviation", "CyberPatriot", "Enterpreneurship", "Robotics"};
	vector<string> meetingDays = {"Wednesday", "Thursday", "Monday", "Tuesday", "Wednesday", "Monday", "Thursday", "Friday"};
	int chosenClubNumber;
	
	for(int x=0; x<clubNames.size(); x++){
		cout<<x+1<<") "<<clubNames.at(x)<<"   "<<meetingDays.at(x)<<endl;
	}
	cout<<"please enter the number of the club you'd like to choose: "<<endl;
	cin>>chosenClubNumber;
	
	return Club(clubNames.at(chosenClubNumber-1), meetingDays.at(chosenClubNumber-1));
}

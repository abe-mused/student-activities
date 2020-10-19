#ifndef STUDENTACTIVITY_H
#define STUDENTACTIVITY_H
#include "Club.h"
#include "Sport.h"
#include <string>
using namespace std;

class StudentActivity
{
	private:
		int studentId;
		string studentName;
		Sport sport;
		Club clubOne, clubTwo;
		double totalAmountDue;	
	public:
		StudentActivity(string, double, string, string, string, string, int, string);
		double calcTotalDue();
		void displayActivities();
};

#endif

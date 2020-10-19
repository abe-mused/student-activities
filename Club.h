#ifndef CLUB_H
#define CLUB_H
#include <string>
using namespace std;

class Club
{
	private:
		string name, meetingDay;
	public:
		Club();
		Club(string, string);
		void setName(string);
		void setMeetingDay(string);
		string getName();
		string getMeetingDay();
};

#endif

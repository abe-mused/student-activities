#ifndef SPORT_H
#define SPORT_H
#include <string>
using namespace std;

class Sport
{
	private:
		string name;
		double fee;
	public:
		Sport(string, double);
		void setName(string);
		void setFee(double);
		string getName();
		double getFee();
};

#endif

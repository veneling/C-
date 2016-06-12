#pragma once
#include <string>
#include <vector>
#include "Building.h"
using namespace std;

class BPStatistics
{
private:
	vector <Building> buildings;
public:
	BPStatistics(vector <Building> buildings);
	~BPStatistics();
	vector <Building> *getBuildings();
	void setBuildings(vector <Building> buildings);
	void getMostEmployees();
	void getMostFreePlaces();
	void highestCoefEmpl();
	void getMostPeoplePerFloor();
	void getLeastPeoplePerFloor();
	void getMostOfficesPerFloor();
	void getLeastOfficesPerFloor();
	void getMostPeoplePerOffice();
	void getLeastPeoplePerOffice();
};
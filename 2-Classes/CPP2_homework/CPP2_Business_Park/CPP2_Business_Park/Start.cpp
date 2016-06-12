#include "Building.h"
#include "BusinessParkStatistics.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	Building b1;
	b1.setCompany("XYZ industries");
	b1.setNumberOfFloors(6);
	b1.setNumberOfOffices(127);
	b1.setNumberOfEmployees(600);
	b1.setNumberOfFreeWorkingSeats(196);

	Building b2;
	b2.setCompany("Rapid Development Crew");
	b2.setNumberOfFloors(8);
	b2.setNumberOfOffices(210);
	b2.setNumberOfEmployees(822);
	b2.setNumberOfFreeWorkingSeats(85);
	b2.setRestaurants(1);

	Building b3;
	b3.setCompany("SoftUni");
	b3.setNumberOfFloors(11);
	b3.setNumberOfOffices(106);
	b3.setNumberOfEmployees(200);
	b3.setNumberOfFreeWorkingSeats(60);

	BPStatistics bpark({ b1, b2, b3 });

	bpark.getMostEmployees();
	bpark.getMostFreePlaces();
	bpark.getMostPeoplePerFloor();
	bpark.getLeastPeoplePerFloor();
	bpark.getMostOfficesPerFloor();
	bpark.getLeastOfficesPerFloor();
	bpark.getMostPeoplePerOffice();
	bpark.getLeastPeoplePerOffice();
	bpark.highestCoefEmpl();
	system("PAUSE");
	return 0;
}
#pragma once
#include <string>
using namespace std;

class Building
{
private:
	string company;
	int	numberOfFloors, numberOfOffices, numberOfEmployees, numberOfFreeWorkingSeats, restaurants;
public:
	Building();
	~Building();
	string getCompany();
	void setCompany(string company);
	int getNumberOfFloors();
	void setNumberOfFloors(int numberOfFloors);
	int getNumberOfOffices();
	void setNumberOfOffices(int numberOfOffices);
	int getNumberOfEmployees();
	void setNumberOfEmployees(int numberOfEmployees);
	int getNumberOfFreeWorkingSeats();
	void setNumberOfFreeWorkingSeats(int numberOfFreeWorkingSeats);
	int getRestaurants();
	void setRestaurants(int restaurants);
};
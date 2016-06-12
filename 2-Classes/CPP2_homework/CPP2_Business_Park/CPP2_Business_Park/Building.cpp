#include "Building.h"
#include <iostream>
#include <string>
using namespace std;

Building::Building()
{
}

Building::~Building()
{
}

string Building::getCompany()
{
	return company;
}

void Building::setCompany(string company)
{
	if (!company.empty()) 
	{
		this->company = company;
	}
	else
	{
		cout << "The company string cannot be empty" << endl;
	}
}

int Building::getNumberOfFloors()
{
	return numberOfFloors;
}

void Building::setNumberOfFloors(int numberOfFloors)
{
	(*this).numberOfFloors = numberOfFloors;
}

int Building::getNumberOfOffices()
{
	return this->numberOfOffices;
}

void Building::setNumberOfOffices(int numberOfOffices)
{
	this->numberOfOffices = numberOfOffices;
}

int Building::getNumberOfEmployees()
{
	return this->numberOfEmployees;
}

void Building::setNumberOfEmployees(int numberOfEmployees)
{
	this->numberOfEmployees = numberOfEmployees;
}

int Building::getNumberOfFreeWorkingSeats()
{
	return this->numberOfFreeWorkingSeats;
}

void Building::setNumberOfFreeWorkingSeats(int numberOfFreeWorkingSeats)
{
	this->numberOfFreeWorkingSeats = numberOfFreeWorkingSeats;
}

int Building::getRestaurants()
{
	return this->restaurants;
}

void Building::setRestaurants(int restaurants)
{
	this->restaurants = restaurants;
}

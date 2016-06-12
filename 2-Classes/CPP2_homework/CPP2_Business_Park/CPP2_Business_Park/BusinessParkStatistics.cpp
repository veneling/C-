#include "BusinessParkStatistics.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

BPStatistics::BPStatistics(vector <Building> buildings)
{
	this->setBuildings(buildings);
}

BPStatistics::~BPStatistics()
{
	vector <Building> b;
	this->buildings.swap(b);
}

vector <Building> *BPStatistics::getBuildings()
{
	return &buildings;
}

void BPStatistics::setBuildings(vector <Building> buildings)
{
	this->buildings = buildings;
}

void BPStatistics::getMostEmployees()
{
	auto maxEmployees = max_element(getBuildings()->begin(), getBuildings()->end(), [](Building &a, Building &b)
	{
		return  a.getNumberOfEmployees() < b.getNumberOfEmployees();
	});

	cout << "Company \"" << maxEmployees->getCompany() << "\" has most employees: " <<
		maxEmployees->getNumberOfEmployees() << endl;
}

void BPStatistics::getMostFreePlaces()
{
	auto mostFreeSeats = max_element(getBuildings()->begin(), getBuildings()->end(), [](Building &a, Building &b)
	{
		return  a.getNumberOfFreeWorkingSeats() < b.getNumberOfFreeWorkingSeats();
	});

	cout << "Company \"" << mostFreeSeats->getCompany() << "\" has most free seats: " <<
		mostFreeSeats->getNumberOfFreeWorkingSeats() << endl;
}

void BPStatistics::highestCoefEmpl()
{
	auto maxCoef = max_element(getBuildings()->begin(), getBuildings()->end(), [](Building &a, Building &b)
	{
		double ac = a.getNumberOfEmployees() / (a.getNumberOfEmployees() / a.getNumberOfFreeWorkingSeats());
		double bc = b.getNumberOfEmployees() / (b.getNumberOfEmployees() / b.getNumberOfFreeWorkingSeats());
		return  ac < bc;
	});

	cout << "Company \"" << maxCoef->getCompany() << "\" has highest utilization coefficient: " <<
		maxCoef->getNumberOfEmployees() / (maxCoef->getNumberOfEmployees() / maxCoef->getNumberOfFreeWorkingSeats()) 
		<< endl;
}

void BPStatistics::getMostPeoplePerFloor()
{
	auto mostPeoplePerFloor = max_element(getBuildings()->begin(), getBuildings()->end(), [](Building &a, Building &b)
	{
		return  a.getNumberOfEmployees() / a.getNumberOfFloors() < b.getNumberOfEmployees() / b.getNumberOfFloors();
	});

	cout << "Company \"" << mostPeoplePerFloor->getCompany() << "\" has most people per floor: " <<
		mostPeoplePerFloor->getNumberOfEmployees() / mostPeoplePerFloor->getNumberOfFloors() << endl;
}

void BPStatistics::getLeastPeoplePerFloor()
{
	auto leastPeoplePerFloor = max_element(getBuildings()->begin(), getBuildings()->end(), [](Building &a, Building &b)
	{
		return  a.getNumberOfEmployees() / a.getNumberOfFloors() > b.getNumberOfEmployees() / b.getNumberOfFloors();
	});

	cout << "Company \"" << leastPeoplePerFloor->getCompany() << "\" has least people per floor: " <<
		leastPeoplePerFloor->getNumberOfEmployees() / leastPeoplePerFloor->getNumberOfFloors() << endl;
}

void BPStatistics::getMostOfficesPerFloor()
{
	auto mostOfficesPerFloor = max_element(getBuildings()->begin(), getBuildings()->end(), [](Building &a, Building &b)
	{
		return  a.getNumberOfOffices() / a.getNumberOfFloors() < b.getNumberOfOffices() / b.getNumberOfFloors();
	});

	cout << "Company \"" << mostOfficesPerFloor->getCompany() << "\" has most offices per floor: " <<
		mostOfficesPerFloor->getNumberOfOffices() / mostOfficesPerFloor->getNumberOfFloors() << endl;
}

void BPStatistics::getLeastOfficesPerFloor()
{
	Building currBld, leastOfficesPerFloor;
	double n = getBuildings()->at(0).getNumberOfOffices() / getBuildings()->at(0).getNumberOfFloors();
	double leastOffices;
	for (vector<Building>::iterator it = getBuildings()->begin(); it != getBuildings()->end(); it++)
	{
		currBld = *it;
		leastOffices = currBld.getNumberOfOffices() / currBld.getNumberOfFloors();
		if (leastOffices < n)
		{
			n = leastOffices;
			leastOfficesPerFloor = currBld;
		}
	}
	cout << "Company \"" << leastOfficesPerFloor.getCompany() << "\" has least offices per floor: " <<
		n << endl;
}

void BPStatistics::getMostPeoplePerOffice()
{
	auto mostPeoplePerOffice = max_element(getBuildings()->begin(), getBuildings()->end(), [](Building &a, Building &b)
	{
		return  a.getNumberOfEmployees() / a.getNumberOfOffices() < b.getNumberOfEmployees() / b.getNumberOfOffices();
	});

	cout << "Company \"" << mostPeoplePerOffice->getCompany() << "\" has most people per office: " <<
		mostPeoplePerOffice->getNumberOfEmployees() / mostPeoplePerOffice->getNumberOfOffices() << endl;
}

void BPStatistics::getLeastPeoplePerOffice()
{
	auto leastPeoplePerOffice = max_element(getBuildings()->begin(), getBuildings()->end(), [](Building &a, Building &b)
	{
		return  a.getNumberOfEmployees() / a.getNumberOfOffices() > b.getNumberOfEmployees() / b.getNumberOfOffices();
	});

	cout << "Company \"" << leastPeoplePerOffice->getCompany() << "\" has least people per office: " <<
		leastPeoplePerOffice->getNumberOfEmployees() / leastPeoplePerOffice->getNumberOfOffices() << endl;
}

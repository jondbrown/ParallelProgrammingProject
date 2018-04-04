#include "Tour.h"



Tour::Tour(size_t** adjMat)
{
	adjancencyMatrix = adjMat;
	cityCount = 0;
}

//starts a tour at city number 0
Tour::Tour(int numCities, size_t** adjMat)
{
	adjancencyMatrix = adjMat;
	tourVector.push_back(0);
	for (int i = 0; i < numCities; i++)
	{
		tourVector.push_back(-1);
	}
	cityCount = 1;
}

Tour::Tour(int numCities, int startingCity, size_t** adjMat)
{
	adjancencyMatrix = adjMat;
	tourVector.push_back(startingCity);
	for (int i = 0; i < numCities; i++)
	{
		tourVector.push_back(-1);
	}
	cityCount = 1;
}

Tour::Tour(const Tour & tourToCopy)
{
	tourVector = tourToCopy.GetTourVector();
	cityCount = tourToCopy.GetCityCount();
	adjancencyMatrix = tourToCopy.GetAdjMat();
}


Tour::~Tour()
{
}

const vector<size_t>& Tour::GetTourVector() const
{
	// TODO: insert return statement here
}

size_t Tour::GetCityCount() const
{
	return size_t();
}

size_t Tour::GetTotalTourCost() const
{
	return size_t();
}

size_t ** Tour::GetAdjMat() const
{
	return nullptr;
}

bool Tour::IsComplete() const
{
	return false;
}

void Tour::AddCity(size_t city)
{
	tourVector.insert(tourVector.begin() + cityCount, city);
	cityCount++;
}

int Tour::RemoveLastCity()
{
	tourVector.insert(tourVector.begin() + cityCount - 1, NO_CITY);
	cityCount--;
}

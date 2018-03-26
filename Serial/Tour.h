#include <vector>

#pragma once

using namespace std;

class Tour
{
#define NO_CITY SIZE_MAX
public:
	Tour(size_t** adjMat);
	Tour(int numCities, size_t** adjMat);
	Tour(int numCities, int startingCity, size_t** adjMat);
	Tour(const Tour& tourToCopy);
	~Tour();
	const vector<size_t>& GetTourVector() const;
	size_t GetCityCount() const;
	size_t GetTotalTourCost() const;
	size_t** GetAdjMat() const;
	//checks the fullness of tourVector
	bool IsComplete() const;	
	//create City Class Eventually to pass into this method
	void AddCity(size_t city);
	int RemoveLastCity();
private:
	size_t** adjancencyMatrix;
	std::vector<size_t> tourVector;
	//is the tour full of cities?
	bool full;
	size_t cityCount;


};


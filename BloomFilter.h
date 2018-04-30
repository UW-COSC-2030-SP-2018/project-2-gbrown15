/*
Gage Brown
COSC 2030
4.30.2018
Project 2
BloomFilter.h
Adapted from:
codereview.stackexchange.com/questions/179135/
*/


#ifndef BLOOMFILTER_H
#define BLOOMFILTER_H
#include <iostream>
#include <string>
#include <vector>
#include <iterator>


typedef unsigned int(*HashFunction)(std::string);

class BloomFilter 
{
private:

	unsigned int numberOfCells;
	unsigned int numberOfFunctions;
	bool* cell;
	std::vector<HashFunction> hashFunctions;

public:

	BloomFilter(unsigned int numbCells, std::vector<HashFunction> funcs) : numberOfCells(numbCells), hashFunctions(funcs) 
	{
		cell = (bool*)calloc(numbCells, sizeof(bool));
	}

	~BloomFilter()
	{
		free(cell);
		cell = NULL;
	}

	void addElement(std::string const& str) 
	{
		for (std::vector<HashFunction>::iterator iter = hashFunctions.begin(); iter != hashFunctions.end(); iter++) 
		{
			cell[(*iter)(str) % numberOfCells] = true;
		}
	}

	bool isMember(std::string const& str) 
	{
		bool inSet = true;

		for (std::vector<HashFunction>::iterator iter = hashFunctions.begin(); iter != hashFunctions.end(); iter++) 
		{
			if (cell[(*iter)(str) % numberOfCells] == false) 
			{
				inSet = false;
				break;
			}
		}

		return inSet;
	}
};

//Additional hash function for testing
unsigned int djb2(std::string str) 
{
	unsigned int hash = 5381;

	for (std::string::iterator iter = str.begin(); iter != str.end(); iter++) 
	{
		hash = ((hash << 5) + hash) + *iter;
	}

	return hash;
}
#endif
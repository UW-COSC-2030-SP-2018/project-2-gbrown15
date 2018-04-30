/*
Gage Brown
COSC 2030
4.29.2018
Project 2
Project2.cpp
*/


#include "Project2.h"
#include "BloomFilter.h"
#include <algorithm> //used for testing
using std::sort;


int main()
{
	//Basic Tests
	/*
	//GB: Testing QuickSort
	vector<int> test = randVec(30, 1, 75);
	Print(test);
	QuickSort(test);
	cout << "Quick Sort test\n";
	Print(test);

	//GB: Testing BinarySearch
	cout << "Enter value to search for in vector: ";
	int val;
	cin >> val;
	int index = BinarySearch(test, val);
	if (index == -1)
	{
		cout << "Value could not be found in the vector.\n";
	}
	else
	{
		cout << "Value was found at Vector[" << index << "]\n";
	}

	//GB: Testing MergeSort
	test = randVec(30, 1, 75);
	Print(test);
	cout << "Merge Sort test\n";
	MergeSort(test);
	Print(test);

	//GB: Testing BloomFilter
	// create bloom filter
	vector<HashFunction> hashFunctions;
	hashFunctions.push_back(djb2);
	hashFunctions.push_back(StrToIntHash);

	BloomFilter bloom(1024, hashFunctions);

	//Bloom set
	vector<string> bloomSet(
		{
		"Gage Brown",
		"tomato potato",
		"pickled pickles",
		"alpha",
		"beta",
		"charlie"
		});

	cout << "Bloom filter created." << endl;
	cout << "Bloom filter tests for the following set of strings:" << std::endl;

	for (vector<string>::iterator iter = bloomSet.begin(); iter != bloomSet.end(); iter++) 
	{
		bloom.addElement(*iter);
		cout << "\t" + *iter << endl;
	}

	//Test set
	vector<string> testSet(
		{
		"Gage Brown",
		"tomato potato",
		"pickled pickles",
		"alpha",
		"beta",
		"charlie",
		"delta",
		"echo",
		"foxtrot",
		"gamma"
		});

	cout << "Testing whether the following strings are members of the set:" << std::endl;
	cout << std::boolalpha;

	for (vector<string>::iterator iter = testSet.begin(); iter != testSet.end(); iter++) 
	{
		cout << "\t" + *iter + ": " << bloom.isMember(*iter) << endl;
	}
	*/
	
	//Testbench: Property based unit tests
	//Test: QuickSort
	vector<int> vec1 = randVec(50, 0, 500);
	vector<int> vec2 = vec1;
	QuickSort(vec1);
	sort(vec2.begin(), vec2.end());
	if (vec1 == vec2)
	{
		cout << "QuickSort successful:" << endl << endl;
		Print(vec1);
	}
	else
	{
		cout << "QuickSort failed! Did not match the sorted test vector." << endl << endl;
		Print(vec1);
	}

	//Test: BinarySearch
	int x = vec2[15];
	int indexVal = BinarySearch(vec2, x);
	if (indexVal == 15)
	{
		cout << "\nBinarySearch successfully returned the index of the integer in the vector.\n";
	}
	else if (indexVal == -1)
	{
		cout << "\nBinarySearch failed! Did not find the value and returned -1.\n";
	}
	else
	{
		cout << "\nBinarySearch failed! Found the value, but returned the wrong index value.\n";
	}

	//Test: MergeSort
	vec1 = randVec(50, 0, 500);
	vec2 = vec1;
	MergeSort(vec1);
	sort(vec2.begin(), vec2.end());
	if (vec1 == vec2)
	{
		cout << "\nMergeSort successful:" << endl << endl;
		Print(vec1);
	}
	else
	{
		cout << "\nMergeSort failed! Did not match the sorted test vector." << endl << endl;
		Print(vec1);
	}

	//Test: Hashing
	cout << "\nTest Hashing: \n";
	string testStr = "string";
	int testInt = 80;
	unsigned int strHash = StrToIntHash(testStr);
	unsigned int intHash = IntToIntHash(testInt);
	cout << "'" << testStr << "' Hashed to: " << strHash
		<< "\nand " << testInt << " Hashed to: " << intHash << endl;

	//Test: Bloom Filter
	// create bloom filter
	cout << "\nTest Bloom Filter: " << endl;
	vector<HashFunction> hashFunctions;
	hashFunctions.push_back(djb2);
	hashFunctions.push_back(StrToIntHash);

	BloomFilter bloom(1024, hashFunctions);

	//Bloom set
	vector<string> bloomSet(
		{
			"Gage Brown",
			"tomato potato",
			"pickled pickles",
			"alpha",
			"beta",
			"charlie"
		});

	cout << "Bloom filter created." << endl;
	cout << "Bloom filter comprised of the following set of strings:" << endl;

	for (vector<string>::iterator iter = bloomSet.begin(); iter != bloomSet.end(); iter++)
	{
		bloom.addElement(*iter);
		cout << "\t" + *iter << endl;
	}

	//Test set
	vector<string> testSet(
		{
			"Gage Brown",
			"tomato potato",
			"pickled pickles",
			"alpha",
			"beta",
			"charlie",
			"delta",
			"echo",
			"foxtrot",
			"gamma"
		});

	cout << "Testing whether the following strings are members of the set:" << endl;
	cout << std::boolalpha;

	for (vector<string>::iterator iter = testSet.begin(); iter != testSet.end(); iter++)
	{
		cout << "\t" + *iter + ": " << bloom.isMember(*iter) << endl;
	}
	system("pause");
	return 0;
}
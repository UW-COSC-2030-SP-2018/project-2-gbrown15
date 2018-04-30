/*
Gage Brown
COSC 2030
4.29.2018
Project 2
Project2.cpp
*/

#ifndef PROJECT2_H
#define PROJECT2_H

#include "RandomUtilities.h"
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

/*
Swaps the values of two variables
*/
void Swap(int *num1, int *num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

/*
Returns size of vector as an int
*/
int Size(vector<int> vec)
{
	int size = (int)(vec.size());
	return size;
}

/*
Partition: utilized by the QuickSort funtion
*/
int Partition(vector<int> &vec, int start, int end)
{
	int pivot = vec[start];
	int i = start;
	for (int j(start + 1); j < end; j++)
	{
		if (vec[j] <= pivot)
		{
			i++;
			Swap(&vec[j], &vec[i]);
		}
	}
	Swap(&vec[start], &vec[i]);
	return i;
}

/*
Recursive Quick Sort implimentation
*/
void QuickSort(vector<int> &vec, int start = 0, int end = -1)
{
	if (end == -1)
	{
		end = Size(vec);
	}
	if (start < end)
	{
		int p = Partition(vec, start, end);

		QuickSort(vec, start, p);
		QuickSort(vec, (p + 1), end);
	}
}

/*
Returns location of val in a sorted vector
If value is not found, returns -1
*/
int BinarySearch(vector<int> vec, int val, int start = 0, int end = -1)
{
	if (end == -1)
	{
		end = Size(vec);
	}
	if (end >= start)
	{
		int mid = start + (end - start) / 2;
		if (vec[mid] == val)
		{
			return mid;
		}

		if (vec[mid] > val)
		{
			return BinarySearch(vec, val, start, (mid - 1));
		}
		else
		{
			return BinarySearch(vec, val, (mid + 1), end);
		}
	}
	return -1;
}

/*
Merge: utilized by the MergeSort function
*/
void Merge(vector<int> &vec, int start, int mid, int end)
{
	int L(0), R(0), k(start);
	int n1 = mid - start + 1;
	int n2 = end - mid;

	vector<int> left, right;
	for (int i(0); i < n1; i++)
	{
		left.push_back(vec[start + i]);
	}
	for (int i(0); i < n2; i++)
	{
		right.push_back(vec[(mid + 1) + i]);
	}

	while (L < n1 && R < n2)
	{
		if (left[L] <= right[R])
		{
			vec[k] = left[L];
			L++;
		}
		else
		{
			vec[k] = right[R];
			R++;
		}
		k++;
	}

	while (L < n1)
	{
		vec[k] = left[L];
		L++;
		k++;
	}

	while (R < n2)
	{
		vec[k] = right[R];
		R++;
		k++;
	}
}

/*
Recursive Merge Sort implimentation
*/
void MergeSort(vector<int> &vec, int start = 0, int end = -1)
{
	if (end == -1)
	{
		end = Size(vec) - 1;
	}
	if (start < end)
	{
		int mid = start + (end - start) / 2;

		MergeSort(vec, start, mid);
		MergeSort(vec, (mid + 1), end);

		Merge(vec, start, mid, end);
	}
}

/*
String to hashed int
*/
unsigned int StrToIntHash(string str)
{
	unsigned int hash = static_cast<unsigned int>(str.length());
	for (size_t i = 0; i < str.length(); i++)
	{
		hash = ((hash << 5) ^ (hash >> 27)) ^ str[i];
	}

	return hash;
}

/*
Int to hashed int:
converts int to string then passes said string into StrToIntHash
*/
unsigned int IntToIntHash(int num)
{
	string str = std::to_string(num);
	unsigned int hash = StrToIntHash(str);
	return hash;
}

/*
Creates a randomly filled vector using RandomUtilities.h
*/
vector<int> randVec(size_t size, int minNum, int maxNum)
{
	vector<int> vec;
	for (size_t i = 0; i < size; ++i)
	{
		vec.push_back(randInt(minNum, maxNum));
	}
	return vec;
}

/*
Prints vector
*/
void Print(vector<int>& vec)
{
	int size = Size(vec);
	cout << "the vector is in this order: {";
	for (int i = 0; i < size; i++)
	{
		if (i == size - 1)
		{
			cout << vec[i];
		}
		else
		{
			cout << vec[i] << ", ";
		}
	}
	cout << "}" << endl;
}
#endif
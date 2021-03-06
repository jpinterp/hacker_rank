// Arrays.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include "string.h"

using namespace std;

#define MAX_ARRAY_LEN	(1000)

int Solution1();
int Solution2();

// The function reads from stdin:
//	The number of elements in the array
//	The actual elements of the array
// Returns:
//	The array in reverse order
//
int main()
{
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	return Solution2();

}

int Solution2()
{
	char lenStr[256];
	std::cout << "\nEnter length of array: ";
	std::cin.getline(lenStr, _countof(lenStr));

	char arrayStr[MAX_ARRAY_LEN * 6];
	std::cout << "\nEnter array with spaces between numbers: ";
	std::cin.getline(arrayStr, _countof(arrayStr));

	int arrayLen = atoi(lenStr);
	std::vector<int> data(arrayLen, 0);



	char* next_tok;
	char* p = strtok_s(arrayStr, " ", &next_tok);
	while (p != NULL)
	{
		// always inserting at beginning will 'reverse' the input
		data.insert(data.begin(), atoi(p));
		p = strtok_s(NULL, " ", &next_tok);
	}

	// dump the array to stdout, the vector may have more
	// elements than the data array
	std::vector<int>::iterator it = data.begin();
	for (int i=0 ; i<arrayLen ; i++)
	{
		std::cout << *it << " ";
		it++;
	}

	return 0;

}


int Solution1()
{
	int length = 0;
	// printf_s("\nEnter length of array: ");
	fscanf_s(stdin, "%i", &length);
	
	int data[MAX_ARRAY_LEN];

	char tmp[MAX_ARRAY_LEN * 6];     // up to 1000 elements, up to 5 digits each, 1 space separating
	// printf_s("\nEnter array with spaces between numbers: ");
	fscanf_s(stdin, " %[^\n]s", tmp, (MAX_ARRAY_LEN*6));  // the space in the format string is important!!

	char* next_tok;
	char* p = strtok_s(tmp, " ", &next_tok);
	int i = 0;
	while (p != NULL)
	{
		data[i] = atoi(p);
		p = strtok_s(NULL, " ", &next_tok);
		i++;
	}

	for (i = length - 1; i >= 0; i--)
	{
		printf("%i ", data[i]);
	}

	return 0;
}
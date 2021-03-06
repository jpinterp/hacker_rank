// VariableArrays.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

// online code requires 1024*1024*10
#define MAX_INPUT_LEN  (1024)

// Sample Input
// 2 2					Number of arrays, number of queries
// 3 1 5 4				First array:  first number is array length, remainder is array elements
// 5 1 2 8 9 3			Second array:  first number is array length, remainder is array elements
// 0 1					First query:  index of the array, index into array; both 0 indexed
// 1 3					Second query:  index of the array, index into the array; both 0 indexed
//
// Sample Output
// 5
// 9
//
int main()
{
	int arrayCount;
	int queryCount;
	char input[MAX_INPUT_LEN];

	std::vector<std::vector<int>> arrays;
	std::vector<std::vector<int>> queries;

	// Get number of arrays and number of queries from stdin
	std::cout << "Enter number of arrays and queries: ";
	std::cin.getline(input, _countof(input));
	char* next_tok;
	char* p = strtok_s(input, " ", &next_tok);
	if (p != NULL)
	{
		arrayCount = atoi(p);
		p = strtok_s(NULL, " ", &next_tok);
		if (p != NULL)
		{
			queryCount = atoi(p);
		}
	}

	// Get the arrays from stdin
	for (int i = 0; i < arrayCount; i++)
	{
		std::cout << "Enter array " << i << ": ";
		std::cin.getline(input, _countof(input));

		p = strtok_s(input, " ", &next_tok);
		int arrayLen = atoi(p);
		std::vector<int> v;
		
		p = strtok_s(NULL, " ", &next_tok);
		while (p != NULL)
		{
			int t = atoi(p);
			v.insert(v.end(), t);

			p = strtok_s(NULL, " ", &next_tok);
		}

		arrays.insert(arrays.end(), v);
	}

	// Get the queries from stdin
	for (int i = 0; i < queryCount; i++)
	{
		std::cout << "Enter query " << i << ": ";
		std::cin.getline(input, _countof(input));

		std::vector<int> v;
		p = strtok_s(input, " ", &next_tok);
		while (p != NULL)
		{
			int t = atoi(p);
			v.insert(v.end(), t);

			p = strtok_s(NULL, " ", &next_tok);
		}

		queries.insert(queries.end(), v);
	}

	// Now that the input is in vectors of vectors, perform the queries
	for (std::vector<std::vector<int>>::iterator it = queries.begin(); it != queries.end(); it++)
	{
		std::vector<int> q = *it;
		int a = q.at(0);
		int i = q.at(1);

		int r = arrays.at(a).at(i);
		std::cout << r << "\n";
	}

    return 0;
}


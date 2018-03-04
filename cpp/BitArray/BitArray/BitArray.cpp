// BitArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <map>

#define MAX_ARRAY_SIZE  (10^8)
#define MAX_INPUT_SIZE  (1024)

// a[0] = S (modulo 2^31)
// for i = 1 to N - 1
//     a[i] = a[i - 1] * P + Q(modulo 2 ^ 31)
//
int main()
{
	std::map<int, int> m;
// 	std::cout << "Max map size: " << m.max_size() << "\n";

	char input[MAX_INPUT_SIZE];
	// std::cout << "\nEnter test parameters N, S, P, Q: ";
	std::cin.getline(input, _countof(input));


	char* next_tok;
	char* p = strtok_s(input, " ", &next_tok);
	int N = atoi(p);
	p = strtok_s(NULL, " ", &next_tok);
	int S = atoi(p);
	p = strtok_s(NULL, " ", &next_tok);
	int P = atoi(p);
	p = strtok_s(NULL, " ", &next_tok);
	int Q = atoi(p);


	int aPrev = S % (2 ^ 31);
	m.insert(std::pair<int,int>(aPrev, aPrev));

	for (int i = 1; i <= N - 1; i++)
	{
		int a = (aPrev * P) + (Q % (2 ^ 31));
		m.insert(std::pair<int,int>(a, a));
		aPrev = a;
	}

	std::cout << m.size();

    return 0;
}


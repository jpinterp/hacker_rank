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

	// Create the bit masks
	unsigned int mask[32];
	for (int i = 0; i < 32; i++)
	{
		mask[i] = 1 << i;
	}

	// Get and parse the input
	char input[MAX_INPUT_SIZE];
	std::cout << "\nEnter test parameters N, S, P, Q: ";
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

	// bitmap array, one bit for each number calculated
	unsigned int bitmapArray[1 + (MAX_ARRAY_SIZE / 32)];
	memset(bitmapArray, 0, sizeof(bitmapArray));

	// calculate the first number
	int a;
	int aPrev = S % (2 ^ 31);
	int bitIndex = 0;
	int intIndex = 0;
	bitmapArray[intIndex] = mask[bitIndex];
	
	int qMod = Q % (2 ^ 31);
	// calculate all the other numbers
	for (int i = 1; i <= N - 1; i++)
	{
		a = (aPrev * P) + qMod;
		aPrev = a;

		bitIndex = a % 32;
		intIndex = a / 32;
		bitmapArray[intIndex] = bitmapArray[intIndex] | mask[bitIndex];
	}

	
	for (int i = 0; i < N; i++)
	{

	}
    return 0;
}


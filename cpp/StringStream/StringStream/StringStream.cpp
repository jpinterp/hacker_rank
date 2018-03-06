// StringStream.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	// Complete this function
	int x;
	char ch;
	vector<int> v;

	stringstream ss(str);
	while (!ss.eof())
	{
		ss >> x >> ch;
		v.insert(v.end(), x);
	}
	return v;
}

int main() {
	string str;
	cin >> str;
	vector<int> integers = parseInts(str);
	for (int i = 0; i < integers.size(); i++) {
		cout << integers[i] << "\n";
	}

	return 0;
}


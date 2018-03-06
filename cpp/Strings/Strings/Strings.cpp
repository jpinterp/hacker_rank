// Strings.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <string>
#include <sstream>
#include <iostream>

int main()
{
	using namespace std;

	string a;
	string b;

	getline(cin, a);
	getline(cin, b);

	cout << a.length() << " " << b.length() << "\n";
	cout << a + b << "\n";

	string c = b.at(0) + a.substr(1, a.length() - 1);
	string d = a.at(0) + b.substr(1, b.length() - 1);

	cout << c << " " << d << "\n";

    return 0;
}


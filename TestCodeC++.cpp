// TestCodeC++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	cout << "Hello World!" << endl;
	int n;
	cout << "Enter a number: ";
	cin >> n;
	if (n % 2 == 0) {
		cout << n << " is even." << endl;
	}
	else {
		cout << n << " is odd." << endl;
	}
}


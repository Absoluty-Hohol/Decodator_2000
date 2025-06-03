#include <iostream>
#include <string>
#include "Encoder.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	string input;
	while (true)
	{
		cout << ">";
		cin >> input;
		if (input == "exit")
		{
			break;
		}
		else if (input == "encode")
		{
			cout << "Слово для шифра: ";
			cin.ignore();
			getline(cin, input);
			encode(input);
		}
	}

	return 0;
}

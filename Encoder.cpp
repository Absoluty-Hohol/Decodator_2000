#include <iostream>
#include <map>
#include <string>
#include <fstream>

using namespace std;

int encode(string input)
{

	const int QUANTITY_LETTERS = 26;
	char Letters[QUANTITY_LETTERS] = {
		'A', 'B', 'C', 'D', 'E', 'F', 'G',
		'H', 'I', 'J', 'K', 'L', 'M', 'N',
		'O', 'P', 'Q', 'R', 'S', 'T', 'U',
		'V', 'W', 'X', 'Y', 'Z'
	};
	char Letters2[QUANTITY_LETTERS];
	for (size_t i = 0; i < 26; i++)
	{
		cout << "Введите значение для буквы " << Letters[i] << ": ";
		cin >> Letters2[i];
	}
	map<char, char> replace;
	
	for (size_t i = 0; i < QUANTITY_LETTERS; i++)
	{
		replace[Letters[i]] = Letters2[i];
		replace[tolower(Letters[i])] = tolower(Letters2[i]);
	}

	for (char ch : input) {
		if (replace.count(ch)) {
			cout << replace[ch];
		}
		else {
			cout << ch;
		}
	}

	ofstream file("Letters.txt");
	if (file.is_open())
	{
		for (size_t i = 0; i < QUANTITY_LETTERS ; i++)
		{
			file << Letters2[i] << endl;
		}
	}
	file.close();
	return 0;
}

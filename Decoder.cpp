#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

int decoder(string path,string wrong)
{
	fstream file(path, ios::in);

	if (!file.is_open())
	{
		cerr << "Fatal Error";
		return 1;
	}
	const int QUANTITY_LETTER = 26;
	char Letter[QUANTITY_LETTER];
	char Letter2[QUANTITY_LETTER] =
	{
		'A', 'B', 'C', 'D', 'E', 'F', 'G',
		'H', 'I', 'J', 'K', 'L', 'M', 'N',
		'O', 'P', 'Q', 'R', 'S', 'T', 'U',
		'V', 'W', 'X', 'Y', 'Z'
	};
	int i = 0;
	char line;
	while (file.get(line) && i < QUANTITY_LETTER)
	{
			Letter[i] = line;
			i++;
	}
	map<char, char> replace;
	for (size_t i = 0; i < QUANTITY_LETTER; i++)
	{
		replace[Letter[i]] = Letter2[i];
		replace[tolower(Letter[i])] = tolower(Letter2[i]);
	}
	for (char ch : wrong) {
		if (replace.count(ch)) {
			cout << replace[ch];
		}
		else {
			cout << ch;
		}
	}
	file.close();
	return 0;
}

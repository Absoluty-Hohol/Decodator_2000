#include <iostream>
#include <string>
#include <map>
#include <functional>

#include "Decoder.h"
#include "Encoder.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	map<string, function<void()>> commands;
	string input,wrong;

	commands["encode"] = [&]()
		{
			cout << "Слово для шифра: ";
			cin.ignore();
			getline(cin, input);
			encode(input);
		};
	commands["decoder"] = [&]()
		{
			cout << "Впишите название файла: ";
			cin.ignore();
			getline(cin, input);
			cout << "Введите слово: ";
			getline(cin, wrong);
			decoder(input,wrong);
		};

	while (true)
	{
		cout << ">";
		cin >> input;
		
		if (input == "exit")
		{
			break;
		}

		auto it = commands.find(input);
		if (it != commands.end())
		{
			it->second();
		}

		else
		{
			cout << "Неизвестная команда";
		}
	}

	return 0;
}

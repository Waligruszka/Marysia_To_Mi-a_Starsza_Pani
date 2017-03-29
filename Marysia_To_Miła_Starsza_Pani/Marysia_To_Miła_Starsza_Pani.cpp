// Marysia_To_Mi³a_Starsza_Pani.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Character.h"
#include "CharacterEditor.h"
#include <iostream>
#include <string>

int main()
{
	int option=99;
	std::string fileName;
	CharacterEditor heroPool;
	while (option != 0)
	{
		std::cout << "==============================\nWybierz opcje:\n 1.Stworz nowa postac\n 2.Edytuj istniejaca postac\n 3.Zapisz postac do pliku\n 4.Odczytaj postac z pliku\n 5.Wyswietl liste postaci\n 6.Wyswietl konkretna postac wraz z jej parametrami\n 0.Wyjdz z programu\n==============================\nTwoj wybor: ";
		std::cin >> option;
		if (option == 1) heroPool.createCharacter();
		if (option == 2)
		{
			int heroIndex;
			heroPool.dispAll();
			std::cout << "Wybierz postac do edycji: ";
			std::cin >> heroIndex;
			heroPool.editCharacter(heroIndex);
		}
		if (option == 3)
		{
			int heroIndex;
			heroPool.dispAll();
			std::cout << "Wprowadz indeks postaci do zapisu: ";
			std::cin >> heroIndex;
			std::cout << "\nWprowadz nazwe pliku do zapisu: ";
			std::cin >> fileName;
			heroPool.saveToFile(fileName, heroIndex);
		}
		if (option == 4)
		{
			std::cout << "Wprowadz nazwe pliku do odczytu: ";
			std::cin >> fileName;
			heroPool.readFromFile(fileName);
		}
		if (option == 5)
		{
			std::cout << "\nObecne postac(i) na liscie to:\n";
			heroPool.dispAll();
			std::cout << "\n";
		}
		if (option == 6)
		{
			int heroIndex;
			std::cout << "Wprowadz indeks postaci do sprawdzenia: ";
			std::cin >> heroIndex;
			heroPool.dispCharacter(heroIndex-1);
		}
	}
	return 0;
}

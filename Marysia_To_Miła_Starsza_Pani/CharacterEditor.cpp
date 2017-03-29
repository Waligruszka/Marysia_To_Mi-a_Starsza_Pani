#include "stdafx.h"
#include "CharacterEditor.h"
#include "Character.h"
#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>

CharacterEditor::CharacterEditor()
{
}


CharacterEditor::~CharacterEditor()
{
}

Character CharacterEditor::createCharacter()
{
	Character newChampion;
	std::string name;
	std::string paramName;
	unsigned int paramValue;
	std::cout << "Wybierz imie dla nowego bohatera: ";
	std::cin >> name;
	newChampion.setName(name);
	std::cout << "\n";
	std::cout << "Zdefiniuj parametry nowego bohatera:\nPunkty zdrowia: ";
	std::cin >> paramValue;
	newChampion.setParameter(paramValue, "hp");
	std::cout << "\n";
	std::cout << "Punkty pancerza: ";
	std::cin >> paramValue;
	newChampion.setParameter(paramValue, "arm");
	std::cout << "\n";
	std::cout << "Zrecznosc: ";
	std::cin >> paramValue;
	newChampion.setParameter(paramValue, "agil");
	std::cout << "\n";
	std::cout << "Inteligencja: ";
	std::cin >> paramValue;
	newChampion.setParameter(paramValue, "int");
	std::cout << "\n";
	std::cout << "Punkty sily: ";
	std::cin >> paramValue;
	newChampion.setParameter(paramValue, "str");
	std::cout << "\n";
	std::cout << "Bazowe zadawane obrazenia: ";
	std::cin >> paramValue;
	newChampion.setParameter(paramValue, "dmg");
	std::cout << "\n";
	std::cout << "Zakonczono tworzenie bohatera!\n";
	CharacterEditor::characters.push_back(newChampion);
	return newChampion;
}

void CharacterEditor::saveToFile(std::string filePath, int heroIndex)
{
	std::ofstream file;
	file.open(filePath);
	file << CharacterEditor::characters[heroIndex];
	file.close();
	std::cout << "Zapisano do pliku!\n";
}

void CharacterEditor::readFromFile(std::string filePath)
{
	Character newDude;
	std::ifstream file(filePath);
	std::string line;
	file >> newDude;
	CharacterEditor::characters.push_back(newDude);
	std::cout << "Odczytano plik!\n";
}

void CharacterEditor::dispCharacter(int i)
{
	CharacterEditor::characters[i].dispStats();
}

void CharacterEditor::dispAll()
{
	int size = CharacterEditor::characters.size();
	for (int i = 0; i < size; i++)
	{
		std::cout << i + 1 << "." << CharacterEditor::characters[i].getName() << "\n";
	}
}

void CharacterEditor::editCharacter(int index)
{
	std::string paramName;
	int paramVal;
	std::cout << "Wybierz parametr do edycji (hp/arm/agil/int/str/dmg): ";
	std::cin >> paramName;
	std::cout << "\n";
	std::cout << "Wprowadz nowa nazwe parametru: ";
	std::cin >> paramVal;
	std::cout << "\n";
	CharacterEditor::characters[index].setParameter(paramVal, paramName);
	std::cout << "Pomyslnie edytowano parametr!\n";
}
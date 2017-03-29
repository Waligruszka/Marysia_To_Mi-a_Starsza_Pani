#include "stdafx.h"
#include "Character.h"
#include <iostream>
#include <string>

Character::Character()
{
}


Character::~Character()
{
}

void Character::setParameter(const int value, const std::string paramName)
{
	if (paramName == "hp") Character::healthPoints = value;
	if (paramName == "arm") Character::armor = value;
	if (paramName == "agil") Character::agility= value;
	if (paramName == "int") Character::intelligence = value;
	if (paramName == "str") Character::strength = value;
	if (paramName == "dmg") Character::damage = value;
}

int Character::getParameter(const std::string paramName)
{
	if (paramName == "hp") return Character::healthPoints;
	if (paramName == "arm") return Character::armor;
	if (paramName == "agil") return Character::agility;
	if (paramName == "int") return Character::intelligence;
	if (paramName == "str") return Character::strength;
	if (paramName == "dmg") return Character::damage;
}

std::string Character::getName()
{
	return Character::name;
}

void Character::setName(const std::string newName)
{
	Character::name = newName;
}

void Character::dispStats()
{
	std::cout << "\nNazwa postaci: " << Character::name << "\n";
	std::cout << "Punkty zycia: " << Character::healthPoints << "\n";
	std::cout << "Punkty pancerza: " << Character::armor << "\n";
	std::cout << "Zrecznosc: " << Character::agility << "\n";
	std::cout << "Inteligencja: " << Character::intelligence << "\n";
	std::cout << "Sila: " << Character::strength << "\n";
	std::cout << "Obrazenia bazowe: " << Character::damage << "\n\n";
}

std::ostream& operator<< (std::ostream& stream, const Character& charac)
{
	stream << charac.healthPoints << " " << charac.armor << " " << charac.agility << " " << charac.intelligence << " " << charac.strength << " " << charac.damage << " " << charac.name << std::endl;
	return stream;
}

std::istream& operator>> (std::istream& stream, Character& charac)
{
	stream >> charac.healthPoints >> charac.armor >> charac.agility >> charac.intelligence >> charac.strength >> charac.damage >> charac.name;
	return stream;
}
#pragma once
#include <string>

class Character
{
	int healthPoints;
	unsigned int armor;
	unsigned int agility;
	unsigned int intelligence;
	unsigned int strength;
	unsigned int damage;
	std::string name;
public:
	Character();
	~Character();
	void setParameter(const int value, const std::string paramName);
	int getParameter(const std::string paramName);
	void setName(const std::string newName);
	void dispStats();
	std::string getName();
	friend std::ostream& operator<< (std::ostream& stream, const Character& charac);
	friend std::istream& operator>> (std::istream& stream, Character& charac);
};

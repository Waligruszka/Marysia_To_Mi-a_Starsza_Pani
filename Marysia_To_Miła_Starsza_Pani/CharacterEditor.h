#pragma once
#include "Character.h"
#include <vector>
#include <string>

class CharacterEditor
{
	std::vector<Character> characters;
public:
	CharacterEditor();
	~CharacterEditor();
	Character createCharacter();
	void saveToFile(std::string filePath, int heroIndex);
	void readFromFile(std::string filePath);
	void dispCharacter(int i);
	void dispAll();
	void editCharacter(int index);
};


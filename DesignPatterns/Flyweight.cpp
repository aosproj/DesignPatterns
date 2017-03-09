#include <iostream>
#include <string>
#include <map>

class Character
{
public:
	virtual void Display(int pointsizenum) = 0;
protected:
	char symbol_name;
	int width;
	int height;
	int pointSize;
};

class charA : public Character
{
public:
	charA()
	{
		symbol_name = 'A';
		width = 100;
		height = 50;
	}

	void Display(int pointsizenum)
	{
		pointSize = pointsizenum;
		std::cout << symbol_name << " (pointsize " << pointSize << " )" << std::endl;
	}
};

class charB : public Character
{
public:
	charB()
	{
		symbol_name = 'B';
		width = 120;
		height = 70;
	}

	void Display(int pointsizenum)
	{
		pointSize = pointsizenum;
		std::cout << symbol_name << " (pointsize " << pointSize << " )" << std::endl;
	}
};
/*..*/
class charZ : public Character
{
public:
	charZ()
	{
		symbol_name = 'Z';
		width = 100;
		height = 90;
	}

	void Display(int pointsizenum)
	{
		pointSize = pointsizenum;
		std::cout << symbol_name << " (pointsize " << pointSize << " )" << std::endl;
	}
};

class CharactorFactory
{
public:
	virtual ~CharactorFactory()
	{
		while (!character_map.empty())
		{
			std::map<char, Character*>::iterator it = character_map.begin();
			delete it->second;
			character_map.erase(it);
		}
	}
	Character* getCharacter(char key)
	{
		Character* character = NULL;
		if (character_map.find(key) != character_map.end())
		{
			character =  character_map[key];
		}
		else
		{
			switch (key)
			{
			case 'A':
				character = new charA();
				break;
			case 'B':
				character = new charB();
				break;
				/*..*/
			case 'Z':
				character = new charZ();
				break;
			default:
				std::cout << "Unrecognized character";
				throw("Unrecognized");
			}
			character_map[key] = character;
		}
		return character;
	}
private:
	std::map<char, Character*> character_map;
};

int main()
{
	std::string doc = "AABZABBZ";
	const char* elems = doc.c_str();

	CharactorFactory* flyweight = new CharactorFactory();

	// extrinsic state
	int pointSize = 10;

	// For each character use a flyweight object
	for (size_t i = 0; i < doc.length(); i++)
	{
		pointSize++;
		Character* character = flyweight->getCharacter(elems[i]);
		character->Display(pointSize);
	}

	//Clean memory
	delete flyweight;

	return 0;
}
// RandomMonsterGenerator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>



class Monster {

public:
	enum MonsterType
	{
		Dragon,
		Goblin,
		Ogre,
		Orc,
		Skeleton,
		Troll,
		Vampire,
		Zombie,
		MAX_MONSTER_TYPES
	};

private:
	MonsterType m_type;
	std::string m_name, m_roar;
	int m_hitPoints;

public:
	Monster(MonsterType type, std::string name, std::string roar, int hitPoints) : m_type(type), m_name(name), m_roar(roar), m_hitPoints(hitPoints)
	{

	}

	std::string getTypeString()
	{
		switch (m_type)
		{
		case Monster::Dragon: return "dragon";
		case Monster::Goblin: return "goblin";
		case Monster::Ogre: return "ogre";
		case Monster::Orc: return "orc";
		case Monster::Skeleton: return "skeleton";
		case Monster::Troll: return "troll";
		case Monster::Vampire: return "vampire";
		case Monster::Zombie: return "zombie";
		}

		return "???";
	}

	void print()
	{
		std::cout << m_name << " the " << getTypeString() << " has " << m_hitPoints << " hit points and says " << m_roar << '\n';
	}

};

class MonsterGenerator
{
public:
	static int getRandomNumber(int min, int max)
	{
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
																					 // evenly distribute the random number across our range
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}

	static Monster generateMonster() 
	{
		Monster::MonsterType type = static_cast<Monster::MonsterType>(getRandomNumber(0, (Monster::MAX_MONSTER_TYPES - 1)));
		int hitPoints = getRandomNumber(1, 100);
		static std::string s_name[] = { "Bones", "Mark", "Dragthar", "Milk", "Nathan", "Fred" };
		static std::string s_roar[] = { "*rattles*", "*howls*", "*bellows*", "*shrieks*", "*roars*", "*screams*" };

		return Monster(type, s_name[getRandomNumber(0, 5)], s_roar[getRandomNumber(0, 5)], hitPoints);
	}

	

};


int main()
{
	srand(static_cast<unsigned int>(time(0)));
	rand();

	Monster m = MonsterGenerator::generateMonster();
	m.print();

	return 0;
}


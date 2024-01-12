// this is Vampire.cpp
#include "Vampire.h"

#include <string>
#include <cstdlib>

using namespace std;

int Vampire::MASTER_INDEX = 0;

Vampire::Vampire() : Creature()
{
	Location defaultValues;
	defaultValues.setComment(Vampire::COMMENT);
	defaultValues.setMohs(Vampire::MOHS);
	defaultValues.setFill(Vampire::FILL);
	this->setSpot(defaultValues);
	// this->spot.setComment(Vampire::COMMENT);
	// this->spot.setMohs(Vampire::MOHS);
	// this->spot.setFill(Vampire::FILL);
	this->incrAssignIndex();
	return;
}

Vampire::~Vampire()
{
}

Vampire::Vampire(int x, int y) : Creature(x, y, Vampire::FILL, Vampire::MOHS, Vampire::COMMENT)
{
	this->incrAssignIndex();
	return;
}

Vampire::Vampire(int x, int y, bool compAI) : Creature(x, y, Vampire::FILL, Vampire::MOHS, Vampire::COMMENT)
{
	this->incrAssignIndex();
	return;
}

void Vampire::incrAssignIndex()
{
	this->indexInVector = MASTER_INDEX;
	Vampire::MASTER_INDEX++;
	return;
}

int Vampire::getIndexInVector()
{
	return this->indexInVector;
}

void Vampire::initCreature(vector<Location *> &theMap, int ROWS, int COLS)
{
	this->Creature::setCreatureOnMap(theMap, ROWS, COLS);
	return;
}

int Vampire::getMove(vector<Location *> &theMap, int COLS, Location *target)
{
	return this->Creature::getMove(theMap, COLS, target);
}

int Vampire::getMovesPerTurn()
{
	return 2;
}

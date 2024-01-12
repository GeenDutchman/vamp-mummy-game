#include "Mummy.h"

#include <string>
#include <cstdlib>

using namespace std;

Mummy::Mummy() : Creature()
{
    Location defaultValues;
    defaultValues.setComment(Mummy::COMMENT);
    defaultValues.setMohs(Mummy::MOHS);
    defaultValues.setFill(Mummy::FILL);
    this->setSpot(defaultValues);
    return;
}

Mummy::~Mummy()
{
}

Mummy::Mummy(int x, int y) : Creature(x, y, Mummy::FILL, Mummy::MOHS, Mummy::COMMENT)
{
    return;
}

void Mummy::initCreature(vector<Location *> &theMap, int ROWS, int COLS)
{
    this->Creature::setCreatureOnMap(theMap, ROWS, COLS);
    return;
}

int Mummy::getMove(vector<Location *> &theMap, int COLS, Location *target)
{
    return this->Creature::getMove(theMap, COLS, target);
}

int Mummy::getMovesPerTurn()
{
    return 1;
}

int Mummy::backMohs()
{
    return Mummy::BACK_MOHS;
}

string Mummy::backFill()
{
    return Mummy::BACK_FILL;
}
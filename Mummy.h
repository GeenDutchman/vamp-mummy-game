#pragma once
#include "Creature.h"
#include <cstdlib>

using namespace std;

class Mummy : public Creature
{
protected:
    const string FILL = "M";
    const string COMMENT = "Mummy.\n";
    const int MOHS = 9;
    const string BACK_FILL = "W";
    const int BACK_MOHS = 8;

public:
    Mummy();
    ~Mummy();
    Mummy(int x, int y);
    virtual void initCreature(vector<Location *> &theMap, int ROWS, int COLS);
    virtual int getMove(vector<Location *> &theMap, int COLS, Location *target);
    virtual int getMovesPerTurn();
    virtual string backFill();
    virtual int backMohs();
};
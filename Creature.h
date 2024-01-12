// creature.h
#pragma once
#include "Location.h"
// #include "Location.cpp"

#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;

class Creature
{
public:
  Creature();
  Creature(int x, int y, string fill, int mohs, string comment);
  virtual int getMove(vector<Location *> &theMap, int COLS, Location *target) = 0;
  virtual int getMovesPerTurn();
  void moveUp(vector<Location *> &theMap, int COLS);
  void moveDown(vector<Location *> &theMap, int COLS);
  void moveLeft(vector<Location *> &theMap, int COLS);
  void moveRight(vector<Location *> &theMap, int COLS);
  void setCreatureOnMap(vector<Location *> &theMap, int ROWS, int COLS);
  //  int XYtoIdex(int x, int y, int ROWS, int COLS);
  virtual void initCreature(vector<Location *> &theMap, int ROWS, int COLS) = 0;
  virtual Location getSpot();
  virtual Location *getSpotP();
  virtual void setSpot(Location newLocation);

private:
  Location spot;
  // none so far
};

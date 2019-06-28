//this is Vampire.h
#pragma once
#include "Creature.h"
//#include "Creature.cpp"
#include <cstdlib>

using namespace std;

class Vampire : public Creature
{
 protected:
  const string FILL = "V";
  const string COMMENT = "Vampire.\n";
  const int MOHS = 5;
  int indexInVector;
  static int MASTER_INDEX;
 public:
  Vampire();
  ~Vampire();
  Vampire(int x, int y);
  Vampire(int x, int y, bool compAI);
  virtual void incrAssignIndex();
  virtual int getIndexInVector();
  //  void initVampire(vector<Location*> & theMap, int ROWS, int COLS);
  virtual void initCreature(vector<Location*> & theMap, int ROWS, int COLS);
  virtual int getMove(vector<Location*> & theMap, int COLS, Location* target);
  //virtual void moveUp(vector<Location*> & theMap);
  //virtual void moveDown(vector<Location*> & theMap);
  /* virtual void moveLeft(vector<Location*> & theMap); */
  /* virtual void moveRight(vector<Location*> & theMap); */
};

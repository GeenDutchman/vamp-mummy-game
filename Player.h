//Player.h
#pragma once
#include "Creature.h"
//#include "Creature.cpp"
#include <cstdlib>

using namespace std;

class Player : public Creature
{
 private:
  bool CPU;
  int level;
  const string FILL = "#";
  const string COMMENT = "This is you, the player.\n";
  const int MOHS = 2;
 public:
  Player();
  ~Player();
  Player(int x, int y);
  Player(int x, int y, bool compAI);
  //  void initPlayer(vector<Location*> & theMap, int ROWS, int COLS);
  virtual void initCreature(vector<Location*> & theMap, int ROWS, int COLS);
  virtual int getMove(vector<Location*> & theMap, int COLS, Location* target);
  //virtual void moveUp(vector<Location*> & theMap, int COLS);
  //virtual void moveDown(vector<Location*> & theMap, int COLS);
  //virtual void moveLeft(vector<Location*> & theMap, int COLS);
  //virtual void moveRight(vector<Location*> & theMap, int COLS);
  bool getCPU();
  void setCPU(bool newCPU);
  int getLevel();
  void setLevel(int newLevel);
};

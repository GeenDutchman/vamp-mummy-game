// this is Player.cpp
#include "Player.h"

#include <string>
#include <cstdlib>
#include <stdio.h>

using namespace std;

Player::Player() : Creature()
{
  Location defaultValues;
  defaultValues.setComment(Player::COMMENT);
  defaultValues.setMohs(Player::MOHS);
  defaultValues.setFill(Player::FILL);
  this->setSpot(defaultValues);
  // this->spot.setComment(Player::COMMENT);
  // this->spot.setMohs(Player::MOHS);
  // this->spot.setFill(Player::FILL);
  this->CPU = false;
  this->level = 0;
  return;
}

Player::~Player()
{
}

Player::Player(int x, int y) : Creature(x, y, Player::FILL, Player::MOHS, Player::COMMENT)
{
  return;
}

Player::Player(int x, int y, bool compAI) : Creature(x, y, Player::FILL, Player::MOHS, Player::COMMENT)
{
  this->CPU = compAI;
  this->level = 0;
  return;
}

void Player::initCreature(vector<Location *> &theMap, int ROWS, int COLS)
{
  this->level = 0;
  this->setCreatureOnMap(theMap, ROWS, COLS);
  return;
}

int Player::getMove(vector<Location *> &theMap, int COLS, Location *target)
{
  // int wasdOPT = 0;
  char traslated = 'V';
  do
  {
    // wasdOPT = getchar();
    cin >> traslated;
  } while ((traslated < 'a') && (traslated > 'z'));

  traslated = toupper(traslated);
  // traslated = toupper((char)wasdOPT);
  // putchar(traslated);
  switch (traslated)
  {
  case 'W':
    this->moveUp(theMap, COLS);
    break;
  case 'A':
    this->moveLeft(theMap, COLS);
    break;
  case 'S':
    this->moveDown(theMap, COLS);
    break;
  case 'D':
    this->moveRight(theMap, COLS);
    break;
  case 'Q':
    // valid for quit
    break;
  default:
    cout << "\nBad Entry\n";
    cout << traslated << "," << endl;
    break;
  }
  return traslated;
}

int Player::getMovesPerTurn()
{
  return 1;
}

bool Player::getCPU()
{
  return this->CPU;
}

void Player::setCPU(bool newCPU)
{
  this->CPU = newCPU;
  return;
}

int Player::getLevel()
{
  return this->level;
}

void Player::setLevel(int newLevel)
{
  this->level = newLevel;
  return;
}

// creature.cpp

#include "Creature.h"
#include <ctime>

using namespace std;

// so far all virtual
Creature::Creature()
{
  this->spot = Location();
  return;
}
Creature::Creature(int x, int y, string fill, int mohs, string comment)
{
  this->spot = Location(x, y, fill, mohs, comment);
  return;
}

void Creature::setCreatureOnMap(vector<Location *> &theMap, int ROWS, int COLS)
{
  srand(time(0));
  this->spot.setOnMap(theMap, ROWS, COLS);
  return;
}

int Creature::getMove(vector<Location *> &theMap, int COLS, Location *target)
{
  enum BINI
  {
    first = 1,
    second = 2,
    third = 4,
    fourth = 8
  };
  const int moves = this->getMovesPerTurn();
  for (char i = 0; i < moves; i++)
  {
    if (!(this->getSpot().compareXY(target)))
    {
      int targX = target->getXCoord();
      int targY = target->getYCoord();
      int vX = this->getSpot().getXCoord();
      int vY = this->getSpot().getYCoord();
      unsigned char decide = 0;
      if (vX != targX)
      {
        decide += first;
      }
      if (vY != targY)
      {
        decide += second;
      }

      switch (decide)
      {
      case 3:
        // int randy = (rand() % second) + first;//one means horz
        decide = (rand() % second) + first; // one means horz
      default:
        if (decide == second)
        {
          if (targY < vY)
          {
            this->moveUp(theMap, COLS);
          }
          else if (targY > vY)
          {
            this->moveDown(theMap, COLS);
          }
        }
        else if (decide == first)
        {
          if (targX < vX)
          {
            this->moveLeft(theMap, COLS);
          }
          else if (targX > vX)
          {
            this->moveRight(theMap, COLS);
          }
        }
        break;
      }
    }
  }
  return 1;
}

int Creature::getMovesPerTurn()
{
  return 1;
}

void Creature::moveUp(vector<Location *> &theMap, int COLS)
{
  //(int x, int y, int COLS)
  int idexToBe = this->spot.XYtoIdex(COLS) - COLS;
  if (theMap[idexToBe]->getMohs() < this->spot.getMohs())
  {
    theMap[idexToBe]->setFill(this->spot.getFill());
    theMap[idexToBe]->setMohs(this->spot.getMohs());
    theMap[idexToBe + COLS]->setFill(" ");
    theMap[idexToBe + COLS]->setMohs(0);
    this->spot.setYCoord(this->spot.getYCoord() - 1);
  }
  else
  {
    // oh no, can't move that way!
  }
  // cout << "this";
  return;
}

void Creature::moveDown(vector<Location *> &theMap, int COLS)
{
  int idexToBe = this->spot.XYtoIdex(COLS) + COLS;
  if (theMap[idexToBe]->getMohs() < this->spot.getMohs())
  {
    theMap[idexToBe]->setFill(this->spot.getFill());
    theMap[idexToBe]->setMohs(this->spot.getMohs());
    theMap[idexToBe - COLS]->setFill(" ");
    theMap[idexToBe - COLS]->setMohs(0);
    this->spot.setYCoord(this->spot.getYCoord() + 1);
  }
  else
  {
    // oh no, can't move that way!
  }
  // cout << "that";
  return;
}
void Creature::moveLeft(vector<Location *> &theMap, int COLS)
{
  int idexToBe = this->spot.XYtoIdex(COLS) - 1;
  if (theMap[idexToBe]->getMohs() < this->spot.getMohs())
  {
    theMap[idexToBe]->setFill(this->spot.getFill());
    theMap[idexToBe]->setMohs(this->spot.getMohs());
    theMap[idexToBe + 1]->setFill(" ");
    theMap[idexToBe + 1]->setMohs(0);
    this->spot.setXCoord(this->spot.getXCoord() - 1);
  }
  else
  {
    // oh no, can't move that way!
  }
  // cout << "and the other";
  return;
}
void Creature::moveRight(vector<Location *> &theMap, int COLS)
{
  int idexToBe = this->spot.XYtoIdex(COLS) + 1;
  if (theMap[idexToBe]->getMohs() < this->spot.getMohs())
  {
    theMap[idexToBe]->setFill(this->spot.getFill());
    theMap[idexToBe]->setMohs(this->spot.getMohs());
    theMap[idexToBe - 1]->setFill(" ");
    theMap[idexToBe - 1]->setMohs(0);
    this->spot.setXCoord(this->spot.getXCoord() + 1);
  }
  else
  {
    // oh no, can't move that way!
  }
  // cout << "thing";
  return;
}

Location Creature::getSpot()
{
  return this->spot;
}
Location *Creature::getSpotP()
{
  return &this->spot;
}
void Creature::setSpot(Location newLocation)
{
  this->spot.setXCoord(newLocation.getXCoord());
  this->spot.setYCoord(newLocation.getYCoord());
  this->spot.setMohs(newLocation.getMohs());
  this->spot.setFill(newLocation.getFill());
  this->spot.setComment(newLocation.getComment());
}

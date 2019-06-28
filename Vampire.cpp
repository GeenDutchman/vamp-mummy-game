//this is Vampire.cpp
#include "Vampire.h"

#include <string>
#include <cstdlib>

using namespace std;

int Vampire::MASTER_INDEX = 0;

Vampire::Vampire():Creature()
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

Vampire::Vampire(int x, int y):Creature(x, y, Vampire::FILL, Vampire::MOHS, Vampire::COMMENT)
{
  this->incrAssignIndex();
  return;
}

Vampire::Vampire(int x, int y, bool compAI):Creature(x, y, Vampire::FILL, Vampire::MOHS, Vampire::COMMENT)
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


void Vampire::initCreature(vector<Location*> & theMap, int ROWS, int COLS)
{
  this->Creature::setCreatureOnMap(theMap, ROWS, COLS);
  return;
}

int Vampire::getMove(vector<Location*> & theMap, int COLS, Location* target)
{
  enum BINI{first = 1, second = 2, third = 4, fourth = 8};
  for(char i = 0; i < second; i++)
    {
      if(!(this->getSpot().compareXY(target)))
	{
	  int targX = target->getXCoord();
	  int targY = target->getYCoord();
	  int vX = this->getSpot().getXCoord();
	  int vY = this->getSpot().getYCoord();
	  unsigned char decide = 0;
	  if(vX != targX)
	    {decide += first;}
	  if(vY != targY)
	    {decide += second;}

	  switch(decide)
	    {
	    case 3:
	      //int randy = (rand() % second) + first;//one means horz
	      decide = (rand() % second) + first;//one means horz
	    default:
	      if(decide == second)
		{
		  if(targY < vY)
		    {this->moveUp(theMap, COLS);}
		  else if(targY > vY)
		    {this->moveDown(theMap, COLS);}
		}
	      else if (decide == first)
		{
		  if(targX < vX)
		    {this->moveLeft(theMap, COLS);}
		  else if(targX > vX)
		    {this->moveRight(theMap, COLS);}
		}
	      break;
	    }
	}
    }
  return 'V';
}


#include "Location.h"

#include <string>

using namespace std;


Location::Location()
{
  this->xCoord = -1;
  this->yCoord = -1;
  this->fill = ' ';
  this->mohs = 0;
  this->comment = "Default Constructor.";
  return;
}
Location::Location(int x, int y)
{
  this->xCoord = x;
  this->yCoord = y;
  this->fill = ' ';
  this->mohs = 0;
  this->comment = "Empty space.";
  return;
}
Location::Location(int x, int y, string fill)
{
  this->xCoord = x;
  this->yCoord = y;
  this->fill = fill;
  this->mohs = 1;
  this->comment = "Empty space. Mohs 1.";
  return;
}
Location::Location(int x, int y, string fill, int mohs)
{
  this->xCoord = x;
  this->yCoord = y;
  this->fill = fill;
  this->mohs = mohs;
  this->comment = "Default Creature.";
  return;
}
Location::Location(int x, int y, string fill, int mohs, string comment)
{
  this->xCoord = x;
  this->yCoord = y;
  this->fill = fill;
  this->mohs = mohs;
  this->comment = comment;
  return;
}

Location::~Location(){}

//getter-setter pairs
int Location::getXCoord()
{
  return this->xCoord;
}
void Location::setXCoord(int neuX)
{
  this->xCoord = neuX;
  return;
}
int Location::getYCoord()
{
  return this->yCoord;
}
void Location::setYCoord(int neuY)
{
  this->yCoord = neuY;
  return;
}

int Location::getMohs()
{
  return this->mohs;
}
void Location::setMohs(int neuMohs)
{
  this->mohs = neuMohs;
  return;
}

string Location::getFill()
{
  return this->fill;
}
void Location::setFill(string neuFill)
{
  this->fill = neuFill;
  return;
}

string Location::getComment()
{
  return this->comment;
}
void Location::setComment(string neuComment)
{
  this->comment = neuComment;
  return;
}

//compare with other location
bool Location::compareXY(Location * otherLocation)
{
  bool isSame = false;
  if((this->xCoord == otherLocation->getXCoord())
     &&(this->yCoord == otherLocation->getYCoord()))
    {
      isSame = true;
    }
  return isSame;
}

int Location::XYtoIdex(int COLS)
{
  int idex = this->yCoord * COLS;
  idex += this->xCoord;
  return idex;
}

int Location::XYtoIdex(int x, int y, int ROWS, int COLS)
{
  //int uberLength = ROWS * COLS;
  int idex = y * COLS;
  idex += x;
  //cout << x << ',' << y << ',' << uberLength << ',' << idex << endl;
  return idex;
}


int Location::XYtoIdex(int x, int y, int COLS)
{
  return XYtoIdex(x,y,0,COLS);
}

bool Location::compareMohs(Location * otherLocation)
{
  //returns true if other Mohs is less than this mohs
  bool isLower = false;
  if(this->mohs < otherLocation->getMohs())
    {
      isLower = true;
    }
  return isLower;
}
bool Location::compareXYMohs(Location * otherLocation)
{
  bool same_XY_and_mohs = false;
  if(compareXY(otherLocation) && compareMohs(otherLocation))
    {
      same_XY_and_mohs = true;
    }
  return same_XY_and_mohs;
}
bool Location::compareMohsXY(Location * otherLocation)
{
  return compareXYMohs(otherLocation);
}
 
void Location::setOnMap(vector<Location*> & theMap, int ROWS, int COLS)
{
  srand(time(0));
  int posX = 0, posY = 0;
  int idex = 0;
  do{
    posY = rand() % ROWS;
    posX = rand() % COLS;
    idex = this->XYtoIdex(posX, posY, ROWS, COLS);
    //idex = 1;
  }while(theMap[idex]->getMohs() >= this->getMohs());
  this->setXCoord(posX);
  this->setYCoord(posY);
  theMap[idex]->setFill(this->getFill());
  //cout << "f" << this->getFill() << "m" << this->getMohs() << endl;
  theMap[idex]->setMohs(this->getMohs());
}

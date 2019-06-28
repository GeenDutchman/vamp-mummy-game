#include "Location.h"
//#include "Location.cpp"
#include "Creature.h"
//#include "Creature.cpp"
#include "Player.h"
#include "Vampire.h"
//#include "Player.cpp"
//#include "Vampire.cpp"

#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <vector>
//#include <allegro.h>
//#include 

using namespace std;

int getDense()
{
  const int MIN_DENSE = 0, MAX_DENSE = 30;
  int density = -15;
  while((density <= MIN_DENSE) || (density > MAX_DENSE))
    {
      cout << "\nHow dense do you want this? " << MIN_DENSE << "-"
	   << MAX_DENSE << ".\n:>";
      cin >> density;
    }
  cout << endl;
  cin.clear();
  return density;
}
bool getFlashlight()
{
  const char Y = 'Y', N = 'N', z = '0', un = '1';
  string input = "junk";
  char upper = toupper(input[0]);
  while((upper != Y) && (upper != N) && (upper != z) && (upper != un))
    {
      cout << "\nDo you want this in flashlight mode? Yes/No\n:>";
      cin >> input;
      upper = toupper(input[0]);
    }
  if((upper == Y)||(upper == un))
    {
      return true;
    }
  else
    {
      return false;
    }
  return false;
}

void initVamps(int diff, vector<Vampire*> & allVamps, vector<Location*> & theMap, int ROWS, int COLS)
{
  srand(time(0));
  //vector<Location*> allVamps;
  while(allVamps.size() < (unsigned int) diff + 1)
    {
      allVamps.push_back((Vampire*)NULL);
    }
  cout << endl;
  for(int i = 0;i <= diff;i++)
    {
      if(allVamps[i] == NULL)
	{
	  allVamps[i] = new Vampire();
	  //	  allVamps[i]->initCreature(theMap, ROWS, COLS);
	}
      allVamps[i]->initCreature(theMap, ROWS, COLS);
    }
  return;  
}

vector<Location*> initMap(int ROWS, int COLS, int dense)
{
  srand(time(0));
  const string WALL_FILL = "█";
  const int WALL_MOHS = 10;
  const string WALL_COMM = "A wall.\n";
  vector<Location*> aMap;//[ROWS * COLS];
  cout << endl;
  cout << "NEW MAP!!!\n";
  for(int i = 0;i<ROWS;i++)//y
    {
      for(int j = 0;j<COLS;j++)//x
	{
	  int o = (int)(rand() % (dense));
	  if((o >= 18)||(i == 0)||(j == 0)||(i >= ROWS -1)||(j >= COLS -1))
	    {
	      aMap.push_back(new Location(j,i,WALL_FILL,WALL_MOHS,WALL_COMM));
	    }
	  else
	    {
	      aMap.push_back(new Location(j,i));
	    }
	  cout << aMap[aMap.size() - 1]->getFill();
	}
      cout << endl;
    }
  return aMap;
}

void displayMap(vector<Location*> theMap, vector<Vampire*> vamps, Player* player, Location* goal, int ROWS, int COLS,bool flashlight)
{
  const int offset = 4;
  Location tempLocation;
  system("clear");
  theMap[goal->XYtoIdex(COLS)]->setFill(goal->getFill());
  tempLocation = player->getSpot();
  theMap[tempLocation.XYtoIdex(COLS)]->setFill(tempLocation.getFill());
  //cout << vamps.size() - 1 << endl;
  for(unsigned int j = 0;j < vamps.size();j++)
    {
      tempLocation = vamps[j]->getSpot();
      theMap[tempLocation.XYtoIdex(COLS)]->setFill(tempLocation.getFill());
    }
  tempLocation = player->getSpot();
  {
    unsigned int i = 0;
    bool done = false;
    for(i = 0;i < theMap.size();i++)
      {
	if(flashlight)
	  {
   	    if(!done)
	      {
		if((tempLocation.getXCoord() - offset >= 0) && (tempLocation.getYCoord() - offset >= 0))
		  {
		    i = (unsigned int)tempLocation.XYtoIdex((int)tempLocation.getXCoord() - offset, (int) tempLocation.getYCoord() - offset, COLS);
		  }
		else if((tempLocation.getXCoord() - offset >= 0) && (tempLocation.getYCoord() - offset < 0))//Y violation
		  {
		    i = (unsigned int)tempLocation.XYtoIdex((int)tempLocation.getXCoord() - offset, (int) 0, COLS);
		  }
		else if((tempLocation.getXCoord() - offset < 0) && (tempLocation.getYCoord() - offset >= 0))//X violation
		  {
		    i = (unsigned int)tempLocation.XYtoIdex(0, (int) tempLocation.getYCoord() - offset, COLS);
		  }
		else
		  {
		    i = 0;
		  }
		
		done = true;
	      }
	    if(i > (unsigned int)tempLocation.XYtoIdex((int)tempLocation.getXCoord() + offset, (int) tempLocation.getYCoord() + offset, COLS))
	      {
		i = theMap.size();
		break;
	      }
	  }
	if(!(i % (unsigned int)COLS))
	  {
	    cout << endl;
	    if(flashlight)
	      {
		i -= (unsigned int) 2* offset;
		i--;
		i += (unsigned int) COLS;
		if((i >= theMap.size()) || (i > (unsigned int)tempLocation.XYtoIdex((int)tempLocation.getXCoord() + offset, (int) tempLocation.getYCoord() + offset, COLS)))
		  {
		    i = theMap.size();
		    break;
		  }
	      }
	    cout << theMap[i]->getFill();
	  }
	else if (flashlight && ((i % (unsigned int) COLS) > (unsigned int)tempLocation.getXCoord() + offset))
	  {
	    cout << endl;
	    i -= (unsigned int)2 * offset;
	    i--;
	    i += (unsigned int)COLS;
	    if((i >= theMap.size()) || (i > (unsigned int)tempLocation.XYtoIdex((int)tempLocation.getXCoord() + offset, (int) tempLocation.getYCoord() + offset, COLS)))
	      {
		i = theMap.size();
		break;
	      }
	    cout << theMap[i]->getFill();
	  }
	else
	  {
	    cout << theMap[i]->getFill();
	  }
      }
  }
  cout << endl;
  cout << "PX:" << tempLocation.getXCoord() << "\t PY:" << tempLocation.getYCoord();
  cout << "\t GX:" << goal->getXCoord() << "\t GY:" << goal->getYCoord() << endl;
  cout << endl;
  return;
}

bool checkEnimies(vector<Location*> theMap, int COLS, Player* thePlayer, vector<Vampire*> theVamps)
{
  bool collision = false;
  for(unsigned int i = 0; i < theVamps.size();i++)
    {
      if(theVamps[i]->getSpot().XYtoIdex(COLS) == thePlayer->getSpot().XYtoIdex(COLS))
	{
	  collision = true;
	}
    }
  return collision;
}

bool checkGoal(vector<Location*> theMap, int COLS, Player* thePlayer, Location* theGoal)
{
  if(theGoal->compareXY(thePlayer->getSpotP()))
    {
      return true;
    }
  return false;
}


int main()
{
  const int ROWS = 30, COLS = 90;
  vector<Location*> theMap = {NULL};
  vector<Vampire*> theVamps = {NULL};
  Location* goalPtr = new Location(-1, -1, "@", 1, "GOAL!");
  Player* thePlayer = new Player();
  int dense = 0, diff = 0, movee = 0;
  signed char win = 0;
  bool flash = false;
  cout << "The Maze Game!  Avoid the Vampires *V* the Mummy *M* and get to the goal *@*!\n";
  cout << "You cannot go through solid blocks, and only the Mummy can get through it's Wrappings *W*\n";
  dense = getDense();
  flash = getFlashlight();
  do{
    theMap = initMap(ROWS, COLS, dense);
    system("pause");
    diff = thePlayer->getLevel();
    initVamps(diff, theVamps, theMap, ROWS, COLS);
    thePlayer->initCreature(theMap, ROWS, COLS);
    goalPtr->setOnMap(theMap, ROWS, COLS);
    do{
      displayMap(theMap, theVamps, thePlayer, goalPtr, ROWS, COLS, flash);
      movee = thePlayer->getMove(theMap, COLS, NULL);
      for(unsigned int i = 0; i < theVamps.size();i++)
	{
	  theVamps[i]->getMove(theMap, COLS, thePlayer->getSpotP());
	}
      if(checkEnimies(theMap, COLS, thePlayer, theVamps))
	{win = -1;}
      if(checkGoal(theMap, COLS, thePlayer, goalPtr))
	{win = 1;}
    }while((movee != 'Q') && (!win));
    displayMap(theMap, theVamps, thePlayer, goalPtr, ROWS, COLS, flash);
    if(win > 0)
      {
	cout << "\nYou have WON!!\n";
	thePlayer->setLevel(diff + 1);
	win = 0;
      }
    else if(win < 0)
      {
	cout << "\nYou have LOST\n";
	win = 0;
      }
    cin.ignore(100, '\n');
    system("pause");
  }while(movee != 'Q');
  cout << "Game Out.\n";
  system("pause");
  return 0;
}

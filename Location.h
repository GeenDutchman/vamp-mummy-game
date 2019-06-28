#pragma once

#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

class Location
{
 private:
  int xCoord, yCoord;
  int mohs;
  string fill;
  string comment;

 public:
  Location();
  Location(int x, int y);
  Location(int x, int y, string fill);
  Location(int x, int y, string fill, int mohs);
  Location(int x, int y, string fill, int mohs, string comment);
  ~Location();
  //getter-setter pairs
  int getXCoord();
  void setXCoord(int neuX);
  int getYCoord();
  void setYCoord(int neuY);

  int getMohs();
  void setMohs(int neuMohs);

  string getFill();
  void setFill(string neuFill);

  string getComment();
  void setComment(string neuComment);

  //compare with other location
  bool compareXY(Location * otherLocation);
  bool compareMohs(Location * otherLocation);
  bool compareXYMohs(Location * otherLocation);
  bool compareMohsXY(Location * otherLocation);

  int XYtoIdex(int COLS);
  int XYtoIdex(int x, int y, int COLS);
  int XYtoIdex(int x, int y, int ROWS, int COLS);

  void setOnMap(vector<Location*> & theMap, int ROWS, int COLS);
};

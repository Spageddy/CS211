#include <iostream>
#include "car.h"
using namespace std;

Car::Car(string mk, string md, int yr, string c, int mi, int bx,int by)
{ 
  make = mk;
  model = md;
  year = yr;
  color = c;
  miles = mi;
  x = bx;
  y = by;
}
void Car::goForward(int num)
{
  y += num;
  miles += num;
}

void Car::goBackward(int num)
{
  y -= num;
  miles += num;
}
void Car::goRight(int num)
{
  x += num;
  miles += num;
}
void Car::goLeft(int num)
{
  x -= num;
  miles += num;
}
void Car::repaint(string cl)
{
  color = cl;
}
string Car::getMake()
{
  return make;
}
string Car::getModel()
{
  return model;
}
int Car::getYear()
{
  return year;
}

int Car::getMiles()
{
  return miles;
}
string Car::getColor()
{
  return color;
}
int Car::getX()
{
  return x;
}
int Car:: getY()
{
  return y;
}


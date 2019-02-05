#include <string>
using namespace std;
#ifndef CAR_H
#define CAR_H
class Car
{
 private:
  string make;
  string model;
  int year;
  string color;
  int miles;
  int x;
  int y;

 public:
  Car(string ,string ,int ,string ,int ,int ,int ); 

  void goForward(int num);
  void goBackward(int num);
  void goRight(int num);
  void goLeft(int num);
  void repaint(string cl);
  string getMake();
  string getModel();
  int getYear();
  int getMiles();
  string getColor();
  int getX();
  int getY();

}; 
#endif

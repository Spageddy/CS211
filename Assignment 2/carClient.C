#include <iostream>
#include "car.h"

using namespace std;

void viewCar(Car& c);
int main()
{
  Car car1("Toyota", "Celica", 2016, "white", 0 ,0, 0);
  Car car2("Honda", "Civic", 2008, "black", 20000, 2, 2);

  car1.goForward(3);
  car2.goBackward(1);
  car1.goRight(2);
  car2.goLeft(5);
  viewCar(car1);
  car1.repaint("red");
  viewCar(car1);
  viewCar(car2);




  return 0;
}

void viewCar(Car& c)
{
  cout << c.getColor() << " " << c.getMake() << " " << c.getModel() << " " << "("<< c.getYear() << ") " << "is at location (" << c.getX() << "," << c.getY() << ")" << " with mileage " << c.getMiles() << " miles" << endl;

}

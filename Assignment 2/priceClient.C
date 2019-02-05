#include <iostream>
#include "price.h"
using namespace std;

int main()
{
  Price p1(2, 50);
  Price p2(3, 75);
  Price p3 = p1 + p2;
 
  cout << "The total price is" << p3.getDollar() << " dollars and " << p3.getCent() << " cents" << endl; //The total price is 6 dollars and 25 cents
  return 0;
}

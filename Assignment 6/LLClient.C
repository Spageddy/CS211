#include <iostream>
#include "LL.h"
using namespace std;

int main()
{
  LList l;
 
 l.addFront(1);
 l.addFront(2);
 l.addFront(3);
 l.addRear(4);
 l.addRear(5);

 l.displayAll();
 cout << endl;

 cout << l.deleteFront() << " has been deleted" << endl;
 cout << l.deleteRear() <<  " has been deleted" << endl;

 l.displayAll();
 cout << endl;

 cout << l.deleteFront() << " has been deleted" << endl;
 cout << l.deleteRear() <<  " has been deleted" << endl;

 l.displayAll();
 cout << endl;

  cout << l.deleteFront() << " has been deleted" << endl;
 
  l.displayAll();
 cout << endl;

 l.addRear(10);
 l.addFront(11);

 l.displayAll();
 cout << endl;

 cout << l.deleteRear() <<  " has been deleted" << endl;
 cout << l.deleteRear() <<  " has been deleted" << endl;

 l.displayAll();
 cout << endl;

 return 0;
}

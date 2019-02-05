#include <iostream>
#include "queue.h"
#include "inputCheck.h"
using namespace std;

int main()
{
  Queue myLine; // myLine is a new queue object
  char userans,eltoadd;

  cout << "Enter your choice Y to add a new element or N when you are done";
  //my getResponse() in inputCheck.h returns either Y or N (returns uppercase)
  userans = getResponse("Invalid choice. Enter Y or N only: ");
  while (userans == 'Y' && !myLine.isFull() )
    {
      cout << "Give me an element to add: ";
      cin >> eltoadd;
      myLine.add(eltoadd);

      cout << "Enter your choice Y to add a new element or N when you are done.";
      userans = getResponse("Invalid choice. Enter Y or N only: ");
    }// end of while
  
  cout << "The line has " << myLine.getSize() << " elements." << endl;
  cout << "Now removing and displaying all elements…" << endl;
  
while ( !myLine.isEmpty())
    cout << myLine.remove() << endl;
}//end of mai

//Eduardo Martinez
//CS211 Assignment 5
//LL Class - Implementation File
#include "LL.h"
#include <iostream>
using namespace std;

// PURPOSE: constructor which initializes top
LList::LList()
{
  count = 0;
  front = NULL;
  rear = NULL;

}
// PURPOSE: destructor- does nothing
LList::~LList()
{
  while(!isEmpty())
    deleteFront();
}
// PURPOSE: to add element to rear of the queue                                            
// PARAMS: new element el of type el_t                                                     
// ALGORITHM: adds element to rear of queue,    
void LList::addRear(el_t el)
{
  if(count != 0)
    {
      rear->next = new node; // make the rear node point to a new node
      rear = rear->next; // rear points to the new one
    }
  else
    front = rear = new node;
  
  rear->elem = el; // the last node points to nothing
  rear->next = NULL; 
  count++;
}
// PURPOSE: to Remove the front element of queue                                           
// ALGORITHM: deletes and returns front, next node becomes fron    
el_t LList::deleteFront()
{
 node* second; 
 el_t ch= front->elem;
  if(isEmpty())
    queueError("Error: list is empty");
    
 second = front->next; // front's next pointer is saved
 delete front; // front node is gone
 front = second; // front pointer points to the new front node.
 count--;
 return ch;  // what's in the front node?
    
}
// PURPOSE: to check if the queue is empty                                                 
// ALGORITHM: if count = 0 then returns true 
bool LList::isEmpty()
{
  if(count == 0)
    return true;
  else
    return false;
}

// PURPOSE: to display all elements in the queue                                           
// ALGORITHM: displays element and points to next node 
void LList::displayAll()
{
  //  if(isEmpty())
  //queueError("queue is empty");

  node* p = front;
  while(p != NULL)
    {
      cout << (el_t)p->elem ;
      p=p->next;
    }    
}
// PURPOSE: (private) to handle unexpected errors encountered by other methods             
// PARAMS: a string message to be displayed                                                
// ALGORITHM: simply cout the message and exit from the program  
void LList::queueError(string msg)
{
  cout << msg << endl;
  //  exit(1);
}
// PURPOSE: to output elements in reverse order                                            
// ALGORITHM: recursive function that outputs elements in reverse
void LList::printAllReverse()
{
  printAllReverse(front);
}
// PURPOSE: to output elements in reverse order                                            
// ALGORITHM: returns if p is pointing at NUll, outputs element  
void LList::printAllReverse (node* p)
{
 if(p == NULL)
    return;
  else
    {
      printAllReverse (p->next);
      cout << (el_t)p->elem;
    }
}
 
void LList::addFront(el_t e)
{
  node* newFront;
  if(isEmpty())
    addRear(e);
  else
    {
      newFront->next= front;
      front = newFront;
      Front->elem = e;
    }
}
el_t LList::deleteRear()
{
  if(isEmpty())
    queueError("queue is empty");
  else
    {
      node* pre;
      node* del;
      pre = front;
      del = front->next;
      for(int i =0; i<=count ;i++)
	{
	  if(count == 1)
	    deleteFront();

	  if(del->next == NULL)
	    {
	      el_t el = rear->elem;
	      delete rear;
	      rear = pre;
	      rear->next = NULL;
	      return el;
	    }

	      pre = pre->next;
	      del= del->next;
	    
	}
    }
//Eduardo Martinez
//CS211 Lab 6 Assignment 4
//Queue class - implementation file
// ======================================================
#include "queue.h"
#include <iostream>
using namespace std;

// PURPOSE: constructor which initializes top
Queue::Queue()
{
  count = 0;
  front = 0;
  rear = -1;
}
// PURPOSE: (private) to handle unexpected errors encountered by other methods
// PARAMS: a string message to be displayed
// ALGORITHM: simply cout the message and exit from the program
void Queue::queueError(string msg)
{
  cout << msg << endl;
  exit(1);
}
// PURPOSE: Checks if queue is empty
// ALGORITHM: if count equals 0 returns true, else returns false
bool Queue::isEmpty()
{
  if(count == 0)
    return true;
  else
    return false;
  
}
// PURPOSE: checks if queue is Full
// ALGORITHM: if count is greater than queue size, then returns tru
// else returns false
bool Queue::isFull()
{
  if(count > QUEUE_SIZE)
    return true;
  else
    return false;
}
// PURPOSE: to add a passed element to the queue
// PARAMS: new element n of type el_t
// ALGORITHM: if not full, increment count and change rear
// else queueError is called
void Queue::add(el_t e)
{
  if(isFull())
    queueError("queue is Full");
  else
    {
      rear = (rear + 1) % QUEUE_SIZE;
      el[rear]= e;
      count++;
    }
}
// PURPOSE: to remove element from queue
// ALGORITHM: if not empty, decrement count, change front, and return removed  
// else stackError is called
el_t Queue::remove()
{
  if(isEmpty())
    queueError("queue is empty");
  else
    {
    count--;
    el_t e= el[front];
    front = (front + 1) % QUEUE_SIZE;
    return e;
    }
}
// PURPOSE:get front of queue without removing
// ALGORITHM: if not empty, returns front of queue
el_t Queue::getFront()
{
  if(isEmpty())
    queueError("queue is empty");
  else
    {
      return el[front];
    }
}
// PURPOSE: takes front and adds to the rear of queue
// AlGORITHM: if not empty, adds removed element to queue
// if size is 1 then does nothing
void Queue::goToBack()
{
  if(isEmpty())
    queueError("Queue is empty");
  else if(count == 1)
    {}
  else
    {
      el_t e = remove();
      add(e);
    }
}
// PURPOSE: returns the size of the queue
int Queue::getSize()
{
  return count;
}
// PURPOSE: Displays all elements in queue
/*
void Queue::displayAll()
{
  while(!isEmpty())
    {
      for(int i = front; i <= rear; i++)
	{
	  cout << "[" <<  el[i] << "]";
	}
    }
} 
*/

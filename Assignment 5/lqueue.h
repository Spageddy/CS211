//Eduardo Martinez
//CS211 Assisgnment 5
//LQueue class - header file

#ifndef LQUEUE_H
#define LQUEUE_H
#include <string>
using namespace std;

typedef int el_t; // el_t is an alias for char


// This declares a new type of structure called node.
// Each node of a linked list will be of this type.
struct node
{
  int elem; // element at this node is an integer
  node* next; // a link (pointer) to the next node
};

class LQueue
{
 private:
  // Data members are:
  int count; // how many elements do we have right now?
  node* front; // where the front element of the queue is.
  node* rear; // where the rear element of the queue is. 
  // PURPOSE: (private) to handle unexpected errors encountered by other methods
  void queueError(string msg);
 
 public:
  LQueue(); // constructor
  ~LQueue(); // destructor
  // HOW TO CALL: pass an element to be added
  // PURPOSE: to add element to rear of the queue
  void addRear(el_t el);
  // PURPOSE: to Remove the front element of queue 
  el_t deleteFront();
  // PURPOSE: to check if the queue is empty
  bool isEmpty();
  // PURPOSE: to display all elements in the queue
  void displayAll();
  // PURPOSE: to output elements in reverse order 
  void printAllReverse();
  // PURPOSE: to output elements in reverse order
  void printAllReverse(node* p); 
};

#endif

//Eduardo Martinez
//CS211 Assisgnment 5
//LList - header file

#ifndef LL_H
#define LL_H
#include <string>
using namespace std;

typedef int el_t; // el_t is an alias for int


// This declares a new type of structure called node.
// Each node of a linked list will be of this type.
struct node
{
  el_t elem; // element at this node is an integer
  node* next; // a link (pointer) to the next node
};

class LList
{
 private:
  // Data members are:
  node* front; // where the front element of the queue is.
  node* rear; // where the rear element of the queue is. 
  // PURPOSE: (private) to handle unexpected errors encountered by other methods
  void queueError(string msg);
 
 public:
  LList(); // constructor
  ~LList(); // destructor
  // HOW TO CALL: pass an element to be added
  // PURPOSE: to add element to rear of the queue
  void addRear(el_t el);
  // PURPOSE: to Remove the front element of queue 
  el_t deleteFront();
  //HOW TO CALL:retursn true if the list is empty
  // PURPOSE: to check if the queue is empty
  bool isEmpty();
  //HOW TO CALL: outputs all the elements in the linked list
  // PURPOSE: to display all elements in the queue
  void displayAll();
  //HOW TO CALL: outputs all elements in linked list
  //in reverse order
  // PURPOSE: to output elements in reverse order 
  void printAllReverse();
  // PURPOSE: to output elements in reverse order
  void printAllReverse(node* p); 
  //HOW TO CALL:pass an element to be added to the front        
  //PURPOSE: to add element to the front 
  void addFront(el_t el);
  //HOW TO CALL: returns deleted rear
  //Purpose: to remove rear node                                                 
  el_t deleteRear();

};

#endif

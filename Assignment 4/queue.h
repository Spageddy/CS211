//Eduardo Martinez
//CS211 Lab 6 Assignment 4
//Queue class - header file
// ======================================================
#ifndef QUEUE_H
#define QUEUE_H
#include <string>
using namespace std;



//create an enumuration type                                                                                                                                                         
enum op {ADD, SUB, MULT, DIVI};

//create a struct that will have an operand, a operator, another operand 
struct expr
{
  int oprd1;
  op oprt;
  int oprd2;
};

typedef expr el_t; // el_t is an alias for char 
const int QUEUE_SIZE = 10; // this is the max number of elements the queue can have    

class Queue
{
 private:
  // Data members are:
  el_t el[QUEUE_SIZE]; // a character array called el
  int count; // how many elements do we have right now?
  int front; // where the front element of the queue is.
  int rear; // where the rear element of the queue is.
  // a private utility function for fatal error cases
  // This displays an error messages passed to it and does exit(1);
  void queueError(string msg); 
 public:
  // constructor
  Queue();
  // PURPOSE: if empty returns true, if not empty returns false 
  bool isEmpty();
  // PURPOSE: if full returns true, if not full returns false
  bool isFull();
  // HOW TO CALL: pass an element to be added to the queue
  // PURPOSE: if full, calls an emergency exit routine
  // if not full, changes rear to the next slot and enters an element at rear
  void add(el_t);
  // PURPOSE: if empty, calls an emergency exit routine
  // if not empty, remove(return) the front element and change front to the next slot
  el_t remove();
  // PURPOSE: if empty, calls an emergency exit routine
  // if not empty, return the front element (but does not remove it)
  el_t getFront();
  //PURPOSE: if empty, calls an emergency exit routine
  //if queue has just 1 element, does nothing
  //if queue has more than 1 element, moves the front one to the rear
  void goToBack();
  // PURPOSE: returns the current size
  int getSize();
  //PURPOSE: display everything in the queue from front to rear enclosed in []. E.g. [a][b][c]
  //Do not call the emergency exit routine when the queue is empty.
  void displayAll();
};

#endif

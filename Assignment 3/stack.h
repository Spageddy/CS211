//Eduardo Martinez
//CS211 Lab5, assignment 3
//Stack class - header file
#ifndef STACK_H
#define STACK_H
#include <string>
using namespace std;

typedef int el_t;// the element type, el_t, is int
const int MAX = 5;//The MAX number of elements for the stack

class Stack
{
 private:
  el_t st[MAX]; // st is an array of el_t's
  int top; // the index to the top element
  void stackError(string msg);//utility function for error handling
 public:
  Stack(); //Constructor
  // PURPOSE: returns true if empty and false if not empty.
  bool isEmpty();
  // PURPOSE: returns true is full and false if not full
  bool isFull();
  // HOW TO CALL: pass an element to be pushed
  // PURPOSE: if not full, enters an element at the top.
  // otherwise, calls an emergency exit routine
  void push(el_t);
  // HOW TO CALL: pops last element on stack
  // PURPOSE: if empty calls an emergency exit routine                                            
  //if not empty, removes an element from the top
  el_t pop(); 
  // HOW TO CALL: pops the top element on stack
  // PURPOSE: if empty calls an emergency exit routine                                       
  //if not empty, removes an element from the top 
  el_t topElem();
  // HOW TO CALL: displays all elements in stack
  // PURPOSE: uses for loop to ouput all elements in stack 
  void displayAll();
  // PURPOSE: pops top element on stack until empty to clear the stack
  void clearIt();
};
#endif

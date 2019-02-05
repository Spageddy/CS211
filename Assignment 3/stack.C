//Eduardo Martinez
//CS211 Lab 5, Assignment 3
//Stack class - implementation file
#include "stack.h"
#include <iostream>
using namespace std;

// PURPOSE: constructor which initializes top
Stack::Stack()
{
  top = -1;
}
// PURPOSE: to check if stack is empty
// ALGORITHM: checks if top is less than 0  
// if true then returns true, if false returns false  
bool Stack::isEmpty()
{
   if (top < 0)
     return true;
   else
     return false;
}
// PURPOSE: to check if stack is full
// ALGORITHM: checks if top is greater than or equal to MAX - 1
// if true then returns true, if false returns false
bool Stack::isFull()
{

  if(top >=  MAX-1)
    return true;
  else
    return false;
}
// PURPOSE: to push a passed element to the stack
// PARAMS: new element n of type el_t
// ALGORITHM: if not full, increment top and place n there.
// else stackError is called
void Stack::push(el_t elem)
{
  if (isFull())//stack is full
    stackError("stack overwflow");
  else//stack is not full
    {
      st[++top] = elem;
    }
}
// PURPOSE: to pop last element on the stack
// ALGORITHM: if not empty, return top elem on stack and decrement top.
// else stackError is called
el_t Stack::pop()
{
  if (isEmpty())
    stackError("stack underflow");
  else
    return st[top--];
}
// PURPOSE: to pop last element on the stack 
// ALGORITHM: if not empty return top element on stack.
// else stackError is called
el_t Stack::topElem()
{
  if (isEmpty())
    stackError("stack is empty");
  else
    return st[top];
}
// PURPOSE: to handle unexpected errors encountered by other methods
// PARAMS: a string message to be displayed
// ALGORITHM: simply cout the message and exit from the program
void Stack::stackError(string msg)
{
  cout << msg << endl;
  exit(1); //ends the program. 1 is returned to the operating system.
  //0 = end with no errors, 1 = end with errors
}
// PURPOSE: to show all elements in stack
// ALGORITHM: goes through a for loop to output elements in stack
void Stack::displayAll()
{
  for(int i =top; i > -1; i--)
      cout << st[i] << endl;
}
// PURPOSE: to clear the stack
// ALGORITHM: while the stack is not empty it pops and item from the stack
void Stack::clearIt()
{
  while(!isEmpty())
    pop();
}

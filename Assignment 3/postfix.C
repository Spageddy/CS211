/*
Eduardo Martinez
CS 211 Lab 5-2, Assignment 3
postfix- the purpose of the program is to get an input expression from the user.
every character from the expression is checked if its an operand,operator, or invalid item.
if its an operand then it pushed onto the stack until an operator shows up. if an error
occurs then "invalid expression" is output.
*/

#include <iostream>
#include <string>
#include<cstring>
#include "stack.h"
using namespace std;



bool isOperand(char ch);
int charToInt(char ch);
bool isOperator(char ch); 
int doMath(int opr1, char opt, int opr2);



int main()
{
  Stack stk;
  char curItem;
  int i=0;
  int ans;
  bool error = false; //for any errors that may occur
  string expr;
  cout << "Enter the expression: ";
  cin >> expr;
  char * cstr= new char[expr.length()+1];//turns the string to c-string
  strcpy (cstr,expr.c_str());//copies the string into cstr
  
 
while(cstr[i] != '\0' && !error)
   {
     curItem = cstr[i];//current item from the c-string
     if(isOperand(curItem))//is its an operand
       {
	 if(!stk.isFull())
	   stk.push(charToInt(curItem));//pushes to stack if stack isnt full
	 else
	    error =true; //stack is full
       }
     else if(isOperator(curItem))//if its an opertator then it does the math
       {                         //and pushed on to stack 
	 int op1,op2;
	 if(!stk.isEmpty())// pops last item from stack if its not empty
	   op1 = stk.pop();
	 else
	     error = true;//stack is empty
	 if(!stk.isEmpty())// pops last item from stack if its not empty
           op2 = stk.pop();
         else
	     error = true;//stack is empty
	 if(!stk.isFull())// checks if stack is full
	   stk.push(doMath(op1,curItem,op2));// does math of two last popped items 
	 else                               // and pushes answer onto stack 
	     error = true;//stack is full
       }
     else //invalid item
	 error = true;
     i++;//increments to get next item from c-string
   }
 if(!stk.isEmpty())//pops last item if stack isnt empty
   ans = stk.pop();
 else 
         error = true;
  
 if(!error && stk.isEmpty())//if there arent any errors and stack is empty then pops answer
   cout << "the answer is: " << ans << endl;
  else 
    cout << "invalid expression" << endl;// if stack isnt empty or there was an error then 
                                         // the expression is invalid  

  return 0;
}

bool isOperand(char ch)//checks if its an operand
{
  if(ch <= 57 && ch >=48)// subtracts to check is its 0-9
    return true;
  else
    return false;
}
int charToInt(char ch)// converts char to int
{
  int num= 48;//ascii 0 is 48
  num = (int)ch - num;//subtract to convert to int
  return (num);
}
bool isOperator(char ch)// checks if its an operator
{
  if(ch == '+' || ch == '-' || ch == '*' || ch == '/') //ch is an operator
    return true;
  else //ch is not an operator
    return false;
}
int doMath(int opr2, char opt, int opr1)//does math
{
  int answer;
  if(opt == '+')
    answer = opr1 + opr2;
  else if(opt == '-')
    answer = opr1 - opr2;
  else if(opt == '*')
    answer = opr1 * opr2;
  else if (opt == '/')
    answer = opr1 / opr2;

  return answer;//returns answer
}

//Eduardo Martinez
//CS211 Assignment5
//LQueue Client File
//the purpose of the lab is to add 2 large int numbera
#include <iostream>
#include <string>
#include "lqueue.h"
#include <stdlib.h>
using namespace std;

//creates in reverse an lqueue with one number in each node
void createReverseLL(LQueue& l, string s);
//adds both l1 and l2 and sum goes into total
void addLLs(LQueue& total,LQueue& l1,LQueue& l2);
int main()
{
  LQueue l1,l2,total;//create lqueue objects
  string s1,s2;//create string 
 

  cout << "enter a positive integer" << endl;
  cin >> s1;//user inputs int
  createReverseLL(l1,s1);
  cout << "enter a positive integer" << endl;
  cin >> s2;//user inputs int
  createReverseLL(l2,s2);//creates and reverses 

  l1.displayAll();//display all the numbers in l1 
  cout << " + ";
  l2.displayAll();//display all the number in l2
  cout << " = ";
  addLLs(total,l1,l2);//adds l1 and l2 together, sum goes into total
 
  total.displayAll();// displays the total in reverse
  cout  << endl;
 

  createReverseLL(l1,s1);
  createReverseLL(l2,s2);
  l1.printAllReverse();//prints l1 in reverse order
  cout << " + ";
  l2.printAllReverse();//prints l2 in reverse order
  cout << " = ";
  total.printAllReverse();// prints total in reverse order
  cout << endl;
  return 0;

}
void createReverseLL(LQueue& l, string s)
{
  char cstr[s.length()+1];//creates a c-string
  strcpy (cstr, s.c_str());//copies the string int cstr
 
  for(int x= s.length()-1; -1 < x; x--)
    {
      l.addRear((cstr[x]-48));//adds the int value to rear of queue
    }

}
void addLLs(LQueue& total,LQueue& l1,LQueue& l2)
{
  int r=0;//
  int sum,n1,n2;

  while(!l1.isEmpty() || !l2.isEmpty())
    {
      if(l1.isEmpty())//l1 is empty
	{
	  n1=0;//l1 is empty
	  n2=l2.deleteFront();//l2 is not empty
	}
      else if(l2.isEmpty())//l2 is empty
	{
	  n1 =l1.deleteFront();//l1 is not empty
	  n2=0;//l2 is empty
	}
      else if(!l1.isEmpty() && !l2.isEmpty())
	{
	  n1 =l1.deleteFront();//l1 is not empty
	  n2=l2.deleteFront();//l2 is not empty
	}

      sum=n1+n2+r;//sum of l1, l2, and carry over
      r=sum/10;//if sum >= 11 then 1 is carried over to next sum
      total.addRear(sum%10);// number is added to rear of total
    }       
  if(r>0)//if the last sum is >=10 
	total.addRear(r);
     
}

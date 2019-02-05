//Eduardo Martinez
//CS 211 - Assignment 6
//Palindrome.C - check if a string is a palindrome.The program getsa string from 
//the user, makes a linked list from the string(only adding char), then deletes and 
//check if front and rear are equaluntil linked list is empty. if front and rear are
// not equal, the funtcion returns false 
#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h> 
#include "LL.h"
using namespace std;

void createLL(LList& l,string s);
bool palindrome(LList& l);
int main()
{
  LList l;//linked list
  string s;
  bool isPal;//bool for it is a palindrome or not
  cout << "********PALINDROME CHECKER********" << endl;
  cout << "Enter Palindrome:" <<endl;
  getline(cin,s);//gets input
  createLL(l,s);//creates the linked list from the user
 
  isPal=palindrome(l);
  if(isPal)//if it is a palindrome
    {
      cout << endl;
      cout << " Yea, its a palindrome" << endl;
    }
  else//if not
    {
      cout << endl;
      cout << "Noo, its not a palindrome!" << endl;
    }


  return 0;
}
void createLL(LList& l,string s)
{
  char c[s.length()+1];//create cstring
  strcpy(c,s.c_str());//copy stringt to the cstring
    
  for(int i=0; i<= s.length();i++)
    {
      
      int x=(int)c[i];
      if(x>96 && x<123)//if x is a lowercase integer
	x -= 32;//makes it uppercase
      if(x>54 && x<133)
	l.addRear(x);//adds to link list only if its an uppercase char
    }
}

bool palindrome(LList& l)
{
  bool pal = true;
  while(!l.isEmpty())//while it not empty
    {
      int a= l.deleteFront();
      if(l.isEmpty())//if empty the link list must only have 1 element
	{
	  //do nothing
	}
      else
	{
	  if(a != l.deleteRear())//checks if front and rear are the same
	    pal = false;//if not
	}

    }
  return pal;
}

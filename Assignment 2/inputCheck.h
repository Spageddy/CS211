#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
//prototypes here                                                                                          
char getLetter(string msg);
char getResponse(string msg);
char getGender(string msg);
int getNumberInRange(int low, int high, string msg);

//CHECKS RESPONSE FOR GENDER & Y OR N                                                                      
char getLetter(string msg)
{
  string input;
  cin >> input;

  while(input.length() != 1 || !isalpha(input[0]))
    {
      cout << input << " is invalid. " << msg;
      cin >> input;
    }
  return input[0];
}
char getResponse(string msg)//y or n                                                                       
{
  char  ch;
  ch = getLetter(msg);

  while(toupper(ch) != 'Y' && toupper(ch) != 'N')
    {
      cout << ch <<  " is invalid. " <<  msg;
      ch = getLetter(msg);
    }
  return toupper(ch);
}
char getGender(string msg)//m or f                                                                         
{
  char  ch;
  ch = getLetter(msg);

  while(toupper(ch) != 'F' && toupper(ch) != 'M')
    {
      cout << ch <<  " is invalid. " <<  msg;
      ch = getLetter(msg);
    }
  return toupper(ch);
}
int getNumberInRange(int low, int high, string msg)
{
  string input;
  bool nonNumber;
  bool invalid;
  int inpt;
  cin >> input;
  do
    {
      
      char * cstr =new char[input.length()+1];
      strcpy (cstr, input.c_str());
      inpt = atoi(cstr);
      nonNumber = false;
      invalid = false;
      //check each character in "input" and if a non-digit character is found, set "nonNumber" to true      
      for(int i = 0; i < input.length(); i++)
	{
	  if(!isdigit(cstr[i]))
	    {
	      nonNumber = true;
	    }
	  
	}
      
      
      
      
      if(nonNumber == true || inpt > high || inpt < low)
	{
	  
	  invalid = true;
	}
      
      //if .invalid. is true, ask for a new input                                                           
      if(invalid) //same as invalid == true                                                                 
	{
	  cout << msg;
	  cin >> input;
	  
	}
      
    }while(invalid);
  //returning a valid integer between low and high                                                          
  return inpt;
}


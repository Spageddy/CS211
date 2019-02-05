/*
Eduardo Martinez
CS211 Lab 6, Assignment 3
Fibonacci- the purpose of the program is to find the fibonacci number of given
position and output the time to see the effiecency of non-recursives solutions
*/
#include <iostream>
#include <time.h>
using namespace std;

int fib(int x);
int fibnoacci(int x);

int main()
{
  clock_t start, end;
  int pos;
  cout << "Enter a position: ";
  cin >> pos;
  int fibNum;
  //start timing
  start = clock();
  fibNum =  fib(pos);

  end = clock();
  cout << "Elapsed time: " << (end - start) / double(CLOCKS_PER_SEC) * 1000 << " milliseconds" << endl;
  cout << "Fibonnaci number at position " << pos << " is " << fibNum << endl;
 
 start = clock();
 fibNum = fibnoacci(pos);
 end = clock();
 cout << "Elapsed time: " << (end - start) / double(CLOCKS_PER_SEC) * 1000 << " mil\
liseconds" << endl;
 cout << "Fibonnaci number at position " << pos << " is " << fibNum << endl;

  return 0;
}
int fib(int x)
{
  if (x <= 1)
    return x;
  else 
    return fib(x-2)+fib(x-1);
  
}

int fibnoacci(int x)
{
  int ans;
  int n1= 0;
  int n2= 1;
  for (int i=0; i<x ; i++)
    {
      if(i < 1)
	{
	  ans= i;
	}
      else
	{
	  ans= n1 +n2;
	  n1= n2;
	  n2 =ans;
	}
    }
  return ans;
}

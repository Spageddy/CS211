#include <iostream>
#include <iomanip>
#include "inputCheck.h"
using namespace std; 

struct student
{
  int id;
  string name;
  char gender;
  string major;
  int age;
};


int getStuData(student a[]);
int findID(int num,int look,student a[]);
void displayStu(student a);
void findYoungOld(student a[],int num ,int& young,int& old);
void displayAllStu(student a[],int num);
void displayStud(student a);

const int MAX = 2;

int main()
{
  student ar[MAX];
  int num = getStuData(ar); 
  int look;

  if(num == 0)
    {
      cout << "Theres no students." << endl;
      cout << "Bye" <<endl;
      exit(0);
    }
    cout << "Enter the id you are looking for: ";
    cin >> look;
   
    
    int found = findID(num,look,ar);    
    int young = 999;
    int old = -1;

    findYoungOld(ar,num,young,old);

    cout << "*******************************************" << endl;
    cout << "The youngest student is " << young << " years old" << endl;
    cout << "The oldest student is " << old << " years old" << endl;
    cout << "*******************************************" << endl;
    
    displayAllStu(ar,num);
    
  return 0;
}

int getStuData(student a[])
{
  int i=0;
  string msg1= "Enter Y or N: ";
  string msg2= "Enter M or F: ";
  cout << "Enter student info? Y or N :";
  char ans = getResponse(msg1);

        while (ans == 'y' || ans == 'Y')
	{
	  if(i>=MAX)
	    {
	      cout << "ARRAY IS FULL!!!" << endl;
	      ans= ' ';
	    }
	  else
	    {
	      cout << "Enter student id: ";
	     a[i].id = getNumberInRange(1, 9999, "Invalid. Enter a score between 0 and 100 only: ");
	      cin.ignore();
	      cout << "Enter student name: ";  
	      getline(cin,a[i].name);
	      cout << "Enter student gender: ";
	      a[i].gender = getGender(msg2);
	      cout << "Enter student major: ";
	      cin.ignore();
	      getline(cin,a[i].major);
	      cout << "Enter student age : ";
	      a[i].age = getNumberInRange(0, 150, "Invalid. Enter a score between 0 and 100 only: ");	      
	      cout << "Enter student info? Y or N: ";
	      ans= getResponse(msg1);
	      i++;
	    }
	}
   
  student Default = {0, " ", ' ', " ", 999}; //defalut values

  for(int x = i; x < MAX; x++)                 
    {
      a[x] = Default;
    }   


return i;
}

int  findID(int num,int look,student a[])
{
  for(int i=0; i< num;i++)
    {
      if(look == a[i].id)
	{
	  displayStu(a[i]);
	  return i;
	}
    }
  cout << "Id was not found" << endl;

}

void displayStu(student a)
{
  cout << "****************************" << endl;
  cout << "Student id: " << a.id << endl;
  cout << "Student name: " << a.name << endl;
  cout << "Student gender: " << a.gender << endl;
  cout << "Student major: " << a.major << endl;
  cout << "student age : " << a.age << endl;
  cout << "****************************" << endl;

}

/*This function will return the youngest and oldest ages */
void  findYoungOld(student a[],int num,int& young,int& old)
{
  for(int i=0; i < num;i++)
    {
      if(a[i].age < young)
	{
	  young = a[i].age;
	}
      if(a[i].age > old)
	{
	  old = a[i].age;
	}
    }
}
//DISPLAY ALL STUDENTS
void displayAllStu(student a[],int num)
{
  cout << setw(10)<< left << "ID" << setw(15) << "Name" << setw(10) << "Gender" << setw(10) << "Major" << setw(10) << "Age" << endl;
  for(int i= 0;i < num; i++)
    {
      displayStud(a[i]);
    }
}
void displayStud(student a)
{
  cout <<  setw(10) << a.id << setw(15) << a.name << setw(10) << a.gender << setw(10) << a.major << setw(10)<< a.age << endl;
}

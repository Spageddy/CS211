#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>  //include vector.h
using namespace std;
#include "student.h"
#include "inputCheck.h"

void showMenu();
void addStudentsFromFile(vector<Student>& s1);
void addOneStudent(vector<Student>& s2);
void printAllStudents(vector<Student>& s3);
void addCourseToStudent(vector<Student>& s4);
void dropCourseFromStudent(vector<Student>& s5);

int main()
{
  cout << "\n *** TEST: the number of students at the beginning is " << Student::getNumStu() << endl;
 
  vector<Student> s; //declare a vector of students  
  int choice;
  do
  {
    
    showMenu();
    cout << "Enter your choice ----> ";
    choice = getNumberInRange(1, 6, "Invalid choice. Enter 1 through 6: ");

    switch(choice)
      {
      case 1:
	  addStudentsFromFile(s);
	  break;
      case 2:
          addOneStudent(s);
	  break;
      case 3:
	  printAllStudents(s);
	   cout << "\n *** TEST: the number of students is " << Student::getNumStu() << endl;
	break;
      case 4:
	addCourseToStudent(s);
	break;
      case 5:
	dropCourseFromStudent(s);
	break;
      case 6:
	cout << "Ending the program ..............." << endl;
      }
  }while(choice != 6);


  cout << "\n *** TEST: the number of students at the end is " << Student::getNumStu() << endl;

  return 0;
}

 void showMenu()
 {
   cout << "\n*****************************************************************" << endl;
   cout << "1: Add students from a file" << endl;
   cout << "2: Add one student" << endl;
   cout << "3: Print all students" << endl;
   cout << "4: Add a course to a student" << endl;
   cout << "5: drop a course from a student" << endl;
   cout << "6: End the program" << endl;
 }

//This function adds students from an input file
//e.g. for input file (for each student, first last gen)
//  Mike Smith M
//  Kathy Ross F
void addStudentsFromFile(vector<Student>& s1)
{
  string fileName;

  cout << "Enter the file name: ";
  cin >> fileName;

  ifstream fin;
  fin.open(fileName.c_str()); //open the file

  if(!fin)
    {
      cout << fileName << " doesn't exist " << endl;
    }
  else//The file exists
    {
      string fn, ln;
      char gn;
   
      fin >> fn >> ln >> gn;//read the first student
      while(fin)//if reading was successful, enter the while
	{
	  Student ob(fn,ln,gn);//create a new student with the data from input
	  s1.push_back(ob); //add it to the vector
	  fin >> fn >> ln >> gn; //read the next student
	}
    }
}

//This function adds one student to the vector.
void addOneStudent(vector<Student>& s2)
{
      string fn, ln;
      char gn;

      cout << "Enter the student's first name: ";
      cin >>fn;
      cout << "Enter the student's last name: ";
      cin >>ln;
      cout << "Enter the student's gender: ";
      gn = getGender("Invalid input. Enter M or F: ");

      Student ob1(fn,ln,gn); //create a new student with the data from the user's input
      s2.push_back(ob1); //add the new student to the vector
}
 
//Print the information about all the students
void printAllStudents(vector<Student>& s3)
{
  //Show the labels
  cout << left << setw(10) << "Id" <<  setw(10) << "First" << setw(10) << "Last" << right << setw(10) << "Fee" << left << setw(10) << "  Courses" << endl; 

  //Go through each student in the vector
  for(int n = 0; n < s3.size() ; n++)
    {
      cout <<  setw(10) << s3[n].getId() << setw(10) << s3[n].getFirstName() << setw(10) << s3[n].getLastName() << right << setw(7) << s3[n].getDollar() << ".";

      //If the cent is less than 10, show a 0 first.
      //e.g. cent = 3, 03 will be shown.
      if(s3[n].getCent() < 10)
	cout << "0";
      cout << s3[n].getCent();
      
      //show all courses the student is enrolled in
      cout << left << "  ";
      vector<int> co = s3[n].getCourses(); //get the vector of courses for this student
      for(int c = 0; c < co.size(); c++)
        cout << setw(6) << co[c];

      cout << endl;
    }
}

//Add a new course to a student.
//Charge $50.10 per course
void addCourseToStudent(vector<Student>& s4)
{

  bool fnd=false;
  bool exist;
  int num;

  cout << "Enter the student id: ";
  int id = getNumberInRange(1, 99999, "Invalid id. Enter the student id: ");
  cout << "Enter the CRN: ";
  int crn = getNumberInRange(1, 99999, "Invalid CRN. Enter the CRN: ");

  for(int i=0;i < s4.size(); i++)
    {

      if(s4[i].getId() == id)
	{
	  fnd=true;
	  num= i;
	}  
    }
  if(fnd)
    {
      exist = s4[num].addCourse(crn);
      if(exist)
	{
	  s4[num].chargeFee(50,10);
	  cout << crn << " was added" << endl;
	}
      else
	cout << "ERROR: The student is already enrolled in " << crn << endl;
    }
  else
    cout<< "ERROR: The student wasn't found" << endl;
}

//drop a course from a student
//reduct $50.10 from the student's balance
void dropCourseFromStudent(vector<Student>& s5)
{
  bool fnd = false;
  bool exist;
  int num;
 
 cout << "Enter the student id: ";
  int id = getNumberInRange(1, 99999, "Invalid id. Enter the student id: ");
  cout << "Enter the CRN: ";
  int crn = getNumberInRange(1, 99999, "Invalid CRN. Enter the CRN: ");

 
  for(int i=0;i < s5.size(); i++)
    {
      
      if(s5[i].getId() == id)
      {
	fnd=true;
	num= i;
      }
  }
if(fnd)
  {
    exist =s5[num].dropCourse(crn);
    if(exist)
      {
	s5[num].reduceFee(50,10);
	cout << crn << " was dropped" << endl;
      }
    else
      cout <<"ERROR: The student is not enrolled in " <<crn << endl;
  }
 else
   cout<< "ERROR: The student wasn't found" << endl;
}

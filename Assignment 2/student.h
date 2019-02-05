#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
using namespace std;
#include "price.h"

class Student
{
 private:
  static int id;
  static int numStu;
  int stId;
  string fName;
  string lName;
  char gender;
  Price balance;
  vector<int> coVec;

 public:
  Student();
  Student(string f, string l, char g);
  bool addCourse(int crn);
  bool dropCourse(int crn);
  string getFirstName();
  string getLastName();
  char getGender();
  int getId();
  static int getNumStu(); //This function returns the static data member 
  int getDollar();
  int getCent();
  vector<int> getCourses();
  void chargeFee(int d, int c);
  void reduceFee(int d, int c);
};

#endif

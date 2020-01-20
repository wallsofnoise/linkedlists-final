//header guard
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;

class Student { // student class
 public:
  // constructor
  Student(char*,char*,int,float);
  // function prototypes
  char* getFirstName(); // will return student's first name
  char* getLastName(); // will return student's last name
  int getID(); // will return student's ID number
  float getGPA(); // will return student's GPA
 private:
  // variables
  char* firstName;
  char* lastName;
  int ID;
  float GPA;
};

#endif
// header guard end

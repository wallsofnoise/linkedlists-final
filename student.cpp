#include "student.h" // allows access to student header file

using namespace std;

Student::Student(char* newFirstName, char* newLastName, int newID, float newGPA) { // constructor
  firstName = newFirstName;
  lastName = newLastName;
  ID = newID;
  GPA = newGPA;
}

Student::~Student() {
  delete firstName;
  delete lastName;
}

char* Student::getFirstName() { // return student's first name
  return firstName;
}

char* Student::getLastName() { // return student's last name
  return lastName;
}

int Student::getID() { // return student's ID number
  return ID;
}

float Student::getGPA() { // return student's ID number
  return GPA;
}

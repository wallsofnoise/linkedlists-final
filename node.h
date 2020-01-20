//node.h
#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "student.h"
using namespace std;

class Node {
 public:
  //constructor
  Node(Student* newstudent);
  //desctructor
  ~Node();
  //get this nodes next node
  Node* getNext();
  //get this nodes student
  Student* getStudent();
  //set this nodes next node
  void setNext(Node* newnext);
 private:
  //individual node variables
  Student* student;
  Node* next;
};

#endif

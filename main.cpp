#include <iostream>
#include <string.h> // for strcpy() and strcmp()
#include "student.h" // allow access to student class
#include "node.h" // allow access to node class

using namespace std;

// name: rose hall
// date: 01.20.20
// project: linked lists pt 2. using a provided node class, this program will allow students to be added to a list, sorted by ID number. the list will be printable, and students can be deleted by searching their ID. the program will also be able to average GPAs to two decimal places.

// function prototypes
void ADD(Node* &head); // add node to list
void PRINT(Node* next); // print list
void DELETE(Node* &head); // delete node from list
void AVERAGE(Node* head); // average GPAs of students in list
void QUIT(bool &programRunning); // quit program

int main() { // main method

  // bool used to keep while loop running while quit command hasn't been called
  bool programRunning = true;

  // char arrays to store function names for strcmp input tests
  char addF[] = "ADD";
  char printF[] = "PRINT";
  char deleteF[] = "DELETE";
  char avgF[] = "AVERAGE";
  char quitF[] = "QUIT";

  // char array used to store which function has been called
  char* calledFunction = new char[7];

  // base head node of linked list
  Node* head = NULL;
  
  // gives information about program and how to operate it
  cout << "this program is a linked list of students.\nyou can add a student by typing 'ADD' into the console.\nyou can print the current list by typing 'PRINT' into the console.\nyou can delete a student from the list by typing 'DELETE' into the console.\nyou can average the GPAs of students currently in the list by typing 'AVERAGE' into the console.\nyou can quit the program by typing 'QUIT' into the console." << endl;

  while (programRunning == true) { // main program loop

    // prompts user for command input
    cout << "please input a command." << endl;

    //take input to determine which function will be called
    cin >> calledFunction;
    cin.get();

    if (strcmp(calledFunction,addF) == 0) { // if called, perform ADD function
      ADD(head);
    }
    else if (strcmp(calledFunction,printF) == 0) { // if called, perform PRINT function
      PRINT(head);
    }
    else if (strcmp(calledFunction,deleteF) == 0) { // if called, perform DELETE function
      DELETE(head);
    }
    else if (strcmp(calledFunction,avgF) == 0) { // if called, perform AVERAGE function
      AVERAGE(head);
    }
    else if (strcmp(calledFunction,quitF) == 0) { // if called, perform QUIT function
      QUIT(programRunning);
    }
    else { // if command is invalid, inform user
      cout << "this command was not recognized! please try again." << endl;
    }
  }
}

void ADD(Node* &head) { // add function
  // test:
  cout << "this function can be called." << endl;
}

void PRINT(Node* next) { // print function
  // test:
  cout << "this function can be called." << endl;
}

void DELETE(Node* &head) { // delete function
  // test:
  cout << "this function can be called." << endl;
}

void AVERAGE(Node* head) { // average function
  // test:
  cout << "this function can be called." << endl;
}

void QUIT(bool &programRunning) { // quit function
  // notify user that program is quitting
  cout << "quitting program..." << endl;
  // break while loop
  programRunning = false;
}

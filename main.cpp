#include <iostream> // for cout/cin
#include <iomanip> // for setprecision
#include <string.h> // for strcpy() and strcmp()
#include "student.h" // allow access to student class
#include "node.h" // allow access to node class

using namespace std;

// name: rose hall
// date: 01.20.20
// project: linked lists pt 2. using a provided node class, this program will allow students to be added to a list, sorted by ID number. the list will be printable, and students can be deleted by searching their ID. the program will also be able to average GPAs to two decimal places.

// function prototypes
void ADD(Node* &head); // add node to list
void PRINT(Node* next, Node* head); // print list
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
      PRINT(head, head);
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
  // cout << "this function can be called." << endl;

  // creates variables for student inputs
  char* inputFirstName = new char[20];
  char* inputLastName = new char[20];
  int inputID;
  float inputGPA;
  
  // prompt for first name input
  cout << "please input student's first name:" << endl;
  cin.getline(inputFirstName,20);
  // prompt for last name input
  cout << "please input student's last name:" << endl;
  cin.getline(inputLastName,20);
  // prompt for ID input
  cout << "please input student's ID:" << endl;
  cin >> inputID;
  cin.get();
  // prompt for GPA input
  cout << "please input student's GPA:" << endl;
  cin >> inputGPA;
  cin.get();

  // create new student
  Student* s = new Student(inputFirstName,inputLastName,inputID,inputGPA);

  // create new node using the student
  Node* n = new Node(s);
  
  // create var to track current and previous nodes, starting at the head
  Node* current = head;
  Node* previous = head;
  
  if (current == NULL) { // if the head node does not exist
    // make the node containing this student the head
    head = n;
  }
  else { // if the head node is already full
    while (current != NULL) { // while the current node still exists
      if (n->getStudent()->getID() < head->getStudent()->getID()) { // if current student's ID is less than current head
	// make n's next node the current head node
	n->setNext(head);
	// make n the new head node
	head = n;
	// break loop, no need to continue
	break;
	// this should successfully add our node to the beginning of the list
      }
      else { // if we make it past the head node
	// move current to be next node in list
	current = current->getNext();

	if (current == NULL) { // if current is now a non-existent node, we've reached the end of the list
	  // set the previous node's next node to be our new inputted student
	  previous->setNext(n);
	  // break loop, no need to continue
	  break;
	  // this should successfully tack our new node onto the end of the list
	}
	else if (n->getStudent()->getID() < current->getStudent()->getID()) { // if the current node still exists, and our new node's ID is less than it's ID
	  // set the previous node's next node to be our new inputted student
	  previous->setNext(n);
	  // set our new inputted student's next node to be the current node
	  n->setNext(current);
	  // break loop, no need to continue
	  break;
	  // this should successfully insert our new node in betwen the previous and current nodes on the list
	}
	// if we make it all the way through, set the previous node to be the next node before running again
	previous = previous->getNext();
      }
    }
  }
  
}

void PRINT(Node* next, Node* head) { // print function
  // test:
  // cout << "this function can be called." << endl;

  if (next == head) { // if we are at the beginning of the list
    // print a header for the list
    cout << "student data stored:" << endl;
  }
  if (next != NULL) { // if we haven't reached the end of the list
    // print the current student's information
    cout << fixed << setprecision(2) << next->getStudent()->getFirstName() << " " << next->getStudent()->getLastName() << ", " << next->getStudent()->getID() << ", " << next->getStudent()->getGPA() << endl;
    // call print function on the next entry in the list
    PRINT(next->getNext(), head);
  }
  
}

void DELETE(Node* &head) { // delete function
  // test:
  // cout << "this function can be called." << endl;

  // create variable for ID input
  int deleteID;

  // prompt for ID input
  cout << "enter the ID of the student you'd like to delete:" << endl;
  cin >> deleteID;
  cin.get();

  // create var to track current and previous nodes, starting at the head
  Node* previous = head;
  Node* current = head;

  while (current != NULL) { // while the current node still exists
    if (deleteID == head->getStudent()->getID()) { // if the ID for deletion is equal to the head's ID
      // set the next node to be the new head
      head = current->getNext();
      // delete current (the old head)
      delete current;
      // break loop, no need to continue
      break;
    }
    else { // if we make it past the head node
      // set current to be next node in the list
      current = current->getNext();
      
      if (current == NULL) { // if the current node is now non-existent, we've reached the end of the list
	// inform the user that no IDs matched their search
	cout << "no students had that ID." << endl;
	// break loop, no need to continue
	break;
      }
      else if (deleteID == current->getStudent()->getID()) { // if the ID for deletion is equal to the current student node's ID
	// set the previous node's next node to be the node after the current node
	previous->setNext(current->getNext());
	// delete the current node
	delete current;
	// break loop, no need to continue
	break;
      }
    }
    // if we make it all the way through, set previous node to be next node before running again
    previous = previous->getNext();
  }
  
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

#pragma once
#include <iostream>
#include "Stack.h"

class NodeS { // Node object to hold the stacks
public:
	Stack info; // Stack data
	NodeS* next; // Pointer to next object

	NodeS(); // Constructors
	NodeS(const Stack& d);
};
class stackLinkedList { // Linked list of stacks
public:
	NodeS* head; // Pointer to head of the linked list
	NodeS* tail; // Pointer to the end of the linked list

	stackLinkedList(); // Constructor

	void addToFront(const Stack& d); // Add to the front of the linked list
	void addToBack(const Stack& d); // Add to the back of the linked list
	void printList(); // Print the linked list
	void printViaPop();
};
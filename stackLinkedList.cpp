#include "stackLinkedList.h"

NodeS::NodeS() {
	next = nullptr; // Make next pointer point to nullptr
}
NodeS::NodeS(const Stack& d) {
	info = d; // Add data to info variable
}

stackLinkedList::stackLinkedList() {}

void stackLinkedList::addToFront(const Stack& d) {
	NodeS* temp = new NodeS(d); // Create node object with the stack being passed
	if (head == nullptr) { // List is empty then make head and tail point to temp
		head = temp;
		tail = temp;
	}
	else {
		temp->next = head; // Make next pointer in temp point to top node in the list
		head = temp; // Make head point to temp
	}
}

void stackLinkedList::addToBack(const Stack& d){
	if (head == nullptr) { // If list is empty just use addToFront function
		addToFront(d);
	}
	else {
		NodeS* temp = new NodeS(d); // Create node
		tail->next = temp; // Make tail object's next pointer point to temp
		tail = temp; // Make tail point to temp
	}
}

void stackLinkedList::printList() {
	NodeS* curr = head; // Pointer to go through the list
	while (curr != nullptr) { // While there are objects in the list keep running
		curr->info.printStack(); // Print the stack in the node that current points to
		curr = curr->next; // Move pointer to next node
	}
}

void stackLinkedList::printViaPop() {
	NodeS* current = head;
	while (current != nullptr) {
		current->info.popPrint();
		current = current->next;
	}
	std::cout << "Stack is now empty" << std::endl;
}
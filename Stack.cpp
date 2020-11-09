#include "Stack.h"

Node::Node(){}
Node::Node(const char& d) {
	data = d; // Store the info to the data variable
}

Stack::Stack(){
	topOfStack = bottomOfStack = nullptr; // Point the pointers to nullptr
}
Stack::Stack(const std::string& d) {
	addWord(d);
}


void Stack::push(const char& d){
	Node* temp = new Node(d); // Put char into a node
	if (topOfStack == nullptr) { // If list is empty then make temp head and tail
		topOfStack =  temp;
		bottomOfStack = temp;
	}
	else { // Point temp to top node, then top pointer points to temp
		temp->next = topOfStack;
		topOfStack = temp;
	}
}
void Stack::pop(){ // Remove top object in the stack
	char data; // Variable to hold data in the top node
	Node* temp = topOfStack; // Temp object to hold onto top node so it is not lost
	data = temp->data; // Copy data from the top node
	topOfStack = topOfStack->next; // Point top to the next node
	delete temp; // Delete what temp points to
	std::cout << data; // Print out data from deleted node
}

void Stack::addWord(const std::string& w) {
	if (w[w.size()-1] == '.') { // If word ends in a period, add period first then move to a new line
		push('\n');
		push('.');
	}
	else { // If no period is found then add a space
		push(' ');
	}
	for (int i = 0; i < w.size(); i++) { // Loop to go through each letter in the string
		if (w[i] == '.') { // If we reached the end of a sentence then skip adding the period to the stack 
			continue;
		}
		push(w[i]); // Push the char to the stack
	}
}

void Stack::printStack(){
	Node* current = topOfStack; // Point to the top of the stack
	while (current != nullptr) { // While current points to a node keep running
		std::cout << current->data; // Print data to console
		current = current->next; // Make current point to next node on the stack
	}
}

void Stack::popPrint() {
	while (topOfStack != nullptr) { // While there is an object in the stack keep traversing
		pop(); // Pop from the stack and print to console
	}
}
#include <fstream>
#include "stackLinkedList.h"

int main() {
	stackLinkedList* list = new stackLinkedList(); // Creates linked list of stacks to be filled

	std::ifstream file; // Object to handle file that will be read
	std::string read; // String that will hold the words from the file

	file.open("Chuck.txt"); // Open file to read
	
	while (file >> read) { // While there is something to read, let read hold the word
		Stack* temp; // Stack that will be sent to the linked list
		temp = new Stack(read);
		list->addToBack(*(temp)); // Add to linked list
	}
	file.close(); // Close the file

	list->printList(); // Print the list using a node going through the linked list of stacks
	std::cout << std::endl;
	list->printViaPop(); // Print the list using pop function from all the stacks

	return 0;
}
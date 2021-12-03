/*
	Joshua Thornton
	11/28/2021
	Project: Linked List

	This project is for the assignment "Project: Linked List." The project implements a generic, doubly linked
	list, and the ability for a user to test that list in the console using integers.

	12/01/2021: Professor reports incorrect data after inserting multiple values and then deleting 1 or more.
				Unable to reproduce this.
*/

#pragma region Preprocessor Directives
// Allows streaming to and from the console.
#include <iostream>
// Include these header files.
#include "DoubleLinkedList.h"
#include "AppDriver.h"
#pragma endregion Preprocessor Directives

// The main function of the program, which will automatically run.
int main()
{
	// Create the AppDriver to run the program.
	AppDriver appDriver = AppDriver();
	// Run the program.
	appDriver.Intro();
	appDriver.Testing();

	// Pause the system, then return 0 to show that the program finished with no problems.
	system("pause");
	return 0;
}
/*
	This header file contains the AppDriver class, which is meant to be implement an
	interface between the app and the user so that the user can test the
	doubly linked list.
*/

#pragma region Preprocessor Directives
// This file will only be included once.
#pragma once
// Allows streaming to and from the console.
#include <iostream>
// Allows for the use of string variables.
#include <string>
// Include the DoubleLinkedList class.
#include "DoubleLinkedList.h"
#pragma endregion Preprocessor Directives

// Define the AppDriver class.
class AppDriver
{
	// These members will be private.
private:
	std::string mainMenuQuestion = "How would you like to manipulate the list next?";
	std::string findMenuQuestion = "Would you like to search by index, or value?";
	std::string findKthMenuQuestion = "Which index do you wish to retrieve? (0-4 only)";
	std::string findFirstOccuranceQuestion = "Which element do you want to find the index of?";
	std::string deleteMenuQuestion = "At what index is the list element you wish to delete?";

	// These members will be public.
public:
	// The constructor for the AppDriver.
	AppDriver();

	// Runs the Intro scenario for the user.
	void Intro();

	// Runs the testing loop for the user (main app content).
	void Testing();

	/*
		Accept user input. Asks the question, and returns int of 1 - 5,
		correlating with the options chosen by user.
	*/
	int AcceptInput(
		std::string question,
		std::string opt1,
		std::string opt2,
		std::string opt3,
		std::string opt4,
		std::string opt5
	);
};


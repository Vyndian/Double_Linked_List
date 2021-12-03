#include "AppDriver.h"
#include "DoubleLinkedList.h"
#include <iostream>
#include <string>

// AppDriver constructor.
AppDriver::AppDriver()
{
	// Intentioanlly left blank.
}

// Runs the Intro scenario for the user.
void AppDriver::Intro()
{
	// Print this out to the user.
	std::cout << "           Joshua Thornton\n";
	std::cout << "         Double Linked List Showcase\n\n";
	std::cout << "   Hello! Let's test the double linked list I created. It holds integers.\n";
	std::cout << "   A list has been created for you with a single entry of the number 1.\n";
	std::cout << "   Press any key to print the list.\n\n";
	
	// Pause, add lines.
	system("pause");
	std::cout << "\n\n";
}

// Runs the Testing scenario for the user.
void AppDriver::Testing()
{
	// Variables for testing.
	DoubleLinkedList<int> testList = DoubleLinkedList<int>();
	bool mainMenu = false;
	bool findMenu = false;
	bool findKthMenu = false;
	bool findFirstOccuranceMenu = false;
	bool insertMenu = false;
	bool deleteMenu = false;

	// Print the list.
	testList.PrintList();

	// Print this to the user.
	std::cout << "\n   Now you may test the list.\n";

	// Until the user wants to break out of the main menu, loop the menu.
	// (Includes all submenus within it)
	mainMenu = true;
	while (mainMenu)
	{
		// MAIN MENU
		std::cout << "\n         MAIN MENU\n\n";
		// Ask the question.
		int mainResponse = AcceptInput(mainMenuQuestion, "find", "insert", "delete", "exit", "");

		// Check for the answer and open the appropriate next menu.
		if (mainResponse == 1)
		{
			// If list is not empty,
			if (testList.GetSize() > 0)
			{
				// Then allow access to find menu.
				findMenu = true;
			}
			// Else, the list is empty.
			else
			{
				std::cout << "\n   The list is empty. There are no values to find.\n";
			}
			// Until the user wants to break out of the Find menu, run that menu.
			// (Also contains a submenu)
			while (findMenu)
			{
				// FIND MENU
				std::cout << "\n         FIND MENU\n\n";
				// Ask the question.
				int findResponse = AcceptInput(findMenuQuestion, "index", "value", "", "", "");

				// Check for the answer and open the appropriate next menu.
				if (findResponse == 1)
				{
					// User has chosen the Index (FindKth) menu, so run that.
					findKthMenu = true;
					while (findKthMenu)
					{
						// FIND BY INDEX MENU
						std::cout << "\n\n         FIND BY INDEX MENU\n\n";
						std::cout << "   You have chosen to find a value using its index in the list.";
						std::cout << "\n   Please remember that this program can only accept an index ";
						std::cout << "from 0 to 4.\n   Choosing an index outside of the range of the list";
						std::cout << " will result in showing the last list item instead.\n";

						// Pause, add lines.
						system("pause");
						std::cout << "\n\n";

						std::cout << "   Printing list for reference...\n";
						testList.PrintList();

						// Pause, add lines.
						system("pause");
						std::cout << "\n\n";

						// Will hold the user's answer.
						int chosenIndex = -1;

						// Ask the question.
						int findByIndexResponse = AcceptInput(findKthMenuQuestion, "0", "1", "2", "3", "4");

						// Set answer based on response.
						switch (findByIndexResponse)
						{
						case 1:
							chosenIndex = 0;
							break;
						case 2:
							chosenIndex = 1;
							break;
						case 3:
							chosenIndex = 2;
							break;
						case 4:
							chosenIndex = 3;
							break;
						case 5:
							chosenIndex = 4;
							break;
						}

						std::cout << "   Looking up the list item at index " << chosenIndex;
						// FindKth.
						Node<int>* foundNode = testList.FindKth(chosenIndex);
						// If a node was found,
						if (foundNode != nullptr)
						{
							int foundVal = foundNode->value;
							std::cout << "\n   Value found: " << foundVal << "\n\n";
						}
						// Else, a node could not be found.
						else
						{
							std::cout << "\n   Unable to find a value.\n\n";
						}

						// Pause, add lines.
						system("pause");
						std::cout << "\n\n";

						findKthMenu = false;
					}
				}
				else if (findResponse == 2)
				{
					// User has chosen the First Occurance menu, so open that.
					findFirstOccuranceMenu = true;
					while (findFirstOccuranceMenu)
					{
						bool validResponse = false;
						int intGiven;

						// FIND BY VALUE MENU
						std::cout << "\n\n         FIND BY VALUE MENU\n\n";

						// Loop until valid response.
						while (!validResponse)
						{
							std::cout << "\n   Enter a number with NO OTHER CHARACTERS and press enter.\n   ";
							std::cout << "Then the list will be searched, and you will be told if that value was found.\n";
							// Take the user's input.
							std::cin >> intGiven;
							// If the input failed (was not ONLY valid for an int),
							if (std::cin.fail())
							{
								// then clear the input stream.
								std::cin.clear();
								std::cin.ignore(1000000);
								std::cout << "\n   Sorry, but that input was not valid. Please enter ONLY numbers.\n";

								// Pause, add lines.
								system("pause");
								std::cout << "\n\n";
							}
							// Else, input worked.
							else
							{
								validResponse = true;
								// If the method found that in the list,
								if (testList.Find(intGiven) != nullptr)
								{
									// then tell the user.
									std::cout << "\n   That value was found!\n\n";

									// Pause, add lines.
									system("pause");
									std::cout << "\n\n";
								}
								// Else, that value was not found.
								else
								{
									std::cout << "\n   That input was valid,";
									std::cout << " but the list does not contain that value.\n\n";

									// Pause, add lines.
									system("pause");
									std::cout << "\n\n";
								}
							}
						}

						findFirstOccuranceMenu = false;
					}
				}

				findMenu = false;
			}
		}
		else if (mainResponse == 2)
		{ 
			// User has chosen to insert a value. Run that menu.
			insertMenu = true;
			while (insertMenu)
			{
				// INSERT MENU
				std::cout << "\n\n         INSERT MENU\n\n";
				std::cout << "   You have chosen to insert a new value into the list.\n";
				std::cout << "   Printing the list for reference...\n";
				testList.PrintList();

				// Pause, add lines.
				system("pause");
				std::cout << "\n\n";

				bool firstValidResponse = false;
				int valGiven;
				// Loop until valid response.
				while (!firstValidResponse)
				{
					std::cout << "\n   Enter a number with NO OTHER CHARACTERS and press enter.\n   ";
					std::cout << "This will be the value that you will insert into the list.\n";
					// Take the user's input.
					std::cin >> valGiven;
					// If the input failed (was not ONLY valid for an int),
					if (std::cin.fail())
					{
						// then clear the input stream.
						std::cin.clear();
						std::cin.ignore(1000000);
						std::cout << "\n   Sorry, but that input was not valid. Please enter ONLY numbers.\n";

						// Pause, add lines.
						system("pause");
						std::cout << "\n\n";
					}
					// Else, input worked.
					else
					{
						firstValidResponse = true;
						std::cout << "\n   You entered " << valGiven;
						std::cout << ". Next, we need the index you wish to insert this value at.\n\n";

						// Pause, add lines.
						system("pause");
						std::cout << "\n\n";
					}
				}

				bool secondValidResponse = false;
				int indexGiven;
				// Loop until valid response.
				while (!secondValidResponse)
				{
					std::cout << "\n   Enter a number with NO OTHER CHARACTERS and press enter.\n   ";
					std::cout << "Then the previous value will be inserted at this index.\n";
					// Take the user's input.
					std::cin >> indexGiven;
					// If the input failed (was not ONLY valid for an int),
					if (std::cin.fail())
					{
						// then clear the input stream.
						std::cin.clear();
						std::cin.ignore(1000000);
						std::cout << "\n   Sorry, but that input was not valid. Please enter ONLY numbers.\n";

						// Pause, add lines.
						system("pause");
						std::cout << "\n\n";
					}
					// Else, input worked.
					else
					{
						secondValidResponse = true;

						// If indexGiven is within the proper range, being 0 through listSize,
						if (indexGiven <= testList.GetSize())
						{
							std::cout << "\n   Input is valid. Inserting value of " << valGiven;
							std::cout << " at index " << indexGiven;
						}
						// Else, the indexGiven IS too high. It will default to the listSize.
						else
						{
							std::cout << "\n   The input was too high. Defaulting to end of list.";
							std::cout << "\n   Inserting value of " << valGiven;
							std::cout << " at index " << testList.GetSize();
						}

						std::cout << "\n\n";

						// Pause, add lines.
						system("pause");
						std::cout << "\n\n";

						// Insert, then print.
						testList.Insert(valGiven, indexGiven);
						testList.PrintList();

						// Pause, add lines.
						system("pause");
						std::cout << "\n\n";
					}
				}

				insertMenu = false;
			}
		}
		else if (mainResponse == 3)
		{
			// If the list is not empty,
			if (testList.GetSize() > 0)
			{
				// then allow the delete menu to open.
				deleteMenu = true;
			}
			// Else, the list is empty.
			else
			{
				std::cout << "\n   The list is empty. There are no values to delete.\n";
			}

			// User has chosen to delete a value. Open that menu.
			while (deleteMenu)
			{
				// DELETE MENU
				std::cout << "\n         DELETE MENU\n\n";
				std::cout << "   You have chosen to delete a list element at a specified index.";
				std::cout << "\n   Please remember that this program can only accept an index ";
				std::cout << "from 0 to 4.\n   Choosing an index outside of the range of the list";
				std::cout << " will result in deleting the last list item instead.\n\n";

				// Pause, add lines.
				system("pause");
				std::cout << "\n\n";

				std::cout << "   Printing list for reference...\n";
				testList.PrintList();

				// Pause, add lines.
				system("pause");
				std::cout << "\n\n";

				// Will hold the user's answer.
				int chosenIndex = -1;

				// Ask the question.
				int deleteIndexResponse = AcceptInput(deleteMenuQuestion, "0", "1", "2", "3", "4");

				// Set answer based on response.
				switch (deleteIndexResponse)
				{
				case 1:
					chosenIndex = 0;
					break;
				case 2:
					chosenIndex = 1;
					break;
				case 3:
					chosenIndex = 2;
					break;
				case 4:
					chosenIndex = 3;
					break;
				case 5:
					chosenIndex = 4;
					break;
				}

				std::cout << "\n   That input was valid. Deleting node at index " << chosenIndex;
				std::cout << "\n\n";

				// Pause, add lines.
				system("pause");
				std::cout << "\n\n";

				// Delete the node found at the chosen index.
				testList.Delete(testList.FindKth(chosenIndex));

				// Print list.
				testList.PrintList();

				// Pause, add lines.
				system("pause");
				std::cout << "\n\n";

				deleteMenu = false;
			}
		}
		else if (mainResponse == 4)
		{
			// User has chosen to exit the program.
			mainMenu = false;
			std::cout << "\n\n   You have chosen to exit the program.\n\n";

			// Pause, add lines.
			system("pause");
			std::cout << "\n\n";

			// Close the program.
			exit(0);
		}
	}
}

/*
	Accept user input. Asks the question, and returns int of 1 - 5,
	correlating with the options chosen by user.
	Formats the question/options automatically.
*/ 
int AppDriver::AcceptInput(
	std::string question,
	std::string opt1,
	std::string opt2,
	std::string opt3,
	std::string opt4,
	std::string opt5
)
{
	// Create a string to hold the user's response.
	std::string response = "";
	// Holds output to return based on user input.
	int intOutput = -1;

	// Repeat until user provides a valid answer.
	while (intOutput < 0)
	{
		// Ask the question and provide instruction to user.
		std::cout << "\n   " << question;
		std::cout << "\n   (Please type your response exactly as shown.)";

		// Print each option if it is valid.
		if (opt1 != "")
		{
			std::cout << "\n      " << opt1;
		}
		if (opt2 != "")
		{
			std::cout << "\n      " << opt2;
		}
		if (opt3 != "")
		{
			std::cout << "\n      " << opt3;
		}
		if (opt4 != "")
		{
			std::cout << "\n      " << opt4;
		}
		if (opt5 != "")
		{
			std::cout << "\n      " << opt5;
		}

		// Wait for user input.
		std::cout << "\n\n";
		std::cin >> response;
		std::cout << "\n\n";

		// Check the response against each option.
		if (response == opt1 && opt1 != "")
		{
			// Answer matched.
			intOutput = 1;
			return intOutput;
		}
		else if (response == opt2 && opt2 != "")
		{
			// Answer matched.
			intOutput = 2;
			return intOutput;
		}
		else if (response == opt3 && opt3 != "")
		{
			// Answer matched.
			intOutput = 3;
			return intOutput;
		}
		else if (response == opt4 && opt4 != "")
		{
			// Answer matched.
			intOutput = 4;
			return intOutput;
		}
		else if (response == opt5 && opt5 != "")
		{
			// Answer matched.
			intOutput = 5;
			return intOutput;
		}
		// Else, did not match any of the options.
		else
		{
			std::cout << "   Sorry, that response did not match any of the options.\n";
			std::cout << "   Please enter the response exactly as it is shown.\n";

			// Pause, add lines.
			system("pause");
			std::cout << "\n\n";
		}
	}

	// Valid answer received, but somehow did not yet return. Return that answer.
	return intOutput;
}
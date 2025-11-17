#include <iostream>
#include <fstream>
#include <string>

#include "fileManipulation.h"
#include "onlyInt.h"   // Uses onlyInt() function in this file
#include "mainMenu.h"  // this is for clearing the screen

void clearScreen();

// ============ File Manipulation Menu ============
void fileManipulationMenu()
{
	std::string fileName{}; // Variable to store file name for file manipulation tasks

	std::cout << "[1] Create a file\n";
	std::cout << "[2] Read a file\n";
	std::cout << "[3] Update a file\n";
	std::cout << "[4] Delete a file\n";


	int choice = onlyInt("Enter your choice: "); // only add numerical input allowed
	// check onlyInt.h
	switch (choice)
	{
	case 1:
		clearScreen();
		std::cout << "You selected Create a file.\n";
		createFile(fileName);
		break;
	case 2:
		clearScreen();
		std::cout << "You selected Read a file.\n";
		readFile(fileName);
		break;
	case 3:
		clearScreen();
		std::cout << "You selected Update a file.\n";
		// Placeholder for update file functionality
		break;
	case 4:
		clearScreen();
		std::cout << "You selected Delete a file.\n";
		// Placeholder for delete file functionality
		break;
	default:
		std::cout << "Invalid choice. Please try again.\n";
		break;
	}
}

void createFile(std::string& fileName)
{

	std::cout << "Enter the name of the file to create (include .txt, .md, etc): ";
	std::getline(std::cin, fileName);

	if (fileName.empty())
	{
		std::cout << "Sorry, you did not input anything. \n";
		return;
	}
	// Creates a file of users choice
	std::ofstream MyFile(fileName); //  
	if (!MyFile)      // checks if file was created successfully
	{
		std::cerr << "\nError creating file '" << fileName << "'!\n";
		return;
	}

	std::cout << "Enter the text to write to the file.\n";
	std::cout << "(Type 'done' on a new line to finish writing)\n";

	std::string fileLine{}; // Variable to store line of user input

	while (true)
	{
		std::getline(std::cin, fileLine);
		if (fileLine == "DONE" || fileLine == "done")
		{
			break;
		}
		MyFile << fileLine << "\n"; // writes user input to file
	}

	// Closes the file
	MyFile.close();
	std::cout << "File " << fileName << " created successfully!\n";
}

void readFile(std::string& fileName)
{
	std::cout << "Enter the name of the file to read (include .txt, .md, etc): ";
	std::getline(std::cin >> std::ws, fileName); // use std::ws to ignore leading whitespace if user inputs any

	// Reads from the text file
	std::ifstream MyReadFile(fileName);


	if (!MyReadFile)
	{
		std::cout << "File '" << fileName << "' does not exist.\n";
		return;
	}

	std::cout << "==== Contents of '" << fileName << "' ====\n";

	// Uses a while loop together with getline() to read the file line by line
	std::string fileLine{};
	while (getline(MyReadFile, fileLine))
	{
		std::cout << fileLine << "\n";
	}

	// Closes the file
	MyReadFile.close();
}

void updateFile(std::string& fileName)
{
	// Selects file to update
	std::cout << "Enter the name of the file you would like to update: ";
	std::getline(std::cin >> std::ws, fileName); // use std::ws to ignore leading whitespace if user inputs any

	// Open contents?


	// Update contents?


	// Save contents?
};




#pragma once
#include "fileManipulation.h"

/* Program to ask user for type of task they want to complete
[1] File maniupulation
[2] Get system information
[3] Set a reminder
[4] Exit
*/
void clearScreen() // clears screen after each selection
{
    std::cout << "\033[2J\033[1;1H"; // works on most modern terminals
}

void mainMenu()
{
	bool running = true;
	std::string fileName; // Variable to store file name for file manipulation tasks

    while (running)
    {
        std::cout << "Select a task to complete:\n";
        std::cout << "[1] File manipulation\n";
        std::cout << "[2] Get system information\n";
        std::cout << "[3] Set a reminder\n";
        std::cout << "[4] Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            clearScreen();
            std::cout << "You selected File manipulation.\n";
			fileManipulationMenu();
            break;
        case 2:
            clearScreen();
            std::cout << "You selected Get system information.\n";
            // Placeholder for system information functionality
            break;
        case 3:
            clearScreen();
            std::cout << "You selected Set a reminder.\n";
            // Placeholder for reminder functionality
            break;
        case 4:
            running = false;
            std::cout << "Exiting the program. Goodbye!\n";
            return;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
        return;
    }
}

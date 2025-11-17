#include "onlyInt.h"
#include <iostream>
#include <limits>


int onlyInt(const std::string& prompt)
{
    int value{};

    std::cout << prompt;
    while (!(std::cin >> value))
    {
        std::cout << "Invalid input, please enter a number: ";

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // flushes the bad input
    }

    // clear the left over new lines
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return value;
}
#pragma once

#include <string>

class EncDec
{
public:
	void encrypt();
	void decrypt();
	

private:
	int key{};		   // to store the enc/dec key
	std::string file{}; // to store to file which the user types
	char c{};
};
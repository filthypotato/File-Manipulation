#include "encdec.h"

#include <windows.h>
#include <fstream>
#include <iostream>

void EncDec::encrypt()
{
    std::string fileName{};
    std::cout << "Enter the name of the file to encrypt (include .txt, .md, etc): ";
    std::getline(std::cin >> std::ws, fileName);

    std::cout << "Enter a numeric key to encrypt with: ";
    std::cin >> key;

    // Check if file exists and open for reading
    std::ifstream fin(fileName, std::ios::binary);
    if (!fin)
    {
        std::cout << "File '" << fileName << "' does not exist! :(\n";
        return;
    }

    std::string outName = fileName + ".enc";
    std::ofstream fout(outName, std::ios::binary);
    if (!fout)
    {
        std::cout << "Could not open '" << outName << "' for writing.\n";
        return;
    }

    char ch{};
    while (fin.get(ch))
    {
        int temp = static_cast<unsigned char>(ch) + key;
        fout.put(static_cast<char>(temp));
    }

    std::cout << "File '" << fileName << "' encrypted as '" << outName << "'.\n";
}

void EncDec::decrypt()
{
    std::string fileName{};
    std::cout << "Enter the name of the file to decrypt (include .txt, .md, etc): ";
    std::getline(std::cin >> std::ws, fileName);

    std::cout << "Enter the key used for encryption: ";
    std::cin >> key;

    std::ifstream fin(fileName, std::ios::binary);
    if (!fin)
    {
        std::cout << "File '" << fileName << "' does not exist! :(\n";
        return;
    }

    std::string outName = fileName + ".dec";
    std::ofstream fout(outName, std::ios::binary);
    if (!fout)
    {
        std::cout << "Could not open '" << outName << "' for writing.\n";
        return;
    }

    char ch{};
    while (fin.get(ch))
    {
        int temp = static_cast<unsigned char>(ch) - key;
        fout.put(static_cast<char>(temp));
    }

    std::cout << "File '" << fileName << "' decrypted as '" << outName << "'.\n";
}



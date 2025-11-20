#include "encdec.h"

#include <windows.h>
#include <fstream>
#include <iostream>

void EncDec::encrypt()
{
    std::string fileName{};
    std::cout << "Enter the name of the file to encrypt (include .txt, .md, etc): ";
    std::getline(std::cin >> std::ws, fileName);

    std::cout << "Enter a phrase key to encrypt with: ";
    std::getline(std::cin >> std::ws, phrase);

    if (phrase.empty())
    {
        std::cout << "Phrase cannot be empty!\n";
        return;
    }


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
    std::size_t index = 0;
    const std::size_t phraseLen = phrase.size();

    while (fin.get(ch))
    {
        unsigned char plain = static_cast<unsigned char>(ch);
        unsigned char keyByte = static_cast<unsigned char>(phrase[index % phraseLen]);
        unsigned char cipher = plain ^ keyByte;

        fout.put(static_cast<char>(cipher));
        ++index;
    }

    std::cout << "File '" << fileName << "' encrypted as '" << outName << "'.\n";
}

void EncDec::decrypt()
{
    std::string fileName{};
    std::cout << "Enter the name of the file to decrypt (include .txt, .md, etc): ";
    std::getline(std::cin >> std::ws, fileName);

    std::cout << "Enter the phrase used for encryption: ";
    std::getline(std::cin >> std::ws, phrase);

    if (phrase.empty())
    {
        std::cout << "Phrase cannot be empty!\n";
        return;
    }

    std::ifstream fin(fileName, std::ios::binary);
    if (!fin)
    {
        std::cout << "File '" << fileName << "' does not exist! :(\n";
        return;
    }

    std::string outName = fileName + ".dec";     // adds .dec to end of file
    std::ofstream fout(outName, std::ios::binary);  // opens file to take file and encrypt with binary
    if (!fout)
    {
        std::cout << "Could not open '" << outName << "' for writing.\n";
        return;
    }

    char ch{};
    std::size_t index = 0;
    const std::size_t phraseLen = phrase.size();

    while (fin.get(ch))
    {
        unsigned char cipher = static_cast<unsigned char>(ch);
        unsigned char keyByte = static_cast<unsigned char>(phrase[index % phraseLen]);   
        unsigned char plain = cipher ^ keyByte;   // undoes cipher

        fout.put(static_cast<char>(plain));
        ++index;
    }

    std::cout << "File '" << fileName << "' decrypted as '" << outName << "'.\n";
}

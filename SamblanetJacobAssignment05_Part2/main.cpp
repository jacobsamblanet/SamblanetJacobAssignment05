/* ---------------------------------------------------------------------------
** I attest that this following code represents my own work and is subject to
** the plagiarism policy found in the course syllabus.
**
** Class: 	CSC 242
** Assignment: 	Assignment 5 Part 2
** File: 	SamblanetJacobAssignment05_Part2.cpp
** Description: Write a program that checks the spelling of all words in a file.
**It should read each word of a file and check whether it is contained in a word list
**
** Author: 	Jacob Samblanet
** Date: 	11/22/2025
** -------------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>


using namespace std;

// Encrypts text by shifting alphabetic characters
string encrypt(string text, int shift) {
    string encoded_text;

    for (int i = 0; i < text.size(); i++) {
        if (isalpha(text[i])) {
            char encoded = text[i] + shift;
            encoded_text += encoded;
        }
        else {
            encoded_text += text[i]; // keep non-letters unchanged
        }
    }
    return encoded_text;
}

// Decrypts by reversing the shift
string decrypt(string text, int shift) {
    return encrypt(text, -shift);
}


int main() {
    string mode;
    int shift;

    // Ask user for mode
    cout << " Do you want to encrypt or decrypt? ";
    cin >> mode;

    //Ask user for shift
    cout << "Enter shift value: ";
    cin >> shift;

    //Open input file
    ifstream in_file("input.txt");
    if (!in_file) {
        cout << "Error opening input.txt\n";
        return 1;
    }

    string text;
    char ch;

    // Read entire file character-by-character
    while (in_file.get(ch)) {
        text += ch;   // add each character
    }

    string result;

    // Choose encrypt or decrypt
    if (mode == "encrypt") {
        result = encrypt(text, shift);
    } else if (mode == "decrypt") {
        result = decrypt(text, shift);
    } else {
        cout << "Invalid mode.\n";
        return 1;
    }

    // Write result to output file
    ofstream out_file("output.txt");
    if (!out_file) {
        cout << "Error opening output.txt\n";
        return 1;
    }
out_file << result <<endl;
    cout <<"Check output.txt\n";

    return 0;
}

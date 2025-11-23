/* ---------------------------------------------------------------------------
** I attest that this following code represents my own work and is subject to
** the plagiarism policy found in the course syllabus.
**
** Class: 	CSC 242
** Assignment: 	Assignment 5 Part 1
** File: 	SamblanetJacobAssignment05_Part1.cpp
** Description: Write a program that checks the spelling of all words in a file.
**It should read each word of a file and check whether it is contained in a word list
**
** Author: 	Jacob Samblanet
** Date: 	11/22/2025
** -------------------------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    // Open the dictionary file
    ifstream dictionaryFile("/Users/jacobsamblanet/Documents/National University/CSC242/Week 4/SamblanetJacobAssignment05/SamblanetJacobAssignment05_Part1/words");
    if (dictionaryFile.fail()) {
        cout << "Error opening words file" << endl;
        return -1;
    }
    vector<string> words;
    string word;

    // Load all dictionary words into vector
    while (dictionaryFile >> word) {
        words.push_back(word);
    }
    dictionaryFile.close();

    // Open the file containing words to check
    ifstream checkFile("/Users/jacobsamblanet/Documents/National University/CSC242/Week 4/SamblanetJacobAssignment05/SamblanetJacobAssignment05_Part1/input");
    if (checkFile.fail()) {
        cout << "Error opening check file" << endl;
        return -1;
    }
    string inputWord;

    // Check each word from input against the dictionary
    while (checkFile >> inputWord) {

        bool found = false;

        // LSearch for the word in the dictionary
        for (const string& w : words) {
            if (w == inputWord) {
                found = true;
                break;

            }
        }

        // Print words not found in the dictionary
        if (!found) {
            cout << inputWord << endl;
        }
    }
    checkFile.close();
    return 0;
}
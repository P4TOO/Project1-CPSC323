//
// Created by diego on 10/7/2024.
//

#ifndef PROJECT1_H
#define PROJECT1_H

#include<iostream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
using namespace std;

//Outputs two of the same size vectors in tabular form
void outputChart(vector<string> data1, vector<string> data2);
//Checks if string is a Keyword or Identifier returns literal string
string checkKeyword(string str);
//takes a string and removes all excess space
string removeSpaces(string& input);
//Reads from input txt file and returns a vector of strings each element is a line of file
vector<string> readFile();
//Takes in vector lines and tokenizes it and labels categories respectively
void tokenize(vector<string> lines, vector<string> &tokens, vector<string> &categories);


#endif //PROJECT1_H

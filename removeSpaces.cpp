#include "Project1.h"

string removeSpaces(string& input) {
    istringstream iss(input);
    string word, result;

    // Read words from the input string
    while (iss >> word) {
        if (!result.empty()) {
            result += " "; // Add a single space before the next word
        }
        result += word; // Append the current word
    }

    return result; // Return the processed string
}
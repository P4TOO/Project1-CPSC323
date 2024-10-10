#include "Project1.h"

string checkKeyword(string str) {
    if (str == "include" || str == "iostream" || str == "using" || str == "namespace" || str == "std" || str == "int"
        || str == "return" || str == "main" || str == "cout" || str == "endl" || str == "if" || str == "else") {
        return "Keyword";
        }
    else {
        return "Identifier";
    }
}
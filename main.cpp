// Name: Diego Salas
// Class: CPSC 323
// Assignment: Project 1
#include "Project1.h"

    int main(){
        //Put's all code from input file to code vector (Removes comments and excess space)
        vector<string> code = readFile();
        vector<string> tokens;              //Stores tokenized code
        vector<string> categories;          //Stores categories of tokens



        tokenize(code, tokens, categories);     //Tokenizes code

        //Output tokens and categories in tabular form
        outputChart(categories, tokens);
        cout << endl << endl;

        //Output code with removed space and comments
        cout << "Here is the code after removing excess space and comments.\n";
        cout << "----------------------------------------------------------\n";
        for (int i = 0; i < code.size(); i++) {
            cout << code[i] << endl;
        }

        return 0;
    }
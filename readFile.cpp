#include "Project1.h"

vector<string> readFile()
{
    ifstream inputFile("C:/Users/diego/CLionProjects/Project1/input2.txt"); // Address of input file

    //Checks if file was opened succesfully
    if (!inputFile.is_open()) {
        cout << "Error opening file!" << endl;
        return {"0"};
    }

    //Put each line of txt file as an element of vector lines
    int i = 0;\
    vector<string> lines;
    string line;
    string temp2;
    bool voidLine = false;
    while (getline(inputFile, line)) {
        //Remove excess space
        line = removeSpaces(line);

        //Removes comments from line
        for (i = 0; i < line.length(); i++) {
            if (line[i] == '/' && line[i+1] == '/') {
                int countToPop = line.length() - i;

                for (int j = 0; j < countToPop; j++) {
                    line.pop_back();
                }
            }
        }

        //if line contains substring '//' skip line (Gets rid of comments)
        if (line[0] == '/' && line[1] == '/') {

        }
        else if (line[0] == '*' && line[1] == '/') { //If line contains substring '\*' it sets voidLine to false
            voidLine = false;
        }
        else if (voidLine) { //If voidLine is true skip line

        }
        else if (line[0] == '/' && line[1] == '*') { //If line contains substring '\*' it sets voidLine to true and skips all lines until off
            voidLine = true;
        }
        else if (line.size() == 0) {   //Skips empty line

        }
        else {
            lines.push_back(line);
            i++;
        }
    }

    inputFile.close();

    return lines;
}
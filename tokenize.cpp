#include "Project1.h"

void tokenize(vector<string> lines, vector<string> &tokens, vector<string> &categories) {

    for(int x = 0; x < lines.size(); x++) {
        string line = lines[x];
        string token;

        for(int i = 0; i < line.size(); i++) {
            //Tokenize # as Keyword
            //Skips to next line if encounters comment
            if (line[i] == '/' && line[i+1] == '/') {
                break;
            }
            if(line[i] == '#') {
                token = line[i];
                tokens.push_back(token);
                categories.emplace_back("Keyword");
            }
            //Tokenize Operators
            else if (line[i] == '=' || line[i] == '-' || line[i] == '+' || line[i] == '<' || line[i] == '>') {
                token = line[i];
                //Special case for substring '<<'
                if (line[i + 1] == '<') {
                    i++;
                    token.push_back(line[i]);
                }
                tokens.push_back(token);
                categories.emplace_back("Operator");
            }
            //Tokenize Delimeters
            else if (line[i] == '(' || line[i] == ')' || line[i] == ';' || line[i] == ',' || line[i] == '{' || line[i] == '}') {    //Tokenize Separator
                token = line[i];
                tokens.push_back(token);
                categories.emplace_back("Delimiter");
            }
            //Tokenize string literals
            else if (line[i] == '\"') {     //Tokenize string literal "..."
                bool reading = true;

                while (reading) {
                    token.push_back(line[i]);
                    i++;
                    if (line[i] == '\"') {
                        token.push_back(line[i]);
                        reading = false;
                    }
                }
                tokens.push_back(token);
                categories.emplace_back("Literal");
            }
            //Tokenize (Keyword\Identifiers)
            else if (isalpha(line[i])) {    //Tokenize Keyword or Identifier
                bool reading = true;

                while(reading) {
                    token.push_back(line[i]);
                    i++;

                    //Check end of word
                    if (isalpha(line[i]) == false ) {
                        //Special case if identifier ends with a number
                        if (isdigit(line[i])) {
                            reading = false;
                            token.push_back(line[i]);
                            tokens.push_back(token);
                            categories.emplace_back("Identifier");
                        }
                        else {
                            reading = false;
                            tokens.push_back(token);
                            //Place function to determine if Keyword or Literal
                            categories.emplace_back(checkKeyword(token));
                            i--;
                        }
                    }
                }
            }
            //Tokenize numeric literals
            else if (isdigit(line[i])) {
                bool reading = true;

                while (reading) {
                    token.push_back(line[i]);
                    i++;
                    //If end of number is reached
                    if (isdigit(line[i]) == false) {
                        reading = false;
                        tokens.push_back(token);
                        categories.emplace_back("Literal");
                        i--;
                        }
                }

                }
            //Resets token for rest of line
            token = "";
        }
        }
    }
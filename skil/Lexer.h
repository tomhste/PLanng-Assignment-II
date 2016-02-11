#ifndef LEXER_H
#define LEXER_H
#include "Token.h"
#include <sstream>
#include <string>
using namespace std;

class Lexer
{
    public:
        Lexer();
        // Scans the standard input (stdin)
        // Looks for patterns that match one of the tokens from TokenCode
        // See assignment for details

        Token nextToken();
        // The lexical analyzer (this class) returns a token with TokenCode = ERROR
        // if some illegal lexeme is found.

        // Checks if input is of TokenCode type ID
        void buildID(string &key);
        // Checks if input is of TokenCode type INT
        void buildINT(string &key);
};

#endif // LEXER_H

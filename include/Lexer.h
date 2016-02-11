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
        bool isLegalID(string input);
        // Checks if input is of TokenCode type INT
        bool isLegalINT(string input);
};

#endif // LEXER_H

#ifndef LEXER_H
#define LEXER_H
#include "Token.h"
using namespace std;

class Lexer
{
    public:
        Lexer();
        // Scans the standard input (stdin)
        // Looks for patterns that match one of the tokens from TokenCode
        // See assignment for details

        TokenCode nextToken();
        // The lexical analyzer (this class) returns a token with TokenCode = ERROR
        // if some illegal lexeme is found.
};

#endif // LEXER_H

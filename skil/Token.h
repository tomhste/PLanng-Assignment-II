#ifndef TOKEN_H
#define TOKEN_H
#include "Token.h"
#include <string>

enum TokenCode {
    ID,
    ASSIGN,
    SEMICOL,
    INT,
    ADD,
    SUB,
    MULT,
    LPAREN,
    RPAREN,
    PRINT,
    END,
    ERROR
};

using namespace std;
class Token
{
    public:
        string lexeme;
        TokenCode tCode;
};

#endif // TOKEN_H

#ifndef PARSER_H
#define PARSER_H
#include "Token.h"
#include "Lexer.h"
// a top-down recursive descent parser
// The output of the parser is the stack-based intermediate code S

class Parser
{
    public:
        Parser(Lexer myLexer);
        void parse();

    protected:

    private:
        Lexer lexer;
        Token currentToken;
};

#endif // PARSER_H

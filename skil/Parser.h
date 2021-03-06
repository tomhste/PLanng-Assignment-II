#ifndef PARSER_H
#define PARSER_H
#include "Token.h"
#include "Lexer.h"
#include <vector>
// a top-down recursive descent parser
// The output of the parser is the stack-based intermediate code S

class Parser
{
    public:
        Parser(Lexer &myLexer);
        void parse();
    private:
        Lexer lexer;
        Token currentToken;
        vector<string> keyVector;
        void parseStatements();
        void parseStatement();
        void parseExpr();
        void parseTerm();
        void parseFactor();
        void syntaxError();

};

#endif // PARSER_H

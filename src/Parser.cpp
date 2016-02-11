#include "Parser.h"
#include <iostream>
#include <vector>

Parser::Parser(Lexer &myLexer){
    this->lexer = myLexer;
}

void Parser::parse(){
    currentToken = lexer.nextToken();
    parseStatements();
}

/// Non terminals: Statements (starting symbol), Statement, Expr, Term and Factor
///     terminals: ;, end, id, print, +, -, *, int, (, )

///      parseStatements(); << calls: parseStatement() | ends
bool Parser::parseStatements(){
    if(currentToken.tCode!= END)
        parseStatement();
    return false;
}

///      parseStatement();  << calls: parseExpr() | print id
bool Parser::parseStatement(){

    return false;
}

///      parseExpr();       << calls: parseTerm() | parseTerm() + parseExpr() | parseTerm() - ParseExpr
bool Parser::parseExpr(){

    return false;
}

///      parseTerm();       << calls: parseFactor() | parseFactor() * parseTerm()
bool Parser::parseTerm(){

    return false;
}

///      parseFactor();     << calls: int | id | ( parseExpr() )
bool Parser::parseFactor(){

    return false;
}

void Parser::syntaxError(){
    cout << "Syntax Error" << endl;
}

#include "Parser.h"
#include <iostream>
#include <sstream>
#include <vector>

Parser::Parser(Lexer &myLexer){
    this->lexer = myLexer;
}

void Parser::parse(){

    // Various test input, will be replaced by stdin.
    string test1 = "number = 3";
    string test2 = "var = 2 * 3 ( ) ( ) ( ) ( ) 3 + 65";

    // We simulate stdin by placing the test strings into a stringstream, replaced later by stdin.
    stringstream ss(test2);

    // A pattern is a description of the form that the lexemes of a token may take.
    // In the case of a keyword as a token, the pattern is just the sequence of
    // characters that form the keyword. For identifiers and some other tokens,
    // the pattern is more complex structure that is matched by many strings.
    vector<Token> pattern;

    // Input is split up by whitespace and parsed into Tokens.
    string key;
    while(ss >> key){
        keyVector.push_back(key);
    }

    parseStatements();
}

/// Non terminals: Statements (starting symbol), Statement, Expr, Term and Factor
///     terminals: ;, end, id, print, +, -, *, int, (, )

///      parseStatements(); << calls: parseStatement() | ends
bool Parser::parseStatements(){

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

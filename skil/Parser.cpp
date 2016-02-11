#include "Parser.h"
#include <iostream>
#include <vector>
#include <stdlib.h>

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
void Parser::parseStatements(){
    parseStatement();
    if(currentToken.tCode == SEMICOL){
        currentToken = lexer.nextToken();
        parseStatements();
    }
    else if(currentToken.tCode == END){
        // do nothing, returning to parse().
    }
    else{
        syntaxError();
    }
}

///      parseStatement();  << calls: parseExpr() | print id
void Parser::parseStatement(){
    if(currentToken.tCode == ID){
        cout << "PUSH " << currentToken.lexeme << endl;
        currentToken = lexer.nextToken();
        if(currentToken.tCode == ASSIGN){
            currentToken = lexer.nextToken();
            parseExpr();
            cout << "ASSIGN" << endl;
        }
    }
    else if(currentToken.tCode == PRINT){
        currentToken = lexer.nextToken();
        if(currentToken.tCode == ID){
            cout << "PUSH " << currentToken.lexeme << endl;
            cout << "PRINT" << endl;
            currentToken = lexer.nextToken();
        }
        else
            syntaxError();
    }
}

///      parseExpr();       << calls: parseTerm() | parseTerm() + parseExpr() | parseTerm() - ParseExpr
void Parser::parseExpr(){
    parseTerm();
    if(currentToken.tCode == ADD){
        currentToken = lexer.nextToken();
        if(currentToken.tCode == INT || currentToken.tCode == ID || currentToken.tCode == LPAREN){
            parseExpr();
            cout << "ADD" << endl;
        }
        else
            syntaxError();
    }
    else if(currentToken.tCode == SUB){
            currentToken = lexer.nextToken();
        if(currentToken.tCode == INT || currentToken.tCode == ID || currentToken.tCode == LPAREN){
            parseExpr();
            cout << "SUB" << endl;
        }
        else
            syntaxError();
    }
}

///      parseTerm();       << calls: parseFactor() | parseFactor() * parseTerm()
void Parser::parseTerm(){
    parseFactor();
    currentToken = lexer.nextToken();
    if(currentToken.tCode == MULT){
        currentToken = lexer.nextToken();
        if(currentToken.tCode == INT || currentToken.tCode == ID || currentToken.tCode == LPAREN){
            parseTerm();
            cout << "MULT" << endl;
        }
        else
            syntaxError();
    }
}

///      parseFactor();     << calls: int | id | ( parseExpr() )
void Parser::parseFactor(){
    if(currentToken.tCode == INT || currentToken.tCode == ID){
        cout << "PUSH " << currentToken.lexeme << endl;
    }
    else if(currentToken.tCode == LPAREN){
        currentToken = lexer.nextToken();
        parseExpr();
        if(currentToken.tCode != RPAREN){
            syntaxError();
        }
    }
}

void Parser::syntaxError(){
    cout << "Syntax Error!" << endl;
    exit(0);
}

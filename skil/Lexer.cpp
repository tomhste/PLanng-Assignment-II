#include "Lexer.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

Lexer::Lexer(){
}

Token Lexer::nextToken(){
    string key = "";
    key += cin.get();
    // check input
    while(key == " " || key == "\n" || key == "\t") // skipping over whitespace and newline
        key = cin.get();

    TokenCode inputToken;
    inputToken = ERROR;
    if(key == "=")
        inputToken = ASSIGN;
    else if(key == ";")
        inputToken = SEMICOL;
    else if(key == "+")
        inputToken = ADD;
    else if(key == "-")
        inputToken = SUB;
    else if(key == "*")
        inputToken = MULT;
    else if(key == "(")
        inputToken = LPAREN;
    else if(key == ")")
        inputToken = RPAREN;
    else if(isalpha(key[0])){
        buildID(key);
        inputToken = ID;
    }
    else if(isdigit(key[0])){
        buildINT(key);
        inputToken = INT;
    }

    if(key == "print")
        inputToken = PRINT;
    if(key == "end")
        inputToken = END;

    // No need to continue...
    if(inputToken == ERROR){
        cout << "Syntax error!" << endl;
        exit(0);
    }

    Token tmpToken;

    // A lexeme is a sequence of characters in the source program that
    // matches the pattern for a token and is identified by the lexical
    // analyzer as an instance of that token.
    tmpToken.lexeme = key;

    // A token is a pair consisting of a token name and an optional attribute value.
    // The token name is an abstract symbol representing a kind of lexical unit, e.g.,
    // a particular keyword, or sequence of input characters denoting an identifier.
    // The token names are the input symbols that the parser processes.
    tmpToken.tCode = inputToken;
    return tmpToken;
}

void Lexer::buildID(string &key){
    while(isalpha(cin.peek()))
        key += cin.get();
}

void Lexer::buildINT(string &key){
    while(isdigit(cin.peek()))
        key += cin.get();
}

#include "Lexer.h"
#include <iostream>

Lexer::Lexer(){

}

Token Lexer::nextToken(string key){

    TokenCode inputToken;
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
    else if(key == "{")
        inputToken = LPAREN;
    else if(key == "}")
        inputToken = RPAREN;
    else if(key == "print")
        inputToken = PRINT;
    else if(key == "end")
        inputToken = END;
    else if(isLegalID(key))
        inputToken = ID;
    else if(isLegalINT(key))
        inputToken = INT;
    else
        inputToken = ERROR;

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

bool Lexer::isLegalID(string key){
    for(size_t i = 0; i < key.size(); i++){
        if(!isalpha(key[i]))
            return false;
    }
    return true;
}

bool Lexer::isLegalINT(string key){
    for(size_t i = 0; i < key.size(); i++){
        if(!isdigit(key[i]))
            return false;
    }
    return true;
}

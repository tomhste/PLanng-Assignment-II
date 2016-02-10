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
    string test2 = "var = 2 * 3";

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
        pattern.push_back(lexer.nextToken(key));
    }

    // Debug printout!
    for(size_t i = 0; i < pattern.size(); i++){
        cout << "Token #" << i << endl;
        cout << "Lexeme: " << pattern[i].lexeme << endl;
        cout << "Token id: " << pattern[i].tCode << endl;
        cout << endl;
    }
}

#include "Parser.h"
#include <iostream>

Parser::Parser(Lexer &myLexer){

}

void Parser::parse(){
    cout << "Inside Parser::parse()" << endl;
    cout << "This is: Assign " << MULT << endl;
    cout << "This is: id " << ID << endl;
}

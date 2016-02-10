#include <iostream>
#include "Lexer.h"
#include "Parser.h"

using namespace std;

int main()
{
    Lexer myLexer;
    Parser myParser(myLexer);
    myParser.parse();

    return 0;
}

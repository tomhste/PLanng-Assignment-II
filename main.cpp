#include <iostream>
#include "main.h"

using namespace std;

int main()
{
    Classone classone;
    while(true)
    {
        string cmd;
        cin >> cmd;
        if(cmd == "add")
        {
            string word;
            cin >> word;
            classone.incr(word);
        }
        if(cmd == "print")
        {
            classone.get_by_freq();
        }

    }
    return 0;
}

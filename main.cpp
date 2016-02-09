#include <iostream>
#include "main.h"

using namespace std;

int main()
{
    Counter counter;
    while(true)
    {
        string cmd;
        cin >> cmd;
        if(cmd == "add")
        {
            string word;
            cin >> word;
            counter.incr(word);
        }
        if(cmd == "print")
        {
            counter.get_by_freq();
        }
    }
    return 0;
}

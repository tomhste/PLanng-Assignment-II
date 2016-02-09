#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Test
{
public:
    string Name;
    void Sleep() //This is a normal function
    {
        cout << "Zzz" << endl;
    }
    virtual void Move() //This is a virtual function which mean it can be overridden in the super class
    {
        cout << "I moved forward" << endl;
    }
    virtual void Speak() = 0; //The = 0 means the function is abstract and must be defined in super class
};




#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//Struct
struct OurDataType
{
public:
    int frequency;
    string word;
    OurDataType(string word)
    {
        this->word = word;
        frequency = 1;
    }
};


bool alphabetical(string a, string b)
{
    int x = min(a.length(), b.length());

    for(int i = 0; i < x; i++)
    {
        if(a[i] > b[i])
            return false;
    }

    return true;
}

bool operator < (OurDataType a, OurDataType b)
{
    if(a.frequency == b.frequency)
    {
        return alphabetical(a.word, b.word);
    }
    else
    {
        return b.frequency < a.frequency;
    }
}



class Classone
{
private:
    vector<OurDataType> words;
public:
    //linulegt
    void incr(string word)
    {
        for(unsigned int i = 0; i < words.size(); i++)
        {
            if(words[i].word == word)
            {
                words[i].frequency++;
                return;
            }
        }
        //We didn't find the word in the vector so we create it
        OurDataType w(word);
        words.push_back(w);
    }
    //linulegt
    void get_by_freq()
    {
        //We can do this so easily because we made a custom < operator for OurDataType
        sort(words.begin(), words.end());
        for(unsigned int i = 0; i < words.size(); i++)
        {
            cout << words[i].word << " " << words[i].frequency << endl;
        }
    }
};

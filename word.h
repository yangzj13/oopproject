#ifndef __WORD_H__
#define __WORD_H__

#include <string>
#include "explain.h"

#define _NOT_KNOW_ 0
#define _KNOW_ 1

using namespace std;

class Word
{
    string * name;
    Explain * explain;
    int level;
public:
    Word(const char * _name, string _ex, int _l = 0):name(new string(_name)),
                                               explain(new Explain(_ex)),
                                               level(_l){};
    ~Word()
    {
        delete name;
        delete explain;
    }
    string getName()
    {
        return *name;
    }
    string getExplain()
    {
            return explain->getExplain();
    }
    int getLevel()
    {
        return level;
    }
};

#endif //__WORD_H__

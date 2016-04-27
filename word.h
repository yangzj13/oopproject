#ifndef __WORD_H__
#define __WORD_H__

#include <string>

#define _NOT_KNOW_ 0
#define _KNOW_ 1

using namespace std;

class Word
{
    string name;
    string explain;
    int level;
public:
    Word(string _name, string _ex, int _l = 0):name(string(_name)),
                                               explain(string(_ex)),
                                               level(_l){};
    ~Word(){}
    string getName()
    {
        return name;
    }
    string getExplain()
    {
            return explain;
    }
    int getLevel()
    {
        return level;
    }
	void setLevel(int _l){
		level = _l;
	}
};

#endif //__WORD_H__

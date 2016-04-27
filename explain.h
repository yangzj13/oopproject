#ifndef __EXPLAIN_H__
#define __EXPLAIN_H__

#include <string>

using namespace std;

class Explain
{
    string * explain;
public:
    Explain(string _s)
    {
        explain = new string(_s);
    }
    ~Explain()
    {
        delete explain;
    }
    string getExplain()
    {
        return *explain;
    }
};

#endif

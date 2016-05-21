#ifndef __COUNTER_H__
#define __COUNTER_H__

#include "dict.h"
#include <algorithm>

using namespace std;

class Counter{
	vector<string> words;
	string filename;
	bool is_valid;
	
public:
	void setWords();
	Counter(const string& _filename) :filename(_filename), is_valid(false)
	{
		setWords();
	}
	void count(Dict &_dict);
};

#endif
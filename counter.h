#ifndef __COUNTER_H__
#define __COUNTER_H__

#include "dict.h"
#include <algorithm>

using namespace std;

class Counter{
	vector<string> words;
	string filename;
	
public:
	void setWords();
	Counter(const string& _filename) :filename(_filename){
		setWords();
	}
	void count(const Dict &_dict);
};

#endif
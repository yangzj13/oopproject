#ifndef __DICT_H__
#define __DICT_H__

#include "word.h"
#include <set>
#include <fstream>
#include <iostream>

struct wordLess
{
	bool operator() (const Word &a, const Word &b) const {
		if( a.getName() < b.getName() )
			return true;
		else
			return false;
	}
};

class Dict
{
	set<Word, wordLess> words;
public:
	Dict();
/* 	Dict(string _filename);
	void addWords(Word _word);
	Word& randomWord(int type = 0); */
	void searchWord(string _name);
/* 	string searchEx(string _name);
	int searchType(string _name);
    bool settype(string _name, int type); //返回是否设置成功 */
};

#endif
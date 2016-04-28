#ifndef __DICT_H__
#define __DICT_H__

#include "word.h"
#include <set>

class Dict
{
	set<Word> words;
public:
	dict();
	dict(string _filename);
	void addWords(Word _word);
	Word& randomWord(int type = 0);
	word& searchWord(string _name);
	string searchEx(string _name);
	int searchType(string _name);
    bool settype(string _name, int type); //返回是否设置成功
}
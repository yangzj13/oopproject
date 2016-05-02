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
	Dict(string _filename = "data/_cet4.txt");
	//void addWords(Word _word);
	string randomWord(int _level = 0);
	void searchWordEx(string _name); //直接输出单词解释
	bool addWordSenten(string _name, string _s); //一次只能加一句
	void searchWordSe(string _name); //直接输出单词例句
	int searchWordLevel(string _name);
    bool setWordLevel(string _name, int _level); //返回是否设置成功
};

#endif
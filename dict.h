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
	string filename;
public:
	Dict(string _filename = "data/_cet4.txt");
	//void addWords(Word _word);
	string randomWord(int _seed, int _level = 0);
	void searchWordEx(string _name); //直接输出单词解释
	void searchWordEx(string _name, int _times);//输出单词解释和次数
	bool addWordSenten(string _name, string _s); //一次只能加一句
	void searchWordSe(string _name); //直接输出单词例句
	int searchWordLevel(string _name);
    bool setWordLevel(string _name, int _level); //返回是否设置成功
	~Dict();
};

class Cet4{
private:
	static Dict* instance;
protected:
	Cet4(){}
public:
	static Dict* getInstance();
	static void saveInstance(); //保存修改
};

class Cet6{
private:
	static Dict* instance;
protected:
	Cet6(){}
public:
	static Dict* getInstance();
	static void saveInstance(); //保存修改
};

class Gre{
private:
	static Dict* instance;
protected:
	Gre(){}
public:
	static Dict* getInstance();
	static void saveInstance(); //保存修改
};

#endif
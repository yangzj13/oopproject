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
	set<Word, wordLess>::iterator nowIter;
public:
	Dict(const string& _filename = "data/_cet4.txt");
	//void addWords(Word _word);
	bool searchWord(const string& _name);
	string randomWord(int _seed);//生成随机单词
	int dictSize();//返回词典单词数
	string getWord(int _pos);//返回特定单词
	void searchWordEx(const string& _name); //直接输出单词解释
	void searchWordEx(const string& _name, int _times);//输出单词解释和次数 专门为counter设计
	void addWordSenten(const string& _name, const string& _s); //一次只能加一句
	void searchWordSe(const string& _name); //直接输出单词例句
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
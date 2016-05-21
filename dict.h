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
	string randomWord(int _seed);//�����������
	int dictSize();//���شʵ䵥����
	string getWord(int _pos);//�����ض�����
	void searchWordEx(const string& _name); //ֱ��������ʽ���
	void searchWordEx(const string& _name, int _times);//������ʽ��ͺʹ��� ר��Ϊcounter���
	void addWordSenten(const string& _name, const string& _s); //һ��ֻ�ܼ�һ��
	void searchWordSe(const string& _name); //ֱ�������������
	~Dict();
};

class Cet4{
private:
	static Dict* instance;
protected:
	Cet4(){}
public:
	static Dict* getInstance();
	static void saveInstance(); //�����޸�
};

class Cet6{
private:
	static Dict* instance;
protected:
	Cet6(){}
public:
	static Dict* getInstance();
	static void saveInstance(); //�����޸�
};

class Gre{
private:
	static Dict* instance;
protected:
	Gre(){}
public:
	static Dict* getInstance();
	static void saveInstance(); //�����޸�
};

#endif
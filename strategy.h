#ifndef __STRATEGY_H__
#define __STRATEGY_H__

#include <string>
#include <ctime>
#include <iostream>
using namespace std;

class Strategy{
	int size;
public:
	Strategy(int _size): size(_size){}
	int getSize() const {return size;}
	virtual bool judge(const string& _word, int _times, int _correct) = 0;
	virtual void showStrategy() = 0;
	virtual ~Strategy(){}
};

class defaultStrategy : public Strategy
{
public:
	defaultStrategy(int _size): Strategy(_size){}
	bool judge(const string& _word, int _times, int _correct){
		return true;
	}
	void showStrategy(){
		cout << endl << "Ĭ�ϲ���(�޲��ѡȡ����)" << endl;
	}
	~defaultStrategy(){}
};

class newStrategy : public Strategy
{
public:
	newStrategy(int _size): Strategy(_size){}
	bool judge(const string& _word, int _times, int _correct);
	void showStrategy(){
		cout << endl << "ѡȡδ���䵥��" << endl;
	}
	~newStrategy(){}
};

class familiarStrategy : public Strategy
{
public:
	familiarStrategy(int _size): Strategy(_size){}
	bool judge(const string& _word, int _times, int _correct);
	void showStrategy(){
		cout << endl << "ѡȡ��Ϥ�ĵ���" << endl;
	}
	~familiarStrategy(){}
};

class hardStrategy : public Strategy
{
public:
	hardStrategy(int _size): Strategy(_size){}
	bool judge(const string& _word, int _times, int _correct);
	void showStrategy(){
		cout << endl << "ѡȡ�ϳ��ĵ��ʺ��״�ĵ���" << endl;
	}
	~hardStrategy(){}
};

class unfamiliarStrategy : public Strategy
{
public:
	unfamiliarStrategy(int _size): Strategy(_size){}
	bool judge(const string& _word, int _times, int _correct);
	void showStrategy(){
		cout << endl << "ѡȡ������δ����ĵ���" << endl;
	}
	~unfamiliarStrategy(){}
};

#endif
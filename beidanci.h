#ifndef __BEIDANCI_H__
#define __BEIDANCI_H__

#include "counter.h"
#include "user.h"
#include "command.h"

const int CET4 = 1;
const int CET6 = 2;
const int GRE  = 3;

class Beidanci{
	User* user;
	Dict* dict;
	Command* command;
	Strategy* strategy;
	int now_dict;
	Beidanci(const Beidanci&);
	Beidanci& operator=(const Beidanci&);
	int number;
	int times;
	float uc;
	float dc;
	
	//切换词典 在记忆擦略底下使用
	void switchDict();
	//记忆策略
	void setStrategy();
	//学习单词
	void study();
	//生词统计
	void count();
	//添加例句
	void addSe(const string& _word);
	//查询单词 
	void search();
	void search(const string& _word);
	//单词测试
	void test();
	//查询历史
	void history();
	//退出系统 
	void exitB();
	//保存修改
	void save();
	//打印空行
	void printBlankLines(int _n);
	//清理屏幕
	void cls();
	//暂停
	void pause();
	
public:
	Beidanci(Command* _command);
	//登陆
	bool login();
	//运行
	void run();
};

#endif
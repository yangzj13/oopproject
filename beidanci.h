#ifndef __BEIDANCI_H__
#define __BEIDANCI_H__

#define CET4 1
#define CET6 2
#define  GRE 3

#include "counter.h"
#include "history.h"

class Beidanci{
	Dict* dict;
	int now_dict;
	History his;
	
public:
	Beidanci();
	void run();
	//
	void switchDict();
	//记忆策略
	void setPolicy();
	//学习单词
	void study();
	//生词统计
	void count();
	//添加例句
	void addSe(string _word);
	//查询单词 
	void search();
	void search(string _word);
	//单词测试
	void test();
	//查询历史
	void history();
	//退出系统 
	void exitB();
	//保存修改
	void save();
	void printBlankLines(int _n);
};

#endif
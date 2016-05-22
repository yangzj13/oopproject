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
	
	//�л��ʵ� �ڼ�����Ե���ʹ��
	void switchDict();
	//�������
	void setStrategy();
	//ѧϰ����
	void study();
	//����ͳ��
	void count();
	//�������
	void addSe(const string& _word);
	//��ѯ���� 
	void search();
	void search(const string& _word);
	//���ʲ���
	void test();
	//��ѯ��ʷ
	void history();
	//�˳�ϵͳ 
	void exitB();
	//�����޸�
	void save();
	//��ӡ����
	void printBlankLines(int _n);
	//������Ļ
	void cls();
	//��ͣ
	void pause();
	
public:
	Beidanci(Command* _command);
	//��½
	bool login();
	//����
	void run();
};

#endif
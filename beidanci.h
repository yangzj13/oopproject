#ifndef __BEIDANCI_H__
#define __BEIDANCI_H__

#include "counter.h"
#include "user.h"

const int CET4 = 1;
const int CET6 = 2;
const int GRE  = 3;

class Beidanci{
	User* user;
	Dict* dict;
	int now_dict;
	Beidanci(const Beidanci&);
	Beidanci& operator=(const Beidanci&);
	int number;
	int times;
	float uc;
	float dc;
	
public:
	Beidanci();
	//��½
	bool login();
	//����
	void run();
	//�л��ʵ� �ڼ�����Ե���ʹ��
	void switchDict();
	//�������
	void setPolicy();
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
};

#endif
#ifndef __USER_H__
#define __USER_H__

#include "history.h"
#include "dict.h"
#include "strategy.h"

using namespace std;

class User{
	string user_name;
	vector<string> own_word_list;
	vector<int> times;
	vector<int> correct_times;
	History his;
	bool isYourWord(const string& _word, Strategy* _s);
public:
	User(const string& _user);
	vector<string> getHistory();
	void updateHistory(const string& _word);
	void updateWordList(const string& _word, bool _correct);
	vector<string> getSpecificWords(Strategy* _s, Dict* _dict);
	~User();
};

#endif
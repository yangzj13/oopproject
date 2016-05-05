#ifndef __HISTORY_H__
#define __HISTORY_H__

#include <string>
#include <vector>
#include <fstream>

using namespace std;

class History{
	vector<string> history_words;
	int max_size;
	
public:
	History(int _m = 20) : max_size(_m){
		ifstream fin("data/history.txt");
		string w;
		fin.get();
		while(!fin.eof()){
			fin >> w;
			history_words.push_back(w);
		}
	}
	void updateHistory(string _word){
		if(history_words.size() < max_size)
			history_words.push_back(_word);
		else{
			vector<string>::iterator iter = history_words.begin();
			history_words.erase(iter);
			history_words.push_back(_word);
		}
	}
	vector<string>& getHistory(){
		return history_words;
	}
	~History(){
		ofstream fout("data/history.txt");
		fout << endl;
		for(int i = 0;i < history_words.size()-1;i++)
			fout << history_words[i] << endl;
		fout << history_words[history_words.size()-1];
	}
};

#endif
#ifndef __HISTORY_H__
#define __HISTORY_H__

#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

class History{
	vector<string> history_words;
	int max_size;
	string file_name;
	
public:
	History(string _filename, int _m = 20) : max_size(_m), 
											 file_name(_filename)
	{
		ifstream fin(file_name);
		if(fin.good()){
			string w;
			fin.get();//空的历史文件也是会有一行的，所以让每个文件的第一行都为空行来解决这个问题
			while(!fin.eof()){
				fin >> w;
				history_words.push_back(w);
			}
		}
	}
	void updateHistory(const string& _word){
		vector<string>::iterator iter = find(history_words.begin(),
											 history_words.end(),
											 _word);
		if(iter == history_words.end()){
			if(history_words.size() < max_size)
				history_words.push_back(_word);
			else{
				vector<string>::iterator iter = history_words.begin();
				history_words.erase(iter);
				history_words.push_back(_word);
			}
		}
	}
	vector<string> getHistory(){
		return history_words;
	}
	~History(){
		ofstream fout(file_name);
		fout << endl;
		for(int i = 0;i < history_words.size()-1;i++)
			fout << history_words[i] << endl;
		if(history_words.size()-1 >= 0)
			fout << history_words[history_words.size()-1];
	}
};

#endif
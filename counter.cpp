#include "counter.h"

void Counter::setWords(){
	ifstream fin(filename, ios::binary);
	char letter;
	string word;
	if(fin.good()){
		is_valid = true;
		while(!fin.eof()){
			fin.read((char*)&letter, sizeof(letter));
			if(letter > 64 && letter < 91){
				letter += 32;
				word.push_back(letter);
			}
			else{
				if(letter > 96 && letter < 123){
					word.push_back(letter);
				}
				else{
					if(!word.empty()){
						words.push_back(word);
						word.clear();
					}
				}
			}
		}
		sort(words.begin(), words.end());
	}
	fin.close();
}

void Counter::count(Dict &_dict){
	if(is_valid){
		string now = words[0];
		int count = 0;
		for(int i = 0;i < words.size();i++){
			if(words[i] == now)
				count++;
			else{
				_dict.searchWordEx(now, count);
				count = 1;
				now = words[i];
			}
		}
		_dict.searchWordEx(now, count);
	}
	else
		cout << "打开失败！" << endl;
}
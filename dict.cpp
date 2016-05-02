#include "dict.h"
#include <sstream>
#include <cstdlib>
#include <ctime>

Dict::Dict(string _filename){
	ifstream file(_filename);
    while(!file.eof()){
        char buf[100];
        file.getline(buf, 100);
        string buffer(buf);
        int pos = buffer.find(' ');
        //��ȡ����
        string name = buffer.substr(0, pos);
        //��ȥ����
        buffer.erase(0, pos+1);
		pos = buffer.find("$");
        string ex = buffer.substr(0,pos);
        buffer.erase(0,pos+1);
		stringstream ss;
		ss << buffer;
		int type;
		ss >> type;
		words.insert( Word(name, ex, type) );
    }
    file.close();
}

void Dict::searchWordEx(string _name){
	Word f(_name, "find");
	set<Word, wordLess>::iterator iter;
	iter = words.find(f);
	if(iter != words.end()) {  
        cout << (*iter).getExplain() << endl;
    } else {  
        cout << "Cannot fine this word!" << endl;  
    }
}

int Dict::searchWordLevel(string _name){
	Word f(_name, "find");
	set<Word, wordLess>::iterator iter;
	iter = words.find(f);
	if(iter != words.end()) {  
        return (*iter).getLevel();
    } else {  
        return -1;  
    }
}

bool Dict::setWordLevel(string _name, int _level){
	Word f(_name, "find");
	set<Word, wordLess>::iterator iter;
	iter = words.find(f);
	if(iter != words.end()) {
        Word tmp(*iter);
		words.erase(iter);
		tmp.setLevel(_level);
		words.insert(tmp);
		return true;
    } else {
        return false;
    }
}

bool Dict::addWordSenten(string _name, string _s){
	Word f(_name, "find");
	set<Word, wordLess>::iterator iter;
	iter = words.find(f);
	if(iter != words.end()) {
        Word tmp(*iter);
		words.erase(iter);
		tmp.addSentence(_s);
		words.insert(tmp);
		return true;
    } else {
        return false;
    }
}

void Dict::searchWordSe(string _name){
	Word f(_name, "find");
	set<Word, wordLess>::iterator iter;
	iter = words.find(f);
	if(iter != words.end()) {
		cout << "����:" << endl;
        for(int i = 0;i < (*iter).getSentencesSize();i++){
			cout << (*iter).getSentences(i) << endl;
		}
    }
}

string Dict::randomWord(int _level){
	srand((unsigned int) time(NULL));
	int i = rand() * rand() % words.size(); //�������
	set<Word, wordLess>::iterator iter = words.begin();
	while(i--)
		iter++;
	while((*iter).getLevel() != _level){
		iter = words.begin();
		i = rand() * rand() % words.size();
		while(i--)
			iter++;
	}
	return (*iter).getName();
}
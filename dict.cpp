#include "dict.h"


Dict::Dict(string _filename){
	ifstream file(_filename);
    while(!file.eof()){
        char buf[100];
        file.getline(buf, 100);
        string buffer(buf);
        int pos = buffer.find(' ');
        //获取单词
        string name = buffer.substr(0, pos);
        //擦去单词
        buffer.erase(0, pos+1);
        string ex;
        ex = buffer;
		words.insert( Word(name, ex) );
    }
    file.close();
}

void Dict::searchWord(string _name){
	Word f(_name, "find");
	set<Word, wordLess>::iterator iter;
	iter = words.find(f);
	if(iter != words.end()) {  
        cout << (*iter).getExplain() << endl;  
    } else {  
        cout << "Cannot fine this word!" << endl;  
    }
}

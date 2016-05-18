#include "dict.h"
#include <sstream>
#include <cstdlib>
#include <ctime>

Dict::Dict(const string& _filename) : filename(_filename)
{
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
		pos = buffer.find("$");
        string ex = buffer.substr(0,pos);
        buffer.erase(0,pos+1);
		stringstream ss;
		int type;
		string t;
		Word* w;
        if( (pos = buffer.find('#') ) > -1){
            t = buffer.substr(0, pos);
            buffer.erase(0, pos+1);
			ss << t;
			ss >> type;
			w = new Word(name, ex, type);

            while( (pos = buffer.find('#') ) > -1){
                string s = buffer.substr(0, pos);
                w->addSentence(s);
                buffer.erase(0, pos+1);
            }

            w->addSentence(buffer);
        }
        else{
            t = buffer;
			ss << t;
			ss >> type;
			w = new Word(name, ex, type);
        }
		words.insert(*w);
    }
    file.close();
}

void Dict::searchWordEx(const string& _name) const
{
	Word f(_name, "find");
	set<Word, wordLess>::iterator iter;
	iter = words.find(f);
	if(iter != words.end()) {  
        cout << (*iter).getExplain() << endl;
    } else {  
        cout << "Cannot find this word!" << endl;  
    }
}

void Dict::searchWordEx(const string& _name, int _times) const
{
	Word f(_name, "find");
	set<Word, wordLess>::iterator iter;
	iter = words.find(f);
	if(iter != words.end()) {  
        cout << _name << " " << (*iter).getExplain()
		 << " " << _times << endl;
    }
}

int Dict::searchWordLevel(const string& _name) const
{
	Word f(_name, "find");
	set<Word, wordLess>::iterator iter;
	iter = words.find(f);
	if(iter != words.end()) {  
        return (*iter).getLevel();
    } else {  
        return -1;  
    }
}

bool Dict::setWordLevel(const string& _name, int _level){
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

bool Dict::addWordSenten(const string& _name, const string& _s){
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

void Dict::searchWordSe(const string& _name) const
{
	Word f(_name, "find");
	set<Word, wordLess>::iterator iter;
	iter = words.find(f);
	if(iter != words.end() && (*iter).getSentencesSize() > 0) {
		cout << "例句:" << endl;
        for(int i = 0;i < (*iter).getSentencesSize();i++){
			cout << (*iter).getSentences(i) << endl;
		}
    }
}

const string Dict::randomWord(int _seed, int _level) const{
	srand((unsigned int) time(NULL));
	int i = rand();
	srand(_seed);
	i = i * rand() % words.size(); //两次随机
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

Dict::~Dict(){
	ofstream fout(filename);
	set<Word, wordLess>::iterator iter = words.begin();
	set<Word, wordLess>::iterator eIter = words.end();
	eIter--;
	while(iter != eIter){
		fout << (*iter).getName() << " " << (*iter).getExplain() << "$";
		fout << (*iter).getLevel();
        for(int i = 0;i < (*iter).getSentencesSize();i++){
			fout << "#" << (*iter).getSentences(i);
		}
		fout << endl;
		iter++;
	}
	fout << (*eIter).getName() << " " << (*eIter).getExplain() << "$";
	fout << (*eIter).getLevel();
    for(int i = 0;i < (*eIter).getSentencesSize();i++){
		fout << "#" << (*eIter).getSentences(i);
	}
	fout.close();
}

Dict* Cet4::instance = NULL;
Dict* Cet4::getInstance(){
	if (instance == NULL){
		instance = new Dict();
	}
	return instance;
}
void Cet4::saveInstance(){
	if(instance != NULL){
		delete instance;
		instance = NULL;
	}
}

Dict* Cet6::instance = NULL;
Dict* Cet6::getInstance(){
	if (instance == NULL){
		instance = new Dict("data/_cet6.txt");
	}
	return instance;
}
void Cet6::saveInstance(){
	if(instance != NULL){
		delete instance;
		instance = NULL;
	}
}

Dict* Gre::instance = NULL;
Dict* Gre::getInstance(){
	if (instance == NULL){
		instance = new Dict("data/_gre.txt");
	}
	return instance;
}
void Gre::saveInstance(){
	if(instance != NULL){
		delete instance;
		instance = NULL;
	}
}
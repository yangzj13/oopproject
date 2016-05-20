#include "dict.h"
#include <sstream>
#include <cstdlib>
#include <ctime>

Dict::Dict(const string& _filename) : filename(_filename), nowIter()
{
	ifstream file(_filename);
    while(!file.eof()){
        string buffer;
        getline(file, buffer);
        int pos = buffer.find(' ');
        //获取单词
        string name = buffer.substr(0, pos);
        //擦去单词
        buffer.erase(0, pos+1);
		pos = buffer.find("$");
        string ex = buffer.substr(0,pos);
        buffer.erase(0,pos+1);
		Word* w;
        if( (pos = buffer.find('#') ) > -1){
            buffer.erase(0, pos+1);
			w = new Word(name, ex);

            while( (pos = buffer.find('#') ) > -1){
                string s = buffer.substr(0, pos);
                w->addSentence(s);
                buffer.erase(0, pos+1);
            }

            w->addSentence(buffer);
        }
        else{
			w = new Word(name, ex);
        }
		words.insert(*w);
    }
	nowIter = words.end();
    file.close();
}

bool Dict::searchWord(const string& _name){
	if(nowIter != words.end() && (*nowIter).getName() == _name) //如果查之前就已经是了就不再查了
		return true;
	else{
		Word f(_name, "find");
		nowIter = words.find(f);
		if(nowIter != words.end())
			return true;
		else
			return false;
	}
}

void Dict::searchWordEx(const string& _name){
	if(searchWord(_name)){  
        cout << (*nowIter).getExplain() << endl;
    }
}

void Dict::searchWordEx(const string& _name, int _times)
{
	if(searchWord(_name)) {  
        cout << _name << " " << (*nowIter).getExplain()
		 << " " << _times << endl;
    }
}

void Dict::addWordSenten(const string& _name, const string& _s){
	if(searchWord(_name)) {
        Word tmp(*nowIter);
		words.erase(nowIter++);
		tmp.addSentence(_s);
		words.insert(tmp);
    }
}

void Dict::searchWordSe(const string& _name)
{
	if(searchWord(_name) && (*nowIter).getSentencesSize() > 0) {
		cout << "例句:" << endl;
        for(int i = 0;i < (*nowIter).getSentencesSize();i++){
			cout << (*nowIter).getSentences(i) << endl;
		}
    }
}

string Dict::randomWord(int _seed){
	srand((unsigned int) time(NULL));
	int i = rand();
	srand(_seed);
	i = i * rand() % words.size(); //两次随机
	nowIter = words.begin();
	while(i--)
		nowIter++;
	return (*nowIter).getName();
}

Dict::~Dict(){
	ofstream fout(filename);
	nowIter = words.begin();
	set<Word, wordLess>::iterator eIter = words.end();
	eIter--;
	while(nowIter != eIter){
		fout << (*nowIter).getName() << " " << (*nowIter).getExplain() << "$";
        for(int i = 0;i < (*nowIter).getSentencesSize();i++){
			fout << "#" << (*nowIter).getSentences(i);
		}
		fout << endl;
		nowIter++;
	}
	fout << (*eIter).getName() << " " << (*eIter).getExplain() << "$";
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
#include "user.h"

User::User(const string& _user): user_name(_user),
								his("user_data/"+_user+"_history.txt")
{
	ifstream fin("user_data/"+_user+"_list.txt");
	if(fin.good()){
		fin.get();//去空行
		string w;
		int t;
		int correct;
		while(!fin.eof()){
			fin >> w;
			fin >> t >> correct;
			own_word_list.push_back(w);
			times.push_back(t);
			correct_times.push_back(correct);
		}
	}
	fin.close();
}

bool User::isYourWord(const string& _word, int _times,
					  float _ucorrect, float _dcorrect)
{
	vector<string>::iterator iter = find(own_word_list.begin(),
									 own_word_list.end(),
									 _word);
	int t = 0;
	float c = 0;
	if(iter != own_word_list.end()){
		int pos = iter - own_word_list.begin();
		t = times[pos];
		c = (float)correct_times[pos] / (float)times[pos];
	}
	if(t >= _times && c >= _dcorrect && c <= _ucorrect)
		return true;
	else
		return false;
}

vector<string> User::getHistory(){
	return his.getHistory();
}

void User::updateHistory(const string& _word){
	his.updateHistory(_word);
}

void User::updateWordList(const string& _word, bool _correct){
	vector<string>::iterator iter = find(own_word_list.begin(),
										 own_word_list.end(),
										 _word);
	if(iter != own_word_list.end()){
		int pos = iter - own_word_list.begin();
		times[pos] += 1;
		if(_correct) correct_times[pos] += 1;
	}
	else{
		own_word_list.push_back(_word);
		times.push_back(1);
		if(_correct)
			correct_times.push_back(1);
		else
			correct_times.push_back(0);
	}
}

vector<string> User::getSpecificWords(int _size, Dict* _dict,
									  int _times, float _ucorrect,
									  float _dcorrect)
{
	int size = _dict->dictSize();
	vector<string> ws;
	bool* b = new bool[size];
	for(int i = 0;i < size;i++)
		b[i] = false;
	srand(_size);
	int r = rand() % size;
	int r0 = r;	
	while(_size){
		if(!b[r] && isYourWord(_dict->getWord(r),_times,_ucorrect,_dcorrect)){
			b[r] = true;
			ws.push_back(_dict->getWord(r));
			_size--;
			srand(_size);
			r = rand() % size;
			r0 = r;
		}
		else{
			b[r++] = true;
			r = r % size;
			if(r == r0)
				break;
		}
	}
	return ws;
}

User::~User(){
	ofstream fout("user_data/"+user_name+"_list.txt");
	fout << endl;
	int i = 0;
	for(;i < own_word_list.size()-1;i++)
		fout << own_word_list[i] << " " << times[i] 
			 << " " << correct_times[i] << endl;
	fout << own_word_list[i] << " " << times[i] 
		 << " " << correct_times[i];
}
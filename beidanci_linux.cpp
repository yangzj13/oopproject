#include "beidanci.h"

void linux_pause(){
	system("read -n 1 -p \"Press any key to continue...\"");
}

Beidanci::Beidanci(): user(NULL), dict(Cet4::getInstance()),
					  now_dict(CET4), number(10), times(0),
					  uc(0), dc(0)
{
}

void linux_cls(){
	system("clear");
}

bool Beidanci::login(){
	linux_cls();
	this->printBlankLines(5);
	cout << "What's your name?" << endl;
	string user_name;
	cin >> user_name;
	user = new User(user_name);
	if(user != NULL)
		return true;
	else
		return false;
}

void Beidanci::run(){
	int order;
	bool valid = true;
	//system("title ������С����");
	
	//ѭ��ִ��
	while(1){
		linux_cls();
		this->printBlankLines(5);
		cout<<"*******************************������С����***********************************"<<endl;
		this->printBlankLines(5);
		cout<<"                                0.�ʵ��л�                                     "<<endl;
		cout<<"                                1.��ѯ����                                     "<<endl;
		//cout<<"                                2.�������                                     "<<endl;
		cout<<"                                3.�������                                     "<<endl;
		cout<<"                                4.ѧϰ����                                     "<<endl;
		cout<<"                                5.����ͳ��                                     "<<endl;
		cout<<"                                6.���ʲ���                                     "<<endl;
		cout<<"                                7.��ѯ��ʷ                                     "<<endl;
		cout<<"                                8.�����޸�                                     "<<endl;
		cout<<"                                9.�˳�ϵͳ                                     "<<endl;
		this->printBlankLines(2);
		//�ж��ϴ������Ƿ���Ч
		if(valid == true)
			cout<<"����������ѡ��";
		else cout<<"������Ч�����������룺";

		cin>>order;
		//�ж������Ƿ���Ч
		 if((order>-1) && (order<10))
			 valid=true;
		 //��Ч����Ҫ��������
		 else{
			 valid=false;
			 linux_cls();
			 continue;
		 }
		
		//�����û�����ѡ��ͬ����
		if(order == 0)
			this->switchDict();
		else if(order == 1)
			this->search();
		else if(order == 3)
			this->setPolicy();
		else if(order == 4)
			this->study();
		else if(order == 5)
			this->count();
		else if(order == 6)
			this->test();
		else if(order == 7)
			this->history();	
		else if(order == 8)
			this->save();
		else if(order == 9)
			this->exitB();
	}
}

void Beidanci::switchDict(){
	linux_cls();
	this->printBlankLines(3);
	cout << "��ǰ�ֵ�Ϊ";
	switch (now_dict){
		case CET4:
			cout << "CET4" << endl;
			break;
		case CET6:
			cout << "CET6" << endl;
			break;
		case GRE:
			cout << "GRE"  << endl;
			break;
	}
	this->printBlankLines(3);
	cout << "1.CET4 2.CET6 3.GRE" << endl;
	cout << "������Ҫ�л��Ĵʵ䣺";
	int op;
	cin >> op;
	if(op > 0&&op < 4){
		now_dict = op;
		if(now_dict == 1)
			dict = Cet4::getInstance();
		else if(now_dict == 2)
			dict = Cet6::getInstance();
		else if(now_dict == 3)
			dict = Gre::getInstance();
		this->printBlankLines(3);
		cout << "�л��ɹ�" << endl;
		linux_pause();
	}
	else{
		this->printBlankLines(3);
		cout << "�л�ʧ��" << endl;
		linux_pause();
	}
}

void Beidanci::setPolicy(){
	linux_cls();
	this->printBlankLines(3);
	cout << "ÿ�������䵥��������";
	while(1){
		cin >> number;
		if(number >= 1)
			break;
		else
			cout << "ӦΪ������";
	}
	this->printBlankLines(1);
	cout << "���ٳ��ִ�����";
	while(1){
		cin >> times;
		if(times >= 0)
			break;
		else
			cout << "ӦΪ�Ǹ�����";
	}
	this->printBlankLines(1);
	cout << "�����ȷ�ʣ�";
	while(1){
		cin >> uc;
		if(uc >= 0 && uc <= 1)
			break;
		else
			cout << "ӦΪ0~1��";
	}
	this->printBlankLines(1);
	cout << "�����ȷ�ʣ�";
	while(1){
		cin >> dc;
		if(dc >= 0 && dc <= uc)
			break;
		else
			cout << "ӦΪ0~1��";
	}
	linux_pause();
}

void Beidanci::study(){
	vector<string> studyWords = user->getSpecificWords(number, dict,
													   times, uc, dc);
	for(int i = 0;i < studyWords.size();i++){
		linux_cls();
		this->printBlankLines(3);
		cout << studyWords[i] << endl;
		cout << "Do you know it? 1.Yes 2.No" << endl;
		int op;
		while(1){
			cin >> op;
			if(op == 1){
				user->updateWordList(studyWords[i], true);
				break;
			}
			if(op == 2){
				user->updateWordList(studyWords[i], false);
				break;
			}
			cout << "��������(1��2)��";
		}
		this->printBlankLines(3);
		dict->searchWordEx(studyWords[i]);
		dict->searchWordSe(studyWords[i]);
		this->printBlankLines(3);
		cout << "1.���� 2.����:";
		while(1){
			cin >> op;
			if(op == 1){
				break;
			}
			if(op == 2){
				i = studyWords.size();
				cout << "����" << endl;
				break;
			}
			cout << "��������(1��2)��";
		}
	}
	if(studyWords.size() == 0){
		linux_cls();
		cout << "No mathched word!" << endl;
	}
	linux_pause();
}

void Beidanci::count(){
	linux_cls();
	this->printBlankLines(3);
	cout << "����������ͳ���ı������ƣ��뽫�ı������ڵ�ǰ�ļ����£���";
	string filename;
	cin >> filename;
	Counter counter(filename);
	counter.count(*dict);
	linux_pause();
}

void Beidanci::addSe(const string& _word){
	linux_cls();
	this->printBlankLines(3);
	cout << "�����������µ���Ϊ��" << _word << endl;
	Dict* nowDict = NULL;
	cout << "ѡ���������Ĵʿ⣺ 1.CET4 2.CET6 3.GRE" << endl;
	cout << "���п��õ��У�";
	if(Cet4::getInstance()->searchWord(_word)){
		cout << " CET4";
	}
	if(Cet6::getInstance()->searchWord(_word)){
		cout << " CET6";
	}
	if(Gre::getInstance()->searchWord(_word)){
		cout << " GRE";
	}
	cout << endl << "���ѡ��";
	while(1){
		int op = -1;
		cin >> op;
		if(op == 1 && Cet4::getInstance()->searchWord(_word)){
			nowDict = Cet4::getInstance();
			break;
		}
		else if(op == 2 && Cet6::getInstance()->searchWord(_word)){
			nowDict = Cet6::getInstance();
			break;
		}
		else if(op == 3 && Gre::getInstance()->searchWord(_word)){
			nowDict = Gre::getInstance();
			break;
		}
		cout << "����ѡ�����ѡ��";
	}
	this->printBlankLines(3);
	string s;
	cout << "��ӵ�����Ϊ�� ";
	cin.get(); 
	getline(cin, s);
	nowDict->addWordSenten(_word, s);
	cout << "��ӳɹ�!" << endl;
	linux_pause();
}

void Beidanci::search(){
	string word;
	linux_cls();
	this->printBlankLines(3);
	cout<<"������Ҫ���ҵĵ��ʣ�";
	cin >> word;
	user->updateHistory(word);
	//��������ͬ�ʿ��ж����е��ʲ�ѯ
	bool isExist = false;
	if(Cet4::getInstance()->searchWord(word)){
		cout << "CET4:" << endl;
		Cet4::getInstance()->searchWordEx(word);
		Cet4::getInstance()->searchWordSe(word);
		isExist = true;
	}
	if(Cet6::getInstance()->searchWord(word)){
		cout << "CET6:" << endl;
		Cet6::getInstance()->searchWordEx(word);
		Cet6::getInstance()->searchWordSe(word);
		isExist = true;
	}
	if(Gre::getInstance()->searchWord(word)){
		cout << "GRE:" << endl;
		Gre::getInstance()->searchWordEx(word);
		Gre::getInstance()->searchWordSe(word);
		isExist = true;
	}
	if(isExist == false)
		cout << "Can't find this word!" << endl;
	cout<<"�����������1�������������2(������)����������أ�";
	char c;
	cin >> c;
	if(c == '1')
		this->search();
	else if(c == '2' && isExist){
		this->addSe(word);		
		this->search(word);
	}
}

void Beidanci::search(const string& _word){
	linux_cls();
	this->printBlankLines(3);
	cout<<"������Ҫ���ҵĵ��ʣ�" << _word << endl;;
	//��������ͬ�ʿ��ж����е��ʲ�ѯ
	bool isExist = false;
	if(Cet4::getInstance()->searchWord(_word)){
		cout << "CET4:" << endl;
		Cet4::getInstance()->searchWordEx(_word);
		Cet4::getInstance()->searchWordSe(_word);
		isExist = true;
	}
	if(Cet6::getInstance()->searchWord(_word)){
		cout << "CET6:" << endl;
		Cet6::getInstance()->searchWordEx(_word);
		Cet6::getInstance()->searchWordSe(_word);
		isExist = true;
	}
	if(Gre::getInstance()->searchWord(_word)){
		cout << "Gre:" << endl;
		Gre::getInstance()->searchWordEx(_word);
		Gre::getInstance()->searchWordSe(_word);
		isExist = true;
	}
	if(isExist == false)
		cout << "Can't find this word!" << endl;
	cout<<"�����������1�������������2(������)����������أ�";
	char c;
	cin >> c;
	if(c == '1')
		this->search();
	else if(c == '2'){
		this->addSe(_word);		
		this->search(_word);
	}
}

void Beidanci::test(){
	linux_cls();
	this->printBlankLines(3);
	cout<<"********************************����˵��************************************"<<endl;
	this->printBlankLines(3);
	cout<<"  �����Թ���20�⣬ȫ��Ϊѡ���⣬ÿ��5�֡�ѡ������Ϊ��ȷ�Ĵ𰸲����룬�س�ȷ��֮�󼴿ɽ�����һ��"
		<<endl;
	cout<<"                                Good Luck!                                  "<<endl;
	this->printBlankLines(10);
	linux_pause();
	//system("cls");

	//��ŵ���
	vector<string> words;
	//��¼�÷�
	int score;
	//���ѡȡ20������
	for(int i=0;i<20;i++){
		srand(i);
		string r_word = dict->randomWord(rand());
		bool repeat=false;
		//���������ɵĵ����Ƿ��ظ�
		for(int j=0;j<i;j++){
			if(words[j] == r_word)
				repeat = true;
		}
		if(repeat == true)
			i--;
		else
			words.push_back(r_word);
	}

	score=0;
	//��ʼ����
	for(int i=0;i<20;i++){
		linux_cls();
		this->printBlankLines(1);
		vector<string> meaning;
		//������ɴ����
		for(int j=0;j<4;j++){
			srand(j);
			int seed = rand();
			srand(i);
			seed *= rand();
			string tmp = dict->randomWord(seed);
			bool repeat=false;
			//����Ƿ����ظ������
			for(int k=0;k<j;k++){
				if(meaning[k] == tmp)
					repeat=true;
			}
			if((repeat == true) || (tmp == words[i]))
				j--;
			else 
				meaning.push_back(tmp);
		}
		//������ȷ��
		int ans=rand()%4;
		meaning[ans]=words[i];
		cout<<"��"<<(i+1)<<"�⣺"<<endl<<endl;
		cout<<"����"<<words[i]<<"����˼�������Ǹ�ѡ����ϣ�"<<endl;
		this->printBlankLines(2);
		for(int j=0;j<4;j++){
			cout<<(char)(j+'A')<<"  ";
			dict->searchWordEx(meaning[j]);
		}
		this->printBlankLines(8);
		cout<<"��������Ĵ𰸣�";
		while(1){
			string yourAns;
			cin>>yourAns;
			//����Ĵ���Ч
			if( (yourAns.size()!=1) || 
				(yourAns!="A" && yourAns!="B" 
				&& yourAns!="C" && yourAns!="D")){
					cout<<"������Ч�����������룺";
					continue;
			}
			else{
				//����ȷ
				if(yourAns[0] == (ans+'A')){
					score+=5;
					user->updateWordList(words[i],true);
				}
				else
					user->updateWordList(words[i],false);
				break;
			}
		}//����whileѭ��
	}// ����forѭ��

	linux_cls();
	this->printBlankLines(3);
	if(score < 60){				
		cout<<"��ֻ����"<<score<<"��><, ����Ŭ����"<<endl;		
	}
	else if((score>=60) && (score<85)){
		cout<<"������"<<score<<"�֣� ���������࣬�����в��㣬���ͣ�"<<endl;
	}
	else if((score>=85) && (score<100)){
		cout<<"������"<<score<<"�֣� �ǳ����㣬���ͣ�"<<endl;
	}
	else if(score==100){
		cout<<"����������100��"<<endl;
	}
	cout<<endl<<"������������ȷ��:"<<endl;
	for(int i=0;i<20;i++){
		cout<<i+1<<": "<<words[i]<<" ";
		dict->searchWordEx(words[i]);
	}
	linux_pause();
	return;
}

void Beidanci::history(){
	linux_cls();
	this->printBlankLines(3);
	vector<string> h = user->getHistory();
	for(int i = 0;i < h.size();i++){
		cout << i+1 << ". " << h[i] << endl; 
	}
	this->printBlankLines(1);
	cout << "���ʵڼ������ʣ�����0���أ��� ";
	while(1){
		int yourChoice;
		cin>>yourChoice;
		if( yourChoice < 0 || 
			yourChoice > h.size() ){
				cout<<"������Ч�����������룺";
				continue;
		}
		else if(yourChoice != 0){
			this->search(h[yourChoice-1]);
			this->history();
			break;
		}
		else{
			break;
		}
	}
}

void Beidanci::exitB(){
	delete user;
	Cet4::saveInstance();
	Cet6::saveInstance();
	Gre::saveInstance();
	exit(0);	
}

void Beidanci::save(){
	linux_cls();
	this->printBlankLines(3);
	cout << "��ѡ��������Ĵʵ� �� 1.CET4 2.CET6 3.GRE 4.Back" << endl;
	cout << "���ѡ�� �� ";
	int c;
	while(1){
		cin >> c;
		if(c > 0 && c < 5)
			break;
		else
			cout << "���������룺 ";
	}
	if(c == 1)
		Cet4::saveInstance();
	else if(c == 2)
		Cet6::saveInstance();
	else if(c == 3)
		Gre::saveInstance();
	if(c > 0 && c < 4){
		if(now_dict == 1)
			dict = Cet4::getInstance();
		else if(now_dict == 2)
			dict = Cet6::getInstance();
		else if(now_dict == 3)
			dict = Gre::getInstance();
		this->printBlankLines(3);
		cout << "����ɹ���" << endl;
		linux_pause();
	}
}

//���Ƹ�ʽ�����һЩ����
void Beidanci::printBlankLines(int _n){
	//�������
	for(int i=0;i<_n;i++)
		cout<<endl;
	return;
}
#include "beidanci.h"

Beidanci::Beidanci() : now_dict(CET4), his()
{
	dict = Cet4::getInstance();
}

void Beidanci::run(){
	int order;
	bool valid = true;
	system("title ������С����");
	
	//ѭ��ִ��
	while(1){
		system("cls");
		this->printBlankLines(5);
		cout<<"********************************���ɱ�����************************************"<<endl;
		this->printBlankLines(5);
		cout<<"                                0.�ʵ��л�                                     "<<endl;
		cout<<"                                1.��ѯ����                                     "<<endl;
		cout<<"                                2.�������                                     "<<endl;
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
			 system("cls");
			 continue;
		 }
		
		//�����û�����ѡ��ͬ����
		if(order == 0)
			this->switchDict();
		else if(order == 1)
			this->search();		
		//else if(order == 2)
			//this->addSe();
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
	system("cls");
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
		system("pause");
	}
	else{
		this->printBlankLines(3);
		cout << "�л�ʧ��" << endl;
		system("pause");
	}
}

void Beidanci::setPolicy(){
	
}

void Beidanci::study(){
	
}

void Beidanci::count(){
	system("cls");
	this->printBlankLines(3);
	cout << "����������ͳ���ı������ƣ��뽫�ı������ڵ�ǰ�ļ����£���";
	string filename;
	cin >> filename;
	Counter counter(filename);
	counter.count(*dict);
	system("pause");
}

void Beidanci::addSe(string _word){
	system("cls");
	this->printBlankLines(3);
	cout << "�����������µ���Ϊ��" << _word << endl;
	dict->searchWordEx(_word);
	dict->searchWordSe(_word);
	this->printBlankLines(3);
	string s;
	cout << "��ӵ�����Ϊ�� ";
	cin.get(); 
	getline(cin, s);
	if(dict->addWordSenten(_word, s)){
		cout << "��ӳɹ�!" << endl;
	}
	else
		cout << "���ʧ��!" << endl;
	system("pause");
}

void Beidanci::search(){
	string word;
	system("cls");
	this->printBlankLines(3);
	cout<<"������Ҫ���ҵĵ��ʣ�";
	cin >> word;
	his.updateHistory(word);
	dict->searchWordEx(word);
	dict->searchWordSe(word);
	this->printBlankLines(3);
	cout<<"�����������1�������������2����������أ�";
	char c;
	cin >> c;
	if(c == '1')
		this->search();
	else if(c == '2'){
		this->addSe(word);		
		this->search(word);
	}
}

void Beidanci::search(string _word){
	system("cls");
	this->printBlankLines(3);
	cout<<"������Ҫ���ҵĵ��ʣ�" << _word << endl;;
	dict->searchWordEx(_word);
	dict->searchWordSe(_word);
	this->printBlankLines(3);
	cout<<"�����������1�������������2����������أ�";
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
	system("cls");
	this->printBlankLines(3);
	cout<<"********************************����˵��************************************"<<endl;
	this->printBlankLines(3);
	cout<<"  �����Թ���20�⣬ȫ��Ϊѡ���⣬ÿ��5�֡�ѡ������Ϊ��ȷ�Ĵ𰸲����룬�س�ȷ��֮�󼴿ɽ�����һ��"
		<<endl;
	cout<<"                                Good Luck!                                  "<<endl;
	this->printBlankLines(10);
	system("pause");
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
		system("cls");
		this->printBlankLines(1);
		vector<string> meaning;
		//������ɴ����
		for(int j=0;j<4;j++){
			srand(j);
			string tmp = dict->randomWord(rand());
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
				if(yourAns[0] == (ans+'A'))
					score+=5;
				break;
			}
		}//����whileѭ��
	}// ����forѭ��

	system("cls");
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
		cout<<"����������100�� Ĥ����ţ��"<<endl;
	}
	cout<<endl<<"������������ȷ��:"<<endl;
	for(int i=0;i<20;i++){
		cout<<i+1<<": "<<words[i]<<" ";
		dict->searchWordEx(words[i]);
	}
	system("pause");
	return;
}

void Beidanci::history(){
	system("cls");
	this->printBlankLines(3);
	vector<string> h = his.getHistory();
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
	his.~History();
	exit(0);	
}

void Beidanci::save(){
	system("cls");
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
		system("pause");
	}
}

//���Ƹ�ʽ�����һЩ����
void Beidanci::printBlankLines(int _n){
	//�������
	for(int i=0;i<_n;i++)
		cout<<endl;
	return;
}
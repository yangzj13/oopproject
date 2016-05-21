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
	//system("title 背单词小能手");
	
	//循环执行
	while(1){
		linux_cls();
		this->printBlankLines(5);
		cout<<"*******************************背单词小能手***********************************"<<endl;
		this->printBlankLines(5);
		cout<<"                                0.词典切换                                     "<<endl;
		cout<<"                                1.查询单词                                     "<<endl;
		//cout<<"                                2.添加例句                                     "<<endl;
		cout<<"                                3.记忆策略                                     "<<endl;
		cout<<"                                4.学习单词                                     "<<endl;
		cout<<"                                5.生词统计                                     "<<endl;
		cout<<"                                6.单词测试                                     "<<endl;
		cout<<"                                7.查询历史                                     "<<endl;
		cout<<"                                8.保存修改                                     "<<endl;
		cout<<"                                9.退出系统                                     "<<endl;
		this->printBlankLines(2);
		//判断上次输入是否有效
		if(valid == true)
			cout<<"请输入您的选择：";
		else cout<<"输入无效，请重新输入：";

		cin>>order;
		//判断输入是否有效
		 if((order>-1) && (order<10))
			 valid=true;
		 //无效则需要重新输入
		 else{
			 valid=false;
			 linux_cls();
			 continue;
		 }
		
		//根据用户输入选择不同功能
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
	cout << "当前字典为";
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
	cout << "请输入要切换的词典：";
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
		cout << "切换成功" << endl;
		linux_pause();
	}
	else{
		this->printBlankLines(3);
		cout << "切换失败" << endl;
		linux_pause();
	}
}

void Beidanci::setPolicy(){
	linux_cls();
	this->printBlankLines(3);
	cout << "每次最多记忆单词数量：";
	while(1){
		cin >> number;
		if(number >= 1)
			break;
		else
			cout << "应为正数：";
	}
	this->printBlankLines(1);
	cout << "至少出现次数：";
	while(1){
		cin >> times;
		if(times >= 0)
			break;
		else
			cout << "应为非负数：";
	}
	this->printBlankLines(1);
	cout << "最高正确率：";
	while(1){
		cin >> uc;
		if(uc >= 0 && uc <= 1)
			break;
		else
			cout << "应为0~1：";
	}
	this->printBlankLines(1);
	cout << "最低正确率：";
	while(1){
		cin >> dc;
		if(dc >= 0 && dc <= uc)
			break;
		else
			cout << "应为0~1：";
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
			cout << "重新输入(1或2)：";
		}
		this->printBlankLines(3);
		dict->searchWordEx(studyWords[i]);
		dict->searchWordSe(studyWords[i]);
		this->printBlankLines(3);
		cout << "1.继续 2.返回:";
		while(1){
			cin >> op;
			if(op == 1){
				break;
			}
			if(op == 2){
				i = studyWords.size();
				cout << "返回" << endl;
				break;
			}
			cout << "重新输入(1或2)：";
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
	cout << "请输入生词统计文本的名称（请将文本放置于当前文件夹下）：";
	string filename;
	cin >> filename;
	Counter counter(filename);
	counter.count(*dict);
	linux_pause();
}

void Beidanci::addSe(const string& _word){
	linux_cls();
	this->printBlankLines(3);
	cout << "待添加例句的新单词为：" << _word << endl;
	Dict* nowDict = NULL;
	cout << "选择添加例句的词库： 1.CET4 2.CET6 3.GRE" << endl;
	cout << "其中可用的有：";
	if(Cet4::getInstance()->searchWord(_word)){
		cout << " CET4";
	}
	if(Cet6::getInstance()->searchWord(_word)){
		cout << " CET6";
	}
	if(Gre::getInstance()->searchWord(_word)){
		cout << " GRE";
	}
	cout << endl << "你的选择：";
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
		cout << "重新选择，你的选择：";
	}
	this->printBlankLines(3);
	string s;
	cout << "添加的例句为： ";
	cin.get(); 
	getline(cin, s);
	nowDict->addWordSenten(_word, s);
	cout << "添加成功!" << endl;
	linux_pause();
}

void Beidanci::search(){
	string word;
	linux_cls();
	this->printBlankLines(3);
	cout<<"请输入要查找的单词：";
	cin >> word;
	user->updateHistory(word);
	//在三个不同词库中都进行单词查询
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
	cout<<"继续查词输入1，添加例句输入2(若存在)，其余键返回：";
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
	cout<<"请输入要查找的单词：" << _word << endl;;
	//在三个不同词库中都进行单词查询
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
	cout<<"继续查词输入1，添加例句输入2(若存在)，其余键返回：";
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
	cout<<"********************************考试说明************************************"<<endl;
	this->printBlankLines(3);
	cout<<"  本考试共有20题，全部为选择题，每题5分。选择你认为正确的答案并输入，回车确认之后即可进入下一题"
		<<endl;
	cout<<"                                Good Luck!                                  "<<endl;
	this->printBlankLines(10);
	linux_pause();
	//system("cls");

	//存放单词
	vector<string> words;
	//记录得分
	int score;
	//随机选取20个单词
	for(int i=0;i<20;i++){
		srand(i);
		string r_word = dict->randomWord(rand());
		bool repeat=false;
		//检查随机生成的单词是否重复
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
	//开始考试
	for(int i=0;i<20;i++){
		linux_cls();
		this->printBlankLines(1);
		vector<string> meaning;
		//随机生成错误答案
		for(int j=0;j<4;j++){
			srand(j);
			int seed = rand();
			srand(i);
			seed *= rand();
			string tmp = dict->randomWord(seed);
			bool repeat=false;
			//检查是否有重复的情况
			for(int k=0;k<j;k++){
				if(meaning[k] == tmp)
					repeat=true;
			}
			if((repeat == true) || (tmp == words[i]))
				j--;
			else 
				meaning.push_back(tmp);
		}
		//生成正确答案
		int ans=rand()%4;
		meaning[ans]=words[i];
		cout<<"第"<<(i+1)<<"题："<<endl<<endl;
		cout<<"单词"<<words[i]<<"的意思与下列那个选项符合？"<<endl;
		this->printBlankLines(2);
		for(int j=0;j<4;j++){
			cout<<(char)(j+'A')<<"  ";
			dict->searchWordEx(meaning[j]);
		}
		this->printBlankLines(8);
		cout<<"请输入你的答案：";
		while(1){
			string yourAns;
			cin>>yourAns;
			//输入的答案无效
			if( (yourAns.size()!=1) || 
				(yourAns!="A" && yourAns!="B" 
				&& yourAns!="C" && yourAns!="D")){
					cout<<"输入无效，请重新输入：";
					continue;
			}
			else{
				//答案正确
				if(yourAns[0] == (ans+'A')){
					score+=5;
					user->updateWordList(words[i],true);
				}
				else
					user->updateWordList(words[i],false);
				break;
			}
		}//结束while循环
	}// 结束for循环

	linux_cls();
	this->printBlankLines(3);
	if(score < 60){				
		cout<<"您只得了"<<score<<"分><, 尚需努力！"<<endl;		
	}
	else if((score>=60) && (score<85)){
		cout<<"您得了"<<score<<"分， 及格颇有余，优秀尚不足，加油！"<<endl;
	}
	else if((score>=85) && (score<100)){
		cout<<"您得了"<<score<<"分， 非常优秀，加油！"<<endl;
	}
	else if(score==100){
		cout<<"您得了满分100！"<<endl;
	}
	cout<<endl<<"下面是所有正确答案:"<<endl;
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
	cout << "访问第几个单词（输入0返回）： ";
	while(1){
		int yourChoice;
		cin>>yourChoice;
		if( yourChoice < 0 || 
			yourChoice > h.size() ){
				cout<<"输入无效，请重新输入：";
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
	cout << "请选择所保存的词典 ： 1.CET4 2.CET6 3.GRE 4.Back" << endl;
	cout << "你的选择 ： ";
	int c;
	while(1){
		cin >> c;
		if(c > 0 && c < 5)
			break;
		else
			cout << "请重新输入： ";
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
		cout << "保存成功！" << endl;
		linux_pause();
	}
}

//控制格式，输出一些空行
void Beidanci::printBlankLines(int _n){
	//输出空行
	for(int i=0;i<_n;i++)
		cout<<endl;
	return;
}
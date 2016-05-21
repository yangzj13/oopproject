#ifndef __COMMAND_H__
#define __COMMAND_H__

#include <iostream>
using namespace std;

class Command{
public:
	virtual void cleanScreen() = 0;
	virtual void pause() = 0;
	virtual ~Command(){}
};

class WindowsCommand : public Command
{
public:
	void cleanScreen(){
		system("cls");
	}
	void pause(){
		system("pause");
	}
	~WindowsCommand(){}
};

class LinuxCommand : public Command
{
public:
	void cleanScreen(){
		system("clear");
	}
	void pause(){
		getchar();
		cout << "»Ø³µ¼ÌÐø..." << endl;
		getchar();
	}
	~LinuxCommand(){}
};

#endif
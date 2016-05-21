#include "beidanci.h"

using namespace std;

int main()
{
	Beidanci b(new LinuxCommand);
	while(b.login() ){
		b.run();
	}
	return 0;
}
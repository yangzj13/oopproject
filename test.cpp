#include <iostream>
#include "word.h"
//test
using namespace std;

int main()
{
    Word * word = new Word("me", "I", 1);
    cout << word->getName() << endl;
    cout << word->getExplain() << endl;
    cout << word->getLevel() << endl;
}

#include <iostream>
#include "word.h"

using namespace std;

int main()
{
    Word * word = new Word("me", "我", 1);
	word->addSentence("Please look at me.");
	word->addSentence("Do you want to talk with me?");
    cout << word->getName() << endl;
    cout << word->getExplain() << endl;
    cout << word->getLevel() << endl;
	for(int i = 0;i < word->getSentencesSize();i++){
		cout << word->getSentences(i) << endl;
	}
	return 0;
}
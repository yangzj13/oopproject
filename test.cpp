#include "dict.h"

using namespace std;

int main()
{
	/* string meaning;
	cin >> meaning;
    Word * word = new Word("me", meaning, 1);
	word->addSentence("Please look at me.");
	word->addSentence("Do you want to talk with me?");
    cout << word->getName() << endl;
    cout << word->getExplain() << endl;
    cout << word->getLevel() << endl;
	for(int i = 0;i < word->getSentencesSize();i++){
		cout << word->getSentences(i) << endl;
	} */
	
	Dict dictionary;
	string name;
	cin >> name;
	dictionary.searchWord(name);
	
	return 0;
}
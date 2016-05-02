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
	
	//Dict dictionary("data/cet6.txt");
	Dict dictionary;
	string name, s1, s2;
	name = dictionary.randomWord();
	//cin >> s1 >> s2;
	cout << name << endl;
	dictionary.searchWordEx(name);
	//dictionary.addWordSenten(name, s1);
	//dictionary.searchWordSe(name);
	//dictionary.addWordSenten(name, s2);
	//dictionary.searchWordSe(name);
	//cout << dictionary.searchWordLevel(name) << endl;
	
	return 0;
}
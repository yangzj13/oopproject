#ifndef __WORD_H__
#define __WORD_H__

#include <string>
#include <vector>

#define _NOT_KNOW_ 0
#define _KNOW_ 1

using namespace std;

class Word
{
    string name;
    string explain;
    int level;
	vector<string> sentences;
public:
    Word(string _name, string _ex, int _l = 0):name(_name),
                                               explain(_ex),
                                               level(_l){};
    Word(const Word &_src):name(_src.name),
						   explain(_src.explain),
						   level(_src.level)
	{
		for(int i = 0;i < _src.getSentencesSize();i++){
			addSentence(_src.getSentences(i));
		}
	}
	~Word(){}
    string getName() const
    {
        return name;
    }
    string getExplain() const
    {
        return explain;
    }
    int getLevel() const
    {
        return level;
    }
	void setLevel(int _l)
	{
		level = _l;
	}
	void addSentence(string _sentence)
	{
		sentences.push_back(_sentence);
	}
	int getSentencesSize() const
	{
		return sentences.size();
	}
	string getSentences(int _pos) const
	{
		return sentences[_pos];
	}
};

#endif //__WORD_H__

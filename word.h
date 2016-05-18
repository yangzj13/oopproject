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
    Word(const string& _name, const string& _ex, int _l = 0):name(_name),
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
    const string getName() const
    {
        return name;
    }
    const string getExplain() const
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
	void addSentence(const string& _sentence)
	{
		sentences.push_back(_sentence);
	}
	int getSentencesSize() const
	{
		return sentences.size();
	}
	const string getSentences(int _pos) const
	{
		return sentences[_pos];
	}
};

#endif //__WORD_H__

#include "strategy.h"
//�´�
bool newStrategy::judge(const string& _word, int _times, int _correct)
{
	if(_times == 0)
		return true;
	return false;
}
//���
bool familiarStrategy::judge(const string& _word, int _times, int _correct)
{
	if(_times >= 5 && _correct >= 0.8 * _times)
		return true;
	return false;
}
//�Ѵ�
bool hardStrategy::judge(const string& _word, int _times, int _correct)
{
	if(_times >= 5 && _correct <= 0.6 * _times)
		return true;
	if(_times < 5 && _word.size() >= 8)
		return true;
	return false;
}
//ѧϰ�еĴ�
bool unfamiliarStrategy::judge(const string& _word, int _times, int _correct)
{
	if(_times < 5 || _correct <= 0.8 * _times)
		return true;
	return false;
}
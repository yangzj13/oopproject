#include "strategy.h"
//新词
bool newStrategy::judge(const string& _word, int _times, int _correct)
{
	if(_times == 0)
		return true;
	return false;
}
//熟词
bool familiarStrategy::judge(const string& _word, int _times, int _correct)
{
	if(_times >= 5 && _correct >= 0.8 * _times)
		return true;
	return false;
}
//难词
bool hardStrategy::judge(const string& _word, int _times, int _correct)
{
	if(_times >= 5 && _correct <= 0.6 * _times)
		return true;
	if(_times < 5 && _word.size() >= 8)
		return true;
	return false;
}
//学习中的词
bool unfamiliarStrategy::judge(const string& _word, int _times, int _correct)
{
	if(_times < 5 || _correct <= 0.8 * _times)
		return true;
	return false;
}
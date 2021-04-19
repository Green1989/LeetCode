// word-break.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <conio.h>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
//using namespace std;

bool wordBreak(std::string s, std::vector<std::string>& wordDict)  {
	std::tr1::unordered_set<std::string> wordSet(wordDict.begin(), wordDict.end());
	std::vector<bool> vecDP(s.size()+1, false);
	vecDP[0] = 1;
	for (int i=1;i<=s.size();i++)
	{
		for (int j=0;j<i;j++)
		{
			std::string word = s.substr(j, i-j);
			if (wordSet.find(word) != wordSet.end() && vecDP[j])
			{
				vecDP[i] = true;
			}
		}
	}
// 	for (int i=0;i<=s.size();i++)
// 	{
// 		std::cout<< "vecDP[" << i << "]=" << vecDP[i] << std::endl;
// 	}
	return vecDP[s.size()];
}

int _tmain(int argc, _TCHAR* argv[])
{
	std::string s = "leetcode";
	std::string strTemp[] = {"leet", "code"};
	std::vector <std::string> wordDict(strTemp, strTemp+2);
	bool bRet = wordBreak(s, wordDict);
	for (int i=0;i<wordDict.size();i++)
	{
		std::cout << wordDict[i] << ",";
	}
	std::cout << std::endl << s << "=" <<bRet << std::endl << std::endl;

	std::string s1 = "applepenapple";
	std::string strTemp1[] = {"apple", "pen"};
	std::vector <std::string> wordDict1(strTemp1, strTemp1+2);
	bRet = wordBreak(s1, wordDict1);
	for (int i=0;i<wordDict1.size();i++)
	{
		std::cout << wordDict1[i] << ",";
	}
	std::cout << std::endl << s1 << "=" << bRet << std::endl << std::endl;

	std::string s2 = "catsandog";
	std::string strTemp2[] = {"cats", "dog", "sand", "and", "cat"};
	std::vector <std::string> wordDict2(strTemp2, strTemp2+5);
	bRet = wordBreak(s2, wordDict2);
	for (int i=0;i<wordDict2.size();i++)
	{
		std::cout << wordDict2[i] << ",";
	}
	std::cout << std::endl << s2 << "=" << bRet << std::endl << std::endl;

	_getch();
	return 0;
}

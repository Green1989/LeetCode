// ones-and-zeroes.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int findMaxForm(vector<string>& strs, int m, int n) {

	vector <vector <int>> vecDP(m + 1, vector <int>(n+1, 0));
	string str;
	for (vector<string>::const_iterator iter = strs.begin();iter != strs.end(); iter++)
	{
		str = (*iter);
		int nOneNums = 0;
		int nZeroNums = 0;
		for (int i = 0; i < str.length(); i++) 
		{
			if (str[i] == '1')
			{
				nOneNums++;
			}
			else
			{
				nZeroNums++;
			}
		}
		for (int i = m; i >= nZeroNums; i--)
		{
			for (int j = n; j>= nOneNums; j--)
			{
				vecDP[i][j] = max(vecDP[i][j], vecDP[i-nZeroNums][j-nOneNums]+1);
			}
		}
	}
	return vecDP[m][n];
}

int _tmain(int argc, _TCHAR* argv[])
{
	string strsTemp[] = {"10", "0001", "111001", "1", "0"};
	vector <string> strs(strsTemp, strsTemp+5);
	int nRet = findMaxForm(strs, 3, 3);
	cout << endl << nRet << endl;
	_getch();
	return 0;
}


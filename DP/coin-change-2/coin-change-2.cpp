// coin-change-2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int change(int amount, vector<int>& coins)  {
	vector <int> vecDP(amount+1, 0);
	vecDP[0] = 1;
	for (int i = 0; i < coins.size(); i++)
	{
		for(int j = coins[i]; j <= amount; j++)
		{
			vecDP[j] += vecDP[j-coins[i]];
		}
	}
	return vecDP[amount];
}

int _tmain(int argc, _TCHAR* argv[])
{
	int nTemp[] = {1, 2, 5};
	vector <int> coins(nTemp, nTemp+3);
	int nRet = change(5,coins);
	cout << endl << nRet << endl;
	_getch();
	return 0;
}
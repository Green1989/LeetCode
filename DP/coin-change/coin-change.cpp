// coin-change.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int change(vector<int>& coins, int amount)  {
	vector <int> vecDP(amount+1, INT_MAX);
	vecDP[0] = 0;
	for (int i = 0; i < coins.size(); i++)
	{
		for(int j = coins[i]; j <= amount; j++)
		{
			if (vecDP[j - coins[i]] != INT_MAX)
			{
				vecDP[j] = min(vecDP[j - coins[i]] + 1, vecDP[j]);
			}
		}
	}
	if (vecDP[amount] == INT_MAX)
	{
		return -1;
	}
	else
	{
		return vecDP[amount];
	}

}

int _tmain(int argc, _TCHAR* argv[])
{
	int nTemp[] = {1, 2, 5};
	vector <int> coins(nTemp, nTemp+3);
	int nRet = change(coins, 11);
	cout << endl << nRet << endl;
	_getch();
	return 0;
}
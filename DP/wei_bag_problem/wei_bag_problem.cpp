// wei_bag_problem.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<conio.h>
#include <iostream>
#include <vector>
using namespace std;
int wei_bag_problem(vector<int> weight, vector<int> value, int bagWeight)//二维数组保存01背包全过程
{
	vector <vector <int>> vecDP(weight.size(), vector <int>(bagWeight+1, 0));
	for (int j=bagWeight;j>=weight[0];j--)
	{
		vecDP[0][j] = vecDP[0][j-weight[0]] + value[0];
	}
	for (int i=1;i<weight.size();i++)
	{
		for (int j=0;j<=bagWeight;j++)
		{
			if (j<weight[i])
			{
				vecDP[i][j] = vecDP[i-1][j];
			}
			else
			{
				vecDP[i][j] = max(vecDP[i-1][j], vecDP[i-1][j-weight[i]]+value[i]);
			}
		}
	}

	for (int i=0;i<weight.size();i++)
	{
		for (int j=0;j<=bagWeight;j++)
		{
			cout << vecDP[i][j] << "  ";
		}
		cout << endl;
	}
	return vecDP[weight.size()-1][bagWeight];
}

int unidimensionalWei_bag_problem(vector<int> weight, vector<int> value, int bagWeight)//一维数组写法，简洁
{
	vector <int> vecDP(bagWeight+1, 0);
	for (int i=0;i<weight.size();i++)
	{
		for (int j=bagWeight;j>=weight[i];j--)
		{
			vecDP[j] = max(vecDP[j], vecDP[j-weight[i]] + value[i]);
		}
	}
	return vecDP[bagWeight];
}
int _tmain(int argc, _TCHAR* argv[])
{
	int weightTemp[] = {1, 3, 4};
	int valueTemp[] = {15, 20, 30};
	vector <int> weight(weightTemp, weightTemp+3);
	vector <int> value(valueTemp, valueTemp+3);
	int bagWeight = 4;
	int nRet = wei_bag_problem(weight, value, bagWeight);
	cout << endl << nRet << endl;
	nRet = unidimensionalWei_bag_problem(weight, value, bagWeight);
	cout << endl << nRet << endl;
	_getch();
	return 0;
}


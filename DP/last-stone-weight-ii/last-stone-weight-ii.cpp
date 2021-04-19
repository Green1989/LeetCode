// last-stone-weight-ii.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

bool lastStoneWeightII(vector<int>& stones) {
	int nSum = accumulate(stones.begin(), stones.end(), 0);
	int nBagWeight = nSum/2;
	vector <int> vecDP(nBagWeight+1, 0);
	for(int i = 0; i < stones.size(); i++)
	{
		for (int j = nBagWeight; j >= stones[i]; j--)
		{
			vecDP[j] = max(vecDP[j], vecDP[j-stones[i]] + stones[i]);
		}			
	}
	return  nSum - vecDP[nBagWeight] - vecDP[nBagWeight];
}

int _tmain(int argc, _TCHAR* argv[])
{
	int numsTemp[] = {2,7,4,1,8,1};
	vector <int> nums(numsTemp, numsTemp+6);
	int nRet = lastStoneWeightII(nums);
	cout << endl << nRet << endl;
	_getch();
	return 0;
}


// target-sum.cpp : 定义控制台应用程序的入口点。
//
// last-stone-weight-ii.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int findTargetSumWays(vector<int>& nums, int S) {
	int nSum = accumulate(nums.begin(), nums.end(), 0);
	if (nSum - S < 0 || (nSum - S) % 2 != 0)
	{
		return 0;
	}	
	int nBagWeight = (nSum - S)/2;
	vector <int> vecDP(nBagWeight+1, 0);
	vecDP[0] = 1;
	for(int i = 0; i < nums.size(); i++)
	{
		for (int j = nBagWeight; j >= nums[i]; j--)
		{
			vecDP[j] += vecDP[j - nums[i]];
		}
	}
	return  vecDP[nBagWeight];
}

int _tmain(int argc, _TCHAR* argv[])
{
	int numsTemp[] = {1, 1, 1, 1, 1};
	vector <int> nums(numsTemp, numsTemp+5);
	int nRet = findTargetSumWays(nums, 3);
	cout << endl << nRet << endl;
	_getch();
	return 0;
}


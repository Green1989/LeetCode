// partition-equal-subset-sum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

bool canPartition(vector<int>& nums) {
	int nSum = accumulate(nums.begin(), nums.end(), 0);
	if (nSum % 2 == 1)
	{
		return false;
	}
	int nBagWeight = nSum/2;
	vector <int> vecDP(nBagWeight+1, 0);
	for(int i = 0; i < nums.size(); i++)
	{
		for (int j = nBagWeight; j >= nums[i]; j--)
		{
			vecDP[j] = max(vecDP[j], vecDP[j-nums[i]] + nums[i]);
		}			
	}
	return  vecDP[nBagWeight] == nBagWeight;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int numsTemp[] = {1, 5, 11, 5};
	vector <int> nums(numsTemp, numsTemp+4);
	bool bRet = canPartition(nums);
	cout << endl << bRet << endl;
	_getch();
	return 0;
}


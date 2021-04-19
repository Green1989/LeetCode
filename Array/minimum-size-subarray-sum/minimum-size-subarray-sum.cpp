// minimum-size-subarray-sum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
int sumArray(int nStart, int nEnd, vector<int>& nums)
{
	int nSum = 0;
	for (int i=nStart; i<=nEnd; i++)
	{
		nSum += nums[i];
	}
	return nSum;
}
int minSubArrayLen(int target, vector<int>& nums) {
	int nSlow = 0, nFast = 0;
	int nResult = INT_MAX;
	int nSize = nums.size();
	while (nFast < nSize)
	{
		if (sumArray(nSlow, nFast, nums) >= target)
		{
			nResult = nResult < (nFast - nSlow + 1) ? nResult:(nFast - nSlow + 1);
			nSlow++;
		}
		else
		{
			nFast++;
		}
	}
	return nResult == INT_MAX ? 0:nResult;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int nTemp[] = {2,7,9,3,1};
	vector <int> nums(nTemp, nTemp+5);
	int target = 11;
	int nRet = minSubArrayLen(target, nums);
	cout << endl << nRet << endl;

	_getch();
	return 0;
}

// house-robber-ii.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
int robRange(vector<int>& nums, int nStart, int nEnd);
int rob(vector<int>& nums)  {
	int amount = nums.size();
	if (amount == 0)
	{
		return 0;
	}
	else if (amount == 1)
	{
		return nums[0];
	}
	int nResult1 = robRange(nums, 0, nums.size()-2);
	int nResult2 = robRange(nums, 1, nums.size()-1);
	return max(nResult1, nResult2);
}

int robRange(vector<int>& nums, int nStart, int nEnd)
{
	if (nStart == nEnd)
	{
		return nums[nStart];
	}
	vector <int> vecDP(nums.size(), 0);
	vecDP[nStart] = nums[nStart];
	vecDP[nStart+1] = max(nums[nStart], nums[nStart+1]);
	for (int i=nStart+2;i<=nEnd;i++)
	{
		vecDP[i] = max(vecDP[i-1], vecDP[i-2]+nums[i]);
	}
	return vecDP[nEnd];
}

int _tmain(int argc, _TCHAR* argv[])
{
	int nTemp[] = {2,7,9,3,1};
	vector <int> nums(nTemp, nTemp+5);
	int nRet = rob(nums);
	cout << endl << nRet << endl;

	int nTemp1[] = {1,2,3,1};
	vector <int> nums1(nTemp1, nTemp1+4);
	int nRet1 = rob(nums1);
	cout << endl << nRet1 << endl;

	int nTemp2[] = {2,3,2};
	vector <int> nums2(nTemp2, nTemp2+3);
	int nRet2 = rob(nums2);
	cout << endl << nRet2 << endl;
	_getch();
	return 0;
}
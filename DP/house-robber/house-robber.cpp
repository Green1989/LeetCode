// house-robber.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

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
	vector <int> vecDP(amount+1, 0);
	vecDP[0] = nums[0];
	vecDP[1] = max(nums[0], nums[1]);
	for (int i=2;i<amount;i++)
	{
		vecDP[i] = max(vecDP[i-1], vecDP[i-2]+nums[i]);
	}
	return vecDP[amount-1];
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
	_getch();
	return 0;
}
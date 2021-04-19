// perfect-squares.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int numSquares(int n)  {
	vector <int> vecDP(n+1, INT_MAX);
	vecDP[0] = 0;
	for (int i=0;i<=n;i++)
	{
		for (int j=1;j*j<=i;j++)
		{
			if (vecDP[i-j*j] != INT_MAX)
			{
				vecDP[i] = min(vecDP[i-j*j]+1, vecDP[i]);
			}
		}
	}
	return vecDP[n];
}

int _tmain(int argc, _TCHAR* argv[])
{
	int nRet = numSquares(3);
	cout << endl << nRet << endl;
	nRet = numSquares(12);
	cout << endl << nRet << endl;
	nRet = numSquares(13);
	cout << endl << nRet << endl;
	_getch();
	return 0;
}
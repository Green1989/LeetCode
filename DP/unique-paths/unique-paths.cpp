// unique-paths.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<conio.h>
#include <iostream>
#include <iomanip>
using namespace std;
int uniquePaths(int m, int n) {

	//int nPathsSum[m][n];
	int **nPathsSum = NULL;
	nPathsSum = new int*[m];
	for (int i=0;i<m;i++)
	{
		nPathsSum[i] = new int[n];
	}
	for (int i=0;i<m;i++)
	{
		nPathsSum[i][0] = 1;
	}
	for (int j=0;j<n;j++)
	{
		nPathsSum[0][j] = 1;
	}
	for (int i=1;i<m;i++)
	{
		for (int j=1;j<n;j++)
		{
			nPathsSum[i][j] = nPathsSum[i-1][j] + nPathsSum[i][j-1];
		}
	}
	return nPathsSum[m-1][n-1];
}
int _tmain(int argc, _TCHAR* argv[])
{
	int nRet = uniquePaths(3, 7);
	cout << nRet << endl;
	_getch();
	return 0;
}


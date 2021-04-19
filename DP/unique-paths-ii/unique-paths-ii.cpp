// unique-paths-ii.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<conio.h>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();
	int **nPathsSum = NULL;
	nPathsSum = new int*[m];
	memset(nPathsSum,0,sizeof(nPathsSum));
	for (int i=0;i<m;i++)
	{
		nPathsSum[i] = new int[n];
	}
	bool bTemp = false;
	for (int i=0;i<m;i++)
	{
		if (bTemp)
		{
			nPathsSum[i][0] = 0;
			continue;
		}
		if (obstacleGrid[i][0] == 0)
		{
			nPathsSum[i][0] = 1;
		}
		else
		{
			bTemp = true;
			nPathsSum[i][0] = 0;			
		}
	}
	bTemp = false;
	for (int j=0;j<n;j++)
	{
		if (bTemp)
		{
			nPathsSum[0][j] = 0;
			continue;
		}
		if (obstacleGrid[0][j] == 0)
		{
			nPathsSum[0][j] = 1;
		}	
		else
		{
			bTemp = true;
			nPathsSum[0][j] = 0;
		}
	}
	for (int i=1;i<m;i++)
	{
		for (int j=1;j<n;j++)
		{
			if (obstacleGrid[i][j] == 0)
			{
				nPathsSum[i][j] = nPathsSum[i-1][j] + nPathsSum[i][j-1];
			}
			else
			{
				nPathsSum[i][j] = 0;
			}
		}
	}

	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++)
		{
			cout << setw(16) << setfill(' ') << left << nPathsSum[i][j];
		}
		cout << endl;
	}
	return nPathsSum[m-1][n-1];
}
int _tmain(int argc, _TCHAR* argv[])
{
	vector<vector<int>> obstacleGrid;

	int m = 1;
	int n = 2;

	vector<int> v;

	obstacleGrid.clear();
	for (int i = 0; i<m; i++) 
	{
		v.clear();
		for (int j = 0; j < n; j++)
		{
			if (i == 0 && j == 0)
			{
				v.push_back(1);
			}
			else
			{
				v.push_back(0);
			}
		}
		obstacleGrid.push_back(v);
	}

	int nRet = uniquePathsWithObstacles(obstacleGrid);
	cout << endl << nRet << endl;
	_getch();
	return 0;
}


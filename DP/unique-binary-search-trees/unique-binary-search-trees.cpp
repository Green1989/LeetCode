// unique-binary-search-trees.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<conio.h>
#include <vector>
using namespace std;
int numTrees(int n) {
	vector <int> vecNumTrees(n+1);
	vecNumTrees[0] = 1;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<i;j++)
		{
			vecNumTrees[i] += (vecNumTrees[i-j-1]*vecNumTrees[j]);
		}
	}	
	return vecNumTrees[n];
}
int _tmain(int argc, _TCHAR* argv[])
{
	int n = 5;
	for (int i=1;i<=n;i++)
	{
		printf("i=%d,NumTrees = %d\n", i, numTrees(i));		
	}
	_getch();
	return 0;
}


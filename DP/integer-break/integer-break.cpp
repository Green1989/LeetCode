// unique-paths-ii.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<conio.h>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
int integerBreak(int n) {

	vector <int> integerPark(n+1);
	integerPark[2] = 1;
	int temp1,temp2, temp3;
	for (int i=3;i<=n;i++)
	{
		for (int j=1;j<i;j++)
		{
			integerPark[i] = max(integerPark[i], max((i-j)*j, (i-j)*integerPark[j]));
		}
	}
	return integerPark[n];
}

#ifdef DEBUG
int integerBreak(int n) {

	vector <int> integerPark(n+1);
	integerPark[2] = 1;
	int temp1,temp2, temp3;
	for (int i=3;i<=n;i++)
	{
		for (int j=1;j<i;j++)
		{
			temp3 = 0;
			temp1 = (i-j)*j;
			temp2 = (i-j)*integerPark[j];
			if (temp1 < temp2)
			{
				temp3 = temp2;
			}
			else
			{
				temp3 = temp1;
			}
			if (integerPark[i] < temp3)
			{
				integerPark[i] = temp3;
				if (temp3 == temp1)
				{
					printf("(i=%d,j=%d)(拆)integerPark[%d]=(%d-%d)*%d=%d\n", i, j, i, i, j, j, integerPark[i]);
					//cout << "integerPark[" << i <<"]=" << "("
				}
				else
				{
					printf("(i=%d,j=%d)(拆拆)integerPark[%d]=(%d-%d)*integerPark[%d]=%d\n", i, j, i, i, j, j, integerPark[i]);
				}
			}
			else
			{
				printf("(i=%d,j=%d)(不拆)integerPark[%d]=integerPark[%d]=%d\n", i, j, i, i, integerPark[i]);
			}
			//integerPark[i] = max(integerPark[i], max((i-j)*j, (i-j)*integerPark[j]));
		}
	}
	for (int i=2;i<n;i++)
	{
		printf("integerPark[%d]=%d\n", i, integerPark[i]);
	}
	return integerPark[n];
}
#endif
int _tmain(int argc, _TCHAR* argv[])
{
	
	int nRet = integerBreak(10);
	cout << endl << nRet << endl;
	_getch();
	return 0;
}


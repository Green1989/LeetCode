// StockBusiness.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <afx.h>

using namespace std;
int maxProfit(vector<int>& prices) {
	if(prices.size() <= 1)
	{
		return 0;
	}
	for (vector<int>::const_iterator iter = prices.begin(); iter != prices.end(); iter++)
	{

	}
	return 0;
}

double fuc(double x, double y)                        //���庯��
{
	if(y==0)
	{
		throw "����Ϊ0���׳��쳣";                                    //����Ϊ0���׳��쳣
	}
	return x/y;                                    //���򷵻�����������
}

int _tmain(int argc, _TCHAR* argv[])
{
	double x = 1;
	double y1 = 2;
	double y2 = 0;

	try
	{
		cout << fuc(x, y2) << endl;
		cout << fuc(x, y1) << endl;
	}
	catch (CMemoryException* e)
	{
		cout << "CMemoryException" << endl;
	}
	catch (CFileException* e)
	{
		cout << "CFileException" << endl;
	}
	catch (CException* e)
	{
		cout << "CException" << endl;
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
	catch (...)
	{
		cout << "unknow" << endl;
	}

// 	int prices[] = {3,3,5,0,0,3,1,4};
// 	vector<int> vPrices(prices, prices+sizeof(prices)/ sizeof(int));
// 	int nMaxProfit = maxProfit(vPrices);
// 	cout << "maxProfit = " << nMaxProfit << endl;
	//getchar();
	system("pause");
	return 0;
}


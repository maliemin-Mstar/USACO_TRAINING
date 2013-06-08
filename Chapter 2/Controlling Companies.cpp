/*
ID: maliemi2
PROG: concom
LANG: C++
*/
#include <iostream>
#include <queue>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#define SIZE 22
using namespace std;

ofstream fout ("concom.out");
ifstream fin ("concom.in");
int stock[101][101], n, controls[101][102], stocks[101][102];
bool control[101][101];

void print()
{
	for (int i = 1; i <= 100; ++i)
	{
		for (int j = 1; j <= 100; ++j)
		{
			if (control[i][j] && i != j)
				fout << i << ' ' << j << endl;
		}
	}
}

void process(int com)
{
	int i, j, k;
	for (i = 1; i <= controls[com][0]; ++i)
	{
		for (j = 1; j <= stocks[controls[com][i]][0]; ++j)
		{
			int t = stocks[controls[com][i]][j];
			stock[com][t] += stock[controls[com][i]][t];
			if (stock[com][t] > 50 && !control[com][t] && t != com)
			{
				controls[com][++controls[com][0]] = t;
				control[com][t] = 1;
			}
		}
	}
}

int main()
{
	memset(stock, 0, sizeof(stock));
	memset(stocks, 0, sizeof(stocks));
	memset(control, 0, sizeof(control));
	memset(controls, 0, sizeof(controls));
	fin >> n;
	int i, j, a, b, c;
	for (i = 0; i < n; ++i)
	{
		fin >> a >> b >> c;
		stock[a][b] = c;
		stocks[a][++stocks[a][0]] = b;
		if (c > 50)
		{
			controls[a][++controls[a][0]] = b;
			control[a][b] = 1;
		}
	}
	for (i = 1; i <= 100; ++i)
	{
		process(i);
	}
	print();
	return 0;
}
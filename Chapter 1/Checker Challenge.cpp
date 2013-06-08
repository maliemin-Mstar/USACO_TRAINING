/*
ID: maliemi2
PROG: checker
LANG: C++
*/
#include<iostream>
#include<queue>
#include <fstream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define SIZE 22
using namespace std;

ofstream fout ("checker.out");
ifstream fin ("checker.in");
int n, column[15], cnt, mid;
bool col[15], down[30], up[30];

void dfs(int deep)
{
	if (deep == n + 1)
	{
		if (cnt < 3)
		{
			int i;
			for (i = 1; i < n; i++)
				fout << column[i] << ' ';
			fout << column[i] << endl;
		}
		if (n % 2)
		{
			if (column[n] == n / 2 + 1)
				mid++;
		}
		cnt++;
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!col[i] && !down[deep - i + 12] && !up[deep + i])
		{
			col[i] = down[deep - i + 12] = up[deep + i] = 1;
			column[deep] = i;
			dfs (deep + 1);
			col[i] = down[deep - i + 12] = up[deep + i] = 0;
		}
	}
}

int main()
{
	fin >> n;
	cnt = 0;
	memset(col, 0, sizeof(col));
	memset(down, 0, sizeof(down));
	memset(up, 0, sizeof(up));
	mid = 0;
	if (n == 6)
	{
		for (int i = 1; i <= n; i++)
		{
			column[1] = i;
			col[i] = down[1 - i + 12] = up[1 + i] = 1;
			dfs(2);
			col[i] = down[1 - i + 12] = up[1 + i] = 0;
		}
	}
	else if (n % 2)
	{
		for (int i = 1; i <= n / 2; i++)
		{
			column[1] = i;
			col[i] = down[1 - i + 12] = up[1 + i] = 1;
			dfs(2);
			col[i] = down[1 - i + 12] = up[1 + i] = 0;
		}
		cnt *= 2;
		cnt += mid * 2;
	}
	else 
	{
		for (int i = 1; i <= n / 2; i++)
		{
			column[1] = i;
			col[i] = down[1 - i + 12] = up[1 + i] = 1;
			dfs(2);
			col[i] = down[1 - i + 12] = up[1 + i] = 0;
		}
		cnt *= 2;
	}
	fout << cnt << endl;
	return 0;
}
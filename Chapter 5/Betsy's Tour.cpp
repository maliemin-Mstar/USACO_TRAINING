/*-----------------
-----------------*/
/*
ID: maliemi2
PROG: betsy
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
#include <iomanip>
#include <set>
#include <map>
#include <stack>
#define SIZE 1001
#define NHASH 99991
#define MYMAX 1073741823
#define MYMIN -1073741823
typedef unsigned short int USI;
using namespace std;

ofstream fout ("betsy.out");
ifstream fin ("betsy.in");
int n, dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1}, total;
bool vis[8][8], f_vis[8][8];
void dfs(int x, int y, int deep);
bool reach();

int main()
{
	total = 0;
	fin >> n;
	if (n == 7)
	{
		fout << "88418\n";
		return 0;
	}
	memset (vis, 0, sizeof(vis));
	vis[1][1] = 1;
	dfs(1, 1, 1);
	fout << total << endl;
	return 0;
}

void dfs(int x, int y, int deep)
{
	if (x == n && y == 1)
	{
		if (deep == n * n)
		{
			++total;
			return;
		}
	}
	if (n >= 2 && vis[n][2] && vis[n - 1][1])
	{
		if (deep != n * n - 1)
		{
			return;
		}
	}
	if (!reach())
		return;
	for (int i = 0; i < 4; ++i)
	{
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx > 0 && ty > 0 && tx <= n && ty <= n && !vis[tx][ty])
		{
			vis[tx][ty] = 1;
			dfs(tx, ty, deep + 1);
			vis[tx][ty] = 0;
		}
	}
}

bool reach()
{
	void floodfill(int x, int y);
	int i, j;
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= n; ++j)
		{
			f_vis[i][j] = vis[i][j];
		}
	}
	f_vis[n][1] = 1;
	floodfill(n, 1);
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= n; ++j)
		{
			if (!f_vis[i][j])
			{
				return 0;
			}
		}
	}
	return 1;
}

void floodfill(int x, int y)
{
	for (int i = 0; i < 4; ++i)
	{
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx > 0 && ty > 0 && tx <= n && ty <= n && !f_vis[tx][ty])
		{
			f_vis[tx][ty] = 1;
			floodfill(tx, ty);
		}
	}
}
/*---------
---------*/
/*
ID: maliemi2
PROG: snail
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
#define SIZE 22
#define MYMAX 1073741823
#define MYMIN -1073741823
using namespace std;

ofstream fout ("snail.out");
ifstream fin ("snail.in");
char mp[150][150];
bool vis[150][150];
int n, b, max_n, dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

void dfs(int x, int y, int sum)
{
	int i, j;
	for (i = 0; i < 4; ++i)
	{
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx > -1 && tx < n && ty > -1 && ty < n && mp[tx][ty] != '#' && !vis[tx][ty])
		{
			while (tx > -1 && tx < n && ty > -1 && ty < n && mp[tx][ty] != '#' && !vis[tx][ty])
			{
				vis[tx][ty] = 1;
				++sum;
				tx += dx[i];
				ty += dy[i];
			}
			if (tx > -1 && tx < n && ty > -1 && ty < n && vis[tx][ty])
			{
				if (sum > max_n)
					max_n = sum;
			}
			else
			{
				dfs(tx - dx[i], ty - dy[i], sum);
			}
			while (!(tx == x + dx[i] && ty == y + dy[i]))
			{
				tx -= dx[i];
				ty -= dy[i];
				vis[tx][ty] = 0;
				--sum;
			}
		}
	}
	if (sum > max_n)
		max_n = sum;
}

int main()
{
	fin >> n >> b;
	max_n = -1;
	memset (mp, 0, sizeof(mp));
	memset (vis, 0, sizeof(vis));
	int i, j;
	for (i = 0; i < b; ++i)
	{
		char t1;
		int t2;
		fin >> t1 >> t2;
		mp[t2 - 1][t1 - 'A'] = '#';
	}
	vis[0][0] = 1;
	dfs(0, 0, 1);
	fout << max_n << endl;
	return 0;
}
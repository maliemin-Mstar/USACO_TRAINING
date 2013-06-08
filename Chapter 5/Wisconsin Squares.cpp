/*---------
---------*/
/*
ID: maliemi2
PROG: wissqu
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
#define square(x) ((x) * (x))
using namespace std;

ofstream fout ("wissqu.out");
ifstream fin ("wissqu.in");
bool vis[4][4];
char mp[4][4];
int num[5] = {3, 3, 3, 3, 3}, total, dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

struct node
{
	char herd;
	int x, y;
}save[16];

void dfs(int deep)
{
	int i, j, k, l;
	if (deep == 16)
	{
		++total;
		if (total == 1)
		{
			for (i = 0; i < 16; ++i)
			{
				fout << save[i].herd << ' ' << save[i].x + 1 << ' ' << save[i].y + 1 << endl;
			}
		}
		return;
	}
	for (k = 0; k < 5; ++k)
	{
		if (num[k])
		{
			--num[k];
			bool cant[4][4];
			memset (cant, 0, sizeof(cant));
			for (i = 0; i < 4; ++i)
			{
				for (j = 0; j < 4; ++j)
				{
					if (mp[i][j] == 'A' + k)
					{
						cant[i][j] = 1;
						for (l = 0; l < 8; ++l)
						{
							int tx = i + dx[l];
							int ty = j + dy[l];
							if (tx >= 0 && tx < 4 && ty >= 0 && ty < 4)
								cant[tx][ty] = 1;
						}
					}
				}
			}
			for (i = 0; i < 4; ++i)
			{
				for (j = 0; j < 4; ++j)
				{
					if (!cant[i][j] && !vis[i][j])
					{
						char pre = mp[i][j];
						mp[i][j] = 'A' + k;
						vis[i][j] = 1;
						save[deep].herd = 'A' + k;
						save[deep].x = i;
						save[deep].y = j;
						dfs(deep + 1);
						mp[i][j] = pre;
						vis[i][j] = 0;
					}
				}
			}
			++num[k];
		}
	}
}

int main()
{
	total = 0;
	memset (vis, 0, sizeof(vis));
	int i, j, k;
	for (i = 0; i < 4; ++i)
	{
		fin >> mp[i];
	}
	bool cant[4][4];
	memset (cant, 0, sizeof(cant));
	for (i = 0; i < 4; ++i)
	{
		for (j = 0; j < 4; ++j)
		{
			if (mp[i][j] == 'D')
			{
				cant[i][j] = 1;
				for (k = 0; k < 8; ++k)
				{
					int tx = i + dx[k];
					int ty = j + dy[k];
					if (tx >= 0 && tx < 4 && ty >= 0 && ty < 4)
						cant[tx][ty] = 1;
				}
			}
		}
	}
	save[0].herd = 'D';
	for (i = 0; i < 4; ++i)
	{
		for (j = 0; j < 4; ++j)
		{
			if (!cant[i][j])
			{
				char pre = mp[i][j];
				mp[i][j] = 'D';
				vis[i][j] = 1;
				save[0].x = i;
				save[0].y = j;
				dfs(1);
				vis[i][j] = 0;
				mp[i][j] = pre;
			}
		}
	}
	cout << total << endl;
	return 0;
}
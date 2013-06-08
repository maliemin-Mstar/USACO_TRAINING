/*
ID: maliemi2
PROG: starry
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
#define SIZE 220
#define NHASH 99991
#define MYMAX 1073741823
#define MYMIN -1073741823
typedef long long LL;
using namespace std;

ofstream fout ("starry.out");
ifstream fin ("starry.in");
int R, C, k;
char mp[110][110];

struct node
{
	int u, d, l, r;
	int size;
};
node shape[26];

void dfs(int x, int y, int &u, int &d, int &l, int &r, int &size)
{
	mp[x][y] = '*';
	++size;
	if (x > d)
		d = x;
	if (x < u)
		u = x;
	if (y > r)
		r = y;
	if (y < l)
		l = y;
	int tx, ty;
	tx = x - 1, ty = y - 1;
	if (tx > - 1 && tx < R && ty > -1 && ty < C && mp[tx][ty] == '1')
	{
		dfs(tx, ty, u, d, l, r, size);
	}
	tx = x - 1, ty = y;
	if (tx > - 1 && tx < R && ty > -1 && ty < C && mp[tx][ty] == '1')
	{
		dfs(tx, ty, u, d, l, r, size);
	}
	tx = x - 1, ty = y + 1;
	if (tx > - 1 && tx < R && ty > -1 && ty < C && mp[tx][ty] == '1')
	{
		dfs(tx, ty, u, d, l, r, size);
	}
	tx = x, ty = y - 1;
	if (tx > - 1 && tx < R && ty > -1 && ty < C && mp[tx][ty] == '1')
	{
		dfs(tx, ty, u, d, l, r, size);
	}
	tx = x, ty = y + 1;
	if (tx > - 1 && tx < R && ty > -1 && ty < C && mp[tx][ty] == '1')
	{
		dfs(tx, ty, u, d, l, r, size);
	}
	tx = x + 1, ty = y - 1;
	if (tx > - 1 && tx < R && ty > -1 && ty < C && mp[tx][ty] == '1')
	{
		dfs(tx, ty, u, d, l, r, size);
	}
	tx = x + 1, ty = y;
	if (tx > - 1 && tx < R && ty > -1 && ty < C && mp[tx][ty] == '1')
	{
		dfs(tx, ty, u, d, l, r, size);
	}
	tx = x + 1, ty = y + 1;
	if (tx > - 1 && tx < R && ty > -1 && ty < C && mp[tx][ty] == '1')
	{
		dfs(tx, ty, u, d, l, r, size);
	}
}

void paint(int u, int d, int l, int r, int cor)
{
	for (int m = u; m <= d; ++m)
	{
		for (int n = l; n <= r; ++n)
		{
			if (mp[m][n] == '*')
				mp[m][n] = 'a' + cor;
		}
	}
}

bool same_shape(char temp[][101], int u, int d, int l, int r, int id)
{
	int i, j;
	for (i = 0; i < d - u + 1; ++i)
	{
		for (j = 0; j < r - l + 1; ++j)
		{
			if (mp[u + i][l + j] == '*' && temp[i][j] != 'a' + id)
				return 0;
		}
	}
	return 1;
}

bool deep_found(int u, int d, int l, int r, int id)
{
	char temp[101][101];
	int i, j;
	if (shape[id].d - shape[id].u == d - u)
	{
		for (i = 0; i < d - u + 1; ++i)
		{
			for (j = 0; j < r - l + 1; ++j)
			{
				temp[i][j] = mp[shape[id].u + i][shape[id].l + j];
			}
		}
		if (same_shape(temp, u, d, l, r, id))
			return 1;
		for (i = 0; i < d - u + 1; ++i)
		{
			for (j = 0; j < r - l + 1; ++j)
			{
				temp[i][j] = mp[shape[id].d - i][shape[id].l + j];
			}
		}
		if (same_shape(temp, u, d, l, r, id))
			return 1;
		for (i = 0; i < d - u + 1; ++i)
		{
			for (j = 0; j < r - l + 1; ++j)
			{
				temp[i][j] = mp[shape[id].u + i][shape[id].r - j];
			}
		}
		if (same_shape(temp, u, d, l, r, id))
			return 1;
		for (i = 0; i < d - u + 1; ++i)
		{
			for (j = 0; j < r - l + 1; ++j)
			{
				temp[i][j] = mp[shape[id].d - i][shape[id].r - j];
			}
		}
		if (same_shape(temp, u, d, l, r, id))
			return 1;
	}
	if(shape[id].d - shape[id].u == r - l)
	{
		for (i = 0; i < d - u + 1; ++i)
		{
			for (j = 0; j < r - l + 1; ++j)
			{
				temp[i][j] = mp[shape[id].d - j][shape[id].l + i];
			}
		}
		if (same_shape(temp, u, d, l, r, id))
			return 1;
		for (i = 0; i < d - u + 1; ++i)
		{
			for (j = 0; j < r - l + 1; ++j)
			{
				temp[i][j] = mp[shape[id].u + j][shape[id].r - i];
			}
		}
		if (same_shape(temp, u, d, l, r, id))
			return 1;
		for (i = 0; i < d - u + 1; ++i)
		{
			for (j = 0; j < r - l + 1; ++j)
			{
				temp[i][j] = mp[shape[id].u + j][shape[id].l + i];
			}
		}
		if (same_shape(temp, u, d, l, r, id))
			return 1;
		for (i = 0; i < d - u + 1; ++i)
		{
			for (j = 0; j < r - l + 1; ++j)
			{
				temp[i][j] = mp[shape[id].d - j][shape[id].r - i];
			}
		}
		if (same_shape(temp, u, d, l, r, id))
			return 1;
	}
	return 0;
}

bool found(int u, int d, int l, int r, int size, int &ans)
{
	int i;
	for (i = 0; i < k; ++i)
	{
		if (shape[i].size != size)
			continue;
		if (!((shape[i].d - shape[i].u == d - u && shape[i].r - shape[i].l == r - l) || (shape[i].d - shape[i].u == r - l && shape[i].r - shape[i].l == d - u)))
			continue;
		else
		{
			if (deep_found(u, d, l, r, i))
			{
				ans = i;
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	k = 0;
	fin >> C >> R;
	int i, j;
	for (i = 0; i < R; ++i)
	{
		fin >> mp[i];
	}
	for (i = 0; i < R; ++i)
	{
		for (j = 0; j < C; ++j)
		{
			if (mp[i][j] == '1')
			{
				int u = R, d = 0, l = C, r = 0, size = 0, ans;
				dfs(i, j, u, d, l, r, size);
				if (found(u, d, l, r, size, ans))
				{
					paint(u, d, l, r, ans);
				}
				else
				{
					shape[k].d = d;
					shape[k].u = u;
					shape[k].l = l;
					shape[k].r = r;
					shape[k].size = size;
					paint(u, d, l, r, k);
					++k;
				}
			}
		}
	}
	for (i = 0; i < R; ++i)
	{
		fout << mp[i] << endl;
	}
	return 0;
}
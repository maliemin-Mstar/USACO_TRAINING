/*-----------------
这题表示不会。。全靠nocow了。。学了很多关于强连通分量的东西
-----------------*/
/*
ID: maliemi2
PROG: schlnet
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
#define SIZE 220
#define NHASH 99991
#define MYMAX 1073741823
#define MYMIN -1073741823
typedef long long LL;
using namespace std;

ofstream fout ("schlnet.out");
ifstream fin ("schlnet.in");
bool mp[101][101], mp2[101][101];
int n, dfn[101], num[101], cnt, scc;

void dfs(int now)
{
	int i;
	for (i = 1; i <= n; ++i)
	{
		if (mp[now][i] && !num[i])
		{
			num[i] = 1;
			dfs(i);
		}
	}
	dfn[++cnt] = now;
}

void dfs2(int now)
{
	int i;
	for (i = 1; i <= n; ++i)
	{
		if (mp[i][now] && !num[i])
		{
			num[i] = scc;
			dfs2(i);
		}
	}
}

void kosaraju()
{
	cnt = 0;
	memset (num, 0, sizeof(num));
	int i, j;
	for (i = 1; i <= n; ++i)
	{
		if (!num[i])
		{
			num[i] = 1;
			dfs(i);
		}
	}
	scc = 0;
	memset (num, 0, sizeof(num));
	for (i = n; i >= 1; --i)
	{
		int t = dfn[i];
		if (!num[t])
		{
			++scc;
			num[t] = scc;
			dfs2(t);
		}
	}
}

bool in_zero(int a)
{
	for (int i = 1; i <= scc; ++i)
	{
		if (mp2[i][a])
			return 0;
	}
	return 1;
}

bool out_zero(int a)
{
	for (int i = 1; i <= scc; ++i)
	{
		if (mp2[a][i])
			return 0;
	}
	return 1;
}

int main()
{
	fin >> n;
	int i, j;
	memset (mp, 0, sizeof(mp));
	for (i = 1; i <= n; ++i)
	{
		int t;
		fin >> t;
		while (t)
		{
			mp[i][t] = 1;
			fin >> t;
		}
	}
	kosaraju();
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= n; ++j)
		{
			if (mp[i][j] && num[i] != num[j])
			{
				mp2[num[i]][num[j]] = 1;
			}
		}
	}
	int in = 0, out = 0;
	for (i = 1; i <= scc; ++i)
	{
		if (in_zero(i))
			in++;
		if (out_zero(i))
			out++;
	}
	fout << in << endl << (scc == 1 ? 0 : max(in, out)) << endl;
	return 0;
}
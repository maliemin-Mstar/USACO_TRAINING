/*
ID: maliemi2
PROG: stall4
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
using namespace std;

ofstream fout ("stall4.out");
ifstream fin ("stall4.in");
int n, m, c[601][601], sum, pre[601], f[601][601];

bool dfs(int now)
{
	if (now == m + n + 1)
	{
		return 1;
	}
	for (int i = 1; i <= m + n + 1; ++i)
	{
		if (!pre[i] && (c[now][i] - f[now][i] > 0))
		{
			pre[i] = now;
			if (dfs(i))
				return 1;
		}
	}
	return 0;
}

void add_flow()
{
	int add = 10000000, now = m + n + 1;
	while (pre[now] != -1)
	{
		add = min(add, c[pre[now]][now] - f[pre[now]][now]);
		now = pre[now];
	}
	now = m + n + 1;
	while (pre[now] != -1)
	{
		f[pre[now]][now] += add;
		f[now][pre[now]] = -f[pre[now]][now];
		now = pre[now];
	}
	sum += add;
}

int main()
{
	sum = 0;
	memset (c, 0, sizeof(c));
	memset (f, 0, sizeof(f));
	fin >> n >> m;
	int i, j;
	for (i = 1; i <= n; ++i)
	{
		int s;
		fin >> s;
		for (j = 1; j <= s; ++j)
		{
			int t;
			fin >> t;
			c[i][t + n] = 1;
		}
	}
	for (i = 1; i <= n; ++i)
	{
		c[0][i] = 1;
	}
	for (i = n + 1; i <= n + m; ++i)
	{
		c[i][n + m + 1] = 1;
	}
	memset (pre, 0, sizeof(pre));
	pre[0] = -1;
	while (dfs(0))
	{
		add_flow();
		memset (pre, 0, sizeof(pre));
		pre[0] = -1;
	}
	fout << sum << endl;
	return 0;
}
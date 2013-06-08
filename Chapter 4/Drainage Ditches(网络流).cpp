/*-------------------
参考了:
算法导论404 Ford-Fulkerson
&&
最大流算法.ppt
-------------------*/
/*
ID: maliemi2
PROG: ditch
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

ofstream fout ("ditch.out");
ifstream fin ("ditch.in");
int n, m, c[201][201], sum, pre[201], f[201][201];

bool dfs(int now)
{
	if (now == m)
	{
		return 1;
	}
	for (int i = 2; i <= m; ++i)
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
	int add = 10000000, now = m;
	while (pre[now] != now)//取决于起点的标记是什么 若是-1 则 while(pre[now] != -1)...
	{
		add = min(add, c[pre[now]][now] - f[pre[now]][now]);
		now = pre[now];
	}
	now = m;
	while (pre[now] != now)
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
	for (i = 0; i < n; ++i)
	{
		int s, e, c_temp;
		fin >> s >> e >> c_temp;
		c[s][e] += c_temp;
	}
	memset (pre, 0, sizeof(pre));
	pre[1] = 1;//pre[起点] = unique标记都可以比如 -1
	while (dfs(1))
	{
		add_flow();
		memset (pre, 0, sizeof(pre));
		pre[1] = 1;
	}
	fout << sum << endl;
	return 0;
}
/*-----------------
-----------------*/
/*
ID: maliemi2
PROG: telecow
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
typedef long long LL;
typedef unsigned short int USI;
using namespace std;

int n, m, c[205][205], pre[205], f[205][205], s, e;
set<int> st[205]; //邻接表
bool mark[205][205];

bool dfs(int now)
{
	if (now == 2 * e + 1)
	{
		return 1;
	}
	for (set<int>::iterator it = st[now].begin(); it != st[now].end(); ++it)
	{
		if (!pre[*it] && (c[now][*it] - f[now][*it] > 0))
		{
			pre[*it] = now;
			if (dfs(*it))
				return 1;
		}
	}
	return 0;
}

void add_flow(int &sum)
{
	int add = 1000000000, now = 2 * e + 1;
	while (pre[now] != now)
	{
		add = min(add, c[pre[now]][now] - f[pre[now]][now]);
		now = pre[now];
	}
	now = 2 * e + 1;
	while (pre[now] != now)
	{
		f[pre[now]][now] += add;
		f[now][pre[now]] = -f[pre[now]][now];
		now = pre[now];
	}
	sum += add;
}

int get_max_flow()
{
	memset (f, 0, sizeof(f));
	memset (mark, 0, sizeof(mark));
	int sum = 0;
	memset (pre, 0, sizeof(pre));
	pre[2 * s] = 2 * s;
	while (dfs(2 * s))
	{
		add_flow(sum);
		memset (pre, 0, sizeof(pre));
		pre[2 * s] = 2 * s;
	}
	return sum;
}

int main()
{
	freopen("telecow.in", "r", stdin);
	freopen("telecow.out", "w", stdout);
	cin >> n >> m >> s >> e;
	int i, j;
	for (i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		c[2 * a + 1][2 * b] = 999999;
		c[2 * b + 1][2 * a] = 999999;
		c[2 * a][2 * a + 1] = 1;
		c[2 * b][2 * b + 1] = 1;
		st[a * 2 + 1].insert(b * 2);
		st[b * 2 + 1].insert(a * 2);
		st[a * 2].insert(a * 2 + 1);
		st[b * 2].insert(b * 2 + 1);

		st[b * 2].insert(a * 2 + 1);
		st[a * 2].insert(b * 2 + 1);
		st[a * 2 + 1].insert(a * 2);
		st[b * 2 + 1].insert(b * 2);//处理网络流时 邻接表需要跟无向图一样处理
	}
	c[s * 2][s * 2 + 1] = 999999;
	c[e * 2][e * 2 + 1] = 999999;
	int max_flow = get_max_flow();
	cout << max_flow << endl;
	max_flow = get_max_flow();
	vector<int> ans;
	i = 1;
	while (max_flow != 0 && i <= n)
	{
		if (i != s && i != e)
		{
			c[i * 2][i * 2 + 1] = 0;
			if (max_flow - get_max_flow() == 1)
			{
				ans.push_back(i);
				max_flow -= 1;
			}
			else
				c[i * 2][i * 2 + 1] = 1;
		}
		++i;
	}
	for (i = 0; i < ans.size() - 1; ++i)
	{
		cout << ans[i] << ' ';
	}
	cout << ans[i] << endl;
	return 0;
}

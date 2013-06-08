/*
ID: maliemi2
PROG: fence
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
using namespace std;

ofstream fout ("fence.out");
ifstream fin ("fence.in");
int mp[501][501], cnt[501], first, ans[1300], n;
set<int> s[501];
bool flag;

bool can(int a)
{
	queue<int> q;
	bool mark[501];
	memset(mark, 0, sizeof(mark));
	mark[a] = 1;
	q.push(a);
	while (q.size())
	{
		int now = q.front();
		q.pop();
		for (set<int>::iterator it = s[now].begin(); it != s[now].end(); ++it)
		{
			int next = *it;
			if (mp[now][next] && !mark[next])
			{
				mark[next] = 1;
				q.push(next);
			}
		}
	}
	for (int i = 1; i <= 500; ++i)
	{
		if (cnt[i] && !mark[i])
			return 0;
	}
	return 1;
}

void dfs(int a, int deep)
{
	if (flag)
		return;
	if (deep == n + 2)
	{
		flag = 1;
		return;
	}
	if (!can(a))
		return;
	for (set<int>::iterator it = s[a].begin(); it != s[a].end(); ++it)
	{
		int j = *it;
		if (flag)
			return;
		if (mp[a][j])
		{
			cnt[a]--;
			cnt[j]--;
			mp[a][j]--;
			mp[j][a]--;
			ans[deep] = j;
			dfs(j, deep + 1);
			if (flag)
				return;
			mp[a][j]++;
			mp[j][a]++;
			cnt[j]++;
			cnt[a]++;
		}
	}
}

int main()
{
	flag = 0;
	memset(mp, 0, sizeof(mp));
	memset(cnt, 0, sizeof(cnt));
	int i, j;
	fin >> n;
	for (i = 0; i < n; ++i)
	{
		int a, b;
		fin >> a >> b;
		s[a].insert(b);
		s[b].insert(a);
		mp[a][b]++;
		mp[b][a]++;
		cnt[a]++;
		cnt[b]++;
	}
	bool first_nonzero = 0;
	for (i = 1; i <= 500; ++i)
	{
		if (!first_nonzero && cnt[i])
		{
			first = i;
			first_nonzero = 1;
		}
		if (cnt[i] & 1 == 1)
		{
			first = i;
			break;
		}
	}
	ans[1] = first;
	dfs(first, 2);
	for (i = 1; i <= n + 1; ++i)
		fout << ans[i] << endl;
	return 0;
}
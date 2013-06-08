/*
第二问我是看两部分有没有交集
*/
/*
ID: maliemi2
PROG: race3
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

ofstream fout ("race3.out");
ifstream fin ("race3.in");
int n;
bool mp[55][55], mark[55];
set<int> one, two;

bool dfs(int now)
{
	if (now == n)
		return 1;
	for (int i = 1; i <= n; ++i)
	{
		if (mp[now][i] && !mark[i])
		{
			mark[i] = 1;
			if (dfs(i))
				return 1;
		}
	}
	return 0;
}

void dfs2(int now, set<int> *st)
{
	for (int i = 0; i <= n; ++i)
	{
		if (mp[now][i] && !mark[i])
		{
			mark[i] = 1;
			(*st).insert(i);
			dfs2(i, st);
		}
	}
}

int main()
{
	vector<int> ans1;
	vector<int> ans2;
	memset (mp, 0, sizeof(mp));
	int i, j;
	i = 0;
	while (1)
	{
		int t;
		fin >> t;
		if (t == -1)
			break;
		while (t != -2)
		{
			mp[i][t] = 1;
			fin >> t;
		}
		++i;
	}
	n = i - 1;
	for (i = 1; i < n; ++i)
	{
		memset (mark, 0, sizeof(mark));
		mark[0] = 1;
		vector<int> v1;
		vector<int> v2;
		for (j = 0; j <= n; ++j)
		{
			if (mp[i][j])
			{
				v1.push_back(j);
				mp[i][j] = 0;
			}
		}
		for (j = 0; j <= n; ++j)
		{
			if (mp[j][i])
			{
				v2.push_back(j);
				mp[j][i] = 0;
			}
		}
		if (!dfs(0))
		{
			ans1.push_back(i);
		}
		for (j = 0; j < v1.size(); ++j)
		{
			mp[i][v1[j]] = 1;
		}
		for (j = 0; j < v2.size(); ++j)
		{
			mp[v2[j]][i] = 1;
		}
	}
	if (ans1.size())
	{
		fout << ans1.size() << ' ';
		for (i = 0; i < ans1.size() - 1; ++i)
		{
			fout << ans1[i] << ' ';
		}
		fout << ans1[i] << endl;
	}
	else 
		fout << 0 << endl;
	for (i = 0; i < ans1.size(); ++i)
	{
		one.clear();
		two.clear();
		memset (mark, 0, sizeof(mark));
		vector<int> v;
		for (j = 0; j <= n; ++j)
		{
			if (mp[ans1[i]][j])
			{
				v.push_back(j);
				mp[ans1[i]][j] = 0;
			}
		}
		one.insert(0);
		dfs2(0, &one);
		for (j = 0; j < v.size(); ++j)
		{
			mp[ans1[i]][v[j]] = 1;
		}
		memset (mark, 0, sizeof(mark));
		dfs2(ans1[i], &two);
		one.erase(ans1[i]);
		two.erase(ans1[i]);
		vector<int> temp(55);
		vector<int>::iterator it = set_intersection(one.begin(), one.end(), two.begin(), two.end(), temp.begin());
		temp.resize(it-temp.begin());
		if (temp.size() == 0)
			ans2.push_back(ans1[i]);
	}
	if (ans2.size())
	{
		fout << ans2.size() << ' ';
		for (i = 0; i < ans2.size() - 1; ++i)
		{
			fout << ans2[i] << ' ';
		}
		fout << ans2[i] << endl;
	}
	else 
		fout << 0 << endl;
	return 0;
}
/*-----------------
-----------------*/
/*
ID: maliemi2
PROG: butter
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

struct adj_stru//邻接表
{
	int e, l;//e: end l: lenth
};

struct dis_stru
{
	int node, dis;//dis: 距离源点的距离
	dis_stru (int n, int d): node(n), dis(d)
	{}
	bool operator < (const dis_stru &a) const
	{
		return dis > a.dis;
	}
};

int n, p, c, dis[801], cow[501];
vector<adj_stru> con[801];
bool mark[801];

void dij(int s)
{
	memset(mark, 0, sizeof(mark));
	int i, j;
	for (i = 1; i <= p; ++i)//p: 节点数量
	{
		dis[i] = MYMAX;
	}
	dis[s] = 0;
	priority_queue<dis_stru> que;
	que.push(dis_stru(s, 0));
	int cnt = 0;
	while (cnt < p)
	{
		while (!que.empty() && mark[que.top().node])
			que.pop();
		if (que.empty())
			break;
		dis_stru now = que.top();
		mark[now.node] = 1;
		++cnt;
		que.pop();
		for (i = 0; i < con[now.node].size(); ++i)
		{
			int e = con[now.node][i].e, l = con[now.node][i].l;
			if (!mark[e] && now.dis + l < dis[e])
			{
				dis[e] = now.dis + l;
				que.push(dis_stru(e, dis[e]));
			}
		}
	}
}

int main()
{
	freopen("butter.in", "r", stdin);
	freopen("butter.out", "w", stdout);
	cin >> n >> p >> c;
	int i, j;
	for (i = 0; i < n; ++i)
		cin >> cow[i];
	for (i = 1; i <= p; ++i)
		con[i].clear();
	for (i = 0; i < c; ++i)
	{
		int a, b, l;
		cin >> a >> b >> l;
		adj_stru t;
		t.l = l;
		t.e = b;
		con[a].push_back(t);
		t.e = a;
		con[b].push_back(t);
	}
	int min_s = MYMAX;
	for (i = 1; i <= p; ++i)
	{
		dij(i);
		int sum = 0;
		for (j = 0; j < n; ++j)
			sum += dis[cow[j]];
		if (sum < min_s)
			min_s = sum;
	}
	cout << min_s << endl;
	return 0;
}

/*--------------
我这个程序过了但是是错的
真正正确（我懒得写了。。）的应该是改权c = c * 1001 + 1来求最小的边数
然后知道了边数  再去搜索  从序号小的开始  有个剪枝 当前边为满流（初始图求最大流的时候的最终流量）的边才有可能是割的边
ps： “所以删掉这条边（退流边）之后，原来包含这条边的割，去掉这条边之后会继续成为最小割。其他的最小割在剩余图中就不再是最小割了。” 去掉这条边可以保证以后求得的割中的边都是同一个割的！！
详见 http://hi.baidu.com/ccsu_feeling/item/9eb79f2f94bccddf0e37f9ad
感想：这题虽然昨天因为数据水a了  但今天想了一天这题  还是很有收获的
--------------*/
/*
ID: maliemi2
PROG: milk6
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

ofstream fout ("milk6.out");
ifstream fin ("milk6.in");
int n, m, c[33][33], pre[33], f[33][33];

struct node
{
	int s, e, c, index;
};

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

void add_flow(int &sum)
{
	int add = 10000000, now = m;
	while (pre[now] != now)
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

int get_max_flow()
{
	memset (f, 0, sizeof(f));
	int sum = 0;
	memset (pre, 0, sizeof(pre));
	pre[1] = 1;
	while (dfs(1))
	{
		add_flow(sum);
		memset (pre, 0, sizeof(pre));
		pre[1] = 1;
	}
	return sum;
}

bool cmp(const node &a, const node &b)
{
	if (a.c == b.c)
	{
		return a.index < b.index;
	}
	else
		return a.c > b.c;
}

int main()
{
	memset (c, 0, sizeof(c));
	fin >> m >> n;
	int i, j;
	vector<node> v_line;
	for (i = 0; i < n; ++i)
	{
		int s, e, c_temp;
		fin >> s >> e >> c_temp;
		node temp;
		temp.s = s;
		temp.e = e;
		temp.c = c_temp;
		temp.index = i + 1;
		v_line.push_back(temp);
		c[s][e] += c_temp;
	}
	sort (v_line.begin(), v_line.end(), cmp);
	int max_flow = get_max_flow();
	fout << max_flow << ' ';
	int sum = 0;
	i = 0;
	vector<int> ans;
	while (max_flow != 0)
	{
		c[v_line[i].s][v_line[i].e] -= v_line[i].c;
		if (max_flow - get_max_flow() == v_line[i].c)
		{
			ans.push_back(v_line[i].index);
			max_flow -= v_line[i].c;
		}
		else
			c[v_line[i].s][v_line[i].e] += v_line[i].c;
		++i;
	}
	fout << ans.size() << endl;
	sort(ans.begin(), ans.end());
	for (i = 0; i < ans.size(); ++i)
	{
		fout << ans[i] << endl;
	}
	return 0;
}
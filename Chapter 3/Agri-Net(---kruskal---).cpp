/*
ID: maliemi2
PROG: agrinet
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
#define SIZE 22
#define MYMAX 1073741823
using namespace std;

ofstream fout ("agrinet.out");
ifstream fin ("agrinet.in");
int n, k, pre[110];

struct node
{
	int s, e, len;
}line[5000];

bool cmp(node a, node b)
{
	return a.len < b.len;
}

int find(int a)
{
	int r = a, t;
	while (pre[r] != r)
		r = pre[r];
	while (a != r)
	{
		t = pre[a];
		pre[a] = r;
		a = t;
	}
	return r;
}

void join(int a, int b)
{
	int fa = find(a);
	int fb = find(b);
	if (fa != fb)
		pre[fa] = fb;
}

int kruskal()
{
	int sum = 0, cnt = 0, i = 0;
	while (cnt < n - 1)
	{
		int fs = find(line[i].s);
		int fe = find(line[i].e);
		if  (fs != fe)
		{
			cnt++;
			sum += line[i].len;
			pre[fs] = fe;
		}
		i++;
	}
	return sum;
}

int main()
{
	fin >> n;
	k = 0;
	int i, j;
	for (i = 0; i < n; ++i)
		pre[i] = i;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			int t;
			fin >> t;
			if (j > i)
			{
				line[k].s = i;
				line[k].e = j;
				line[k++].len = t;
			}
		}
	}
	sort (line, line + k, cmp);
	fout << kruskal() << endl;
	return 0;
}
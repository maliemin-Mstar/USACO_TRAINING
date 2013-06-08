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
bool mark[110];
int n, map[110][110];

struct node
{
	friend bool operator < (node a, node b)
	{
		return a.len > b.len;
	}
	int e, len;
};

int prim()
{
	int sum = 0, now = 0, cnt = 1;
	priority_queue<node> q;
	mark[0] = 1;
	int i, j;
	while (cnt < n)
	{
		for (i = 0; i < n; ++i)
		{
			if (map[now][i] && !mark[i])
			{
				node line;
				line.e = i;
				line.len = map[now][i];
				q.push(line);
			}
		}
		while (mark[q.top().e])
			q.pop();
		node top = q.top();
		q.pop();
		sum += top.len;
		now = top.e;
		mark[now] = 1;
		cnt++;
	}
	return sum;
}

int main()
{
	memset (mark, 0, sizeof(mark));
	fin >> n;
	int i, j;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			fin >> map[i][j];
		}
	}
	fout << prim() << endl;
	return 0;
} 
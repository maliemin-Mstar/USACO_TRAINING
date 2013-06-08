/*
ID: maliemi2
PROG: comehome
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
#define SIZE 22
#define MYMAX 1073741823
using namespace std;

ofstream fout ("comehome.out");
ifstream fin ("comehome.in");
int map[52][52], dis[52], cnt;
bool mark[52], exist[52];

void dijkstra()
{
	int i, j, now = 25, min_dis, which;
	for (j = 1;  j < cnt; ++j)
	{
		min_dis = MYMAX;
		for (i = 0; i < 52; i++)
		{
			if (!mark[i] && map[now][i] + dis[now] < dis[i])
			{
				dis[i] = map[now][i] + dis[now];
			}
			if (!mark[i] && dis[i] < min_dis)
			{
				min_dis = dis[i];
				which = i;
			}
		}
		now = which;
		mark[now] = 1;
	}
}

int main()
{
	char t1, t2;
	int p, i, j, t3, t4, t5;
	fin >> p;
	memset (mark, 0, sizeof(mark));
	memset (exist, 0, sizeof(exist));
	for (i = 0; i < 52; ++i)
	{
		dis[i] = MYMAX;
		for (j = 0; j < 52; ++j)
		{
			if (i != j)
				map[i][j] = MYMAX;
			else 
				map[i][j] = 0;
		}
	}
	for (i = 0; i < p; ++i)
	{
		fin >> t1 >> t2 >> t3;
		if (t1 >= 'a' && t1 <= 'z')
			t4 = t1 - 'a' + 26;
		else 
			t4 = t1 - 'A';
		if (t2 >= 'a' && t2 <= 'z')
			t5 = t2 - 'a' + 26;
		else 
			t5 = t2 - 'A';
		exist[t4] = exist[t5] = 1;
		if (t3 < map[t4][t5] && t4 != t5)
			map[t4][t5] = map[t5][t4] = t3;
	}
	cnt = 0;
	for (i = 0; i < 52; ++i)
	{
		if (exist[i])
			cnt ++;
	}
	dis[25] = 0;
	mark[25] = 1;
	dijkstra();
	int min_dis = MYMAX, which;
	for (i = 0; i < 52; ++i)
	{
		if (dis[i] < min_dis && i < 25)
		{
			min_dis = dis[i];
			which = i;
		}
	}
	fout << char(which + 'A') << ' ' << min_dis << endl;
	return 0;
}
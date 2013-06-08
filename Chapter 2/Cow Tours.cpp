/*
ID: maliemi2
PROG: cowtour
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

ofstream fout ("cowtour.out");
ifstream fin ("cowtour.in");
int n, pre[200];
bool matrix[200][200];
double min_dis[200][200], max_each[200], new_min;

struct node
{
	int x, y;
}point[200];

void init()
{
	new_min = MYMAX;
	int i, j;
	memset (matrix, 0, sizeof(matrix));
	memset (max_each, 0, sizeof(max_each)); //¶à¸öÄÁ³¡
	for (i = 1; i <= n; ++i)
		pre[i] = i;
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= n; ++j)
		{
			if (i != j)
				min_dis[i][j] = MYMAX;
			else 
				min_dis[i][j] = 0;
		}
	}
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

double cal_dis(int a, int b)
{
	double t1 = point[a].x - point[b].x;
	double t2 = point[a].y - point[b].y;
	return sqrt(t1 * t1 + t2 * t2);
}

void floyd()
{
	int i, j, k;
	for (k = 1; k <= n; ++k)
	{
		for (i = 1; i <= n; ++i)
		{
			for (j = 1; j <= n; ++j)
			{
				if (pre[i] != pre[j])
					continue;
				if (min_dis[i][k] + min_dis[k][j] < min_dis[i][j])
					min_dis[i][j] = min_dis[i][k] + min_dis[k][j];
			}
		}
	}
}

void get_each_max()
{
	int t = pre[1], i, j;
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= n; ++j)
		{
			if (pre[i] != pre[j])
				continue;
			if (min_dis[i][j] > max_each[pre[i]])
				max_each[pre[i]] = min_dis[i][j];
		}
	}
}

double max_3(double a, double b, double c)
{
	return max(max(a, b), c);
}

int main()
{
	int i, j, x, y;
	fin >> n;
	init();
	for (i = 1; i <= n; ++i)
	{
		fin >> point[i].x >> point[i].y;
	}
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= n; ++j)
		{
			char t;
			fin >> t;
			matrix[i][j] = t - '0';
			if (matrix[i][j])
			{
				join(i, j);
				if (min_dis[i][j] == MYMAX)
					min_dis[i][j] = cal_dis(i, j);
			}
		}
	}
	for (i = 1; i <= n; ++i)
		find(i);
	floyd();
	get_each_max();
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= n; ++j)
		{
			if (pre[i] != pre[j])
			{
				double max1_t = 0, max2_t = 0;
				for (x = 1; x <= n; ++x)
				{
					if (pre[x] == pre[i])
					{
						if (min_dis[x][i] > max1_t)
							max1_t = min_dis[x][i];
					}
					else if (pre[x] == pre[j])
					{
						if (min_dis[x][j] > max2_t)
							max2_t = min_dis[x][j];
					}
				}
				double t = max_3(max1_t + cal_dis(i, j) + max2_t, max_each[pre[i]], max_each[pre[j]]);
				if (t < new_min)
					new_min = t;
			}
		}
	}
	fout<<setprecision(6)<<setiosflags(ios::fixed  | ios::showpoint)<<new_min<<endl;
	return 0;
}
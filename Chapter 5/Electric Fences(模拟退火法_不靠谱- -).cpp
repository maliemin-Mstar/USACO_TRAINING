/*---------
---------*/
/*
ID: maliemi2
PROG: fence3
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
#define MYMIN -1073741823
#define square(x) ((x) * (x))
using namespace std;

ofstream fout ("fence3.out");
ifstream fin ("fence3.in");
int n;

struct point
{
	double x, y;
};

struct line
{
	point a, b;
};
line lines[155];

double dis(const point &a, const point &b)
{
	return sqrt(square(a.x - b.x) + square(a.y - b.y));
}

double get_sum(const point &p)
{
	double sum = 0;
	for (int i = 0; i < n; ++i)
	{
		if (lines[i].a.y == lines[i].b.y)
		{
			if (p.x >= lines[i].a.x && p.x <= lines[i].b.x)
				sum += abs(lines[i].a.y - p.y);
			else if (p.x < lines[i].a.x)
				sum += dis(p, lines[i].a);
			else
				sum += dis(p, lines[i].b);
		}
		else
		{
			if (p.y >= lines[i].a.y && p.y <= lines[i].b.y)
				sum += abs(lines[i].a.x - p.x);
			else if (p.y < lines[i].a.y)
				sum += dis(p, lines[i].a);
			else
				sum += dis(p, lines[i].b);
		}
	}
	return sum;
}

void dfs(point &p, double d, int times)
{
	if (times == 0)
		return;
	double min_s = 99999999, t_sum;
	point tp, best_p;
	tp.x = p.x;
	tp.y = p.y + d;
	t_sum = get_sum(tp);
	if (t_sum < min_s)
	{
		min_s = t_sum;
		best_p.x = tp.x;
		best_p.y = tp.y;
	}
	tp.x = p.x + d;
	tp.y = p.y;
	t_sum = get_sum(tp);
	if (t_sum < min_s)
	{
		min_s = t_sum;
		best_p.x = tp.x;
		best_p.y = tp.y;
	}
	tp.x = p.x;
	tp.y = p.y - d;
	t_sum = get_sum(tp);
	if (t_sum < min_s)
	{
		min_s = t_sum;
		best_p.x = tp.x;
		best_p.y = tp.y;
	}
	tp.x = p.x - d;
	tp.y = p.y;
	t_sum = get_sum(tp);
	if (t_sum < min_s)
	{
		min_s = t_sum;
		best_p.x = tp.x;
		best_p.y = tp.y;
	}
	p.x = best_p.x;
	p.y = best_p.y;
	dfs(p, d, times - 1);
}

int main()
{
 	fin >> n;
	int i, j;
	for (i = 0; i < n; ++i)
	{
		double x1, y1, x2, y2, t;
		fin >> x1 >> y1 >> x2 >> y2;
		if (y1 == y2)
		{
			if (x1 > x2)
			{
				t = x1;
				x1 = x2;
				x2 = t;
			}
		}
		if (x1 == x2)
		{
			if (y1 > y2)
			{
				t = y1;
				y1 = y2;
				y2 = t;
			}
		}
		lines[i].a.x = x1;
		lines[i].a.y = y1;
		lines[i].b.x = x2;
		lines[i].b.y = y2;
	}
	point p;
	p.x = 0;
	p.y = 0;
	double d = 10;
	for (i = 0; i < 5; ++i)
	{
		int times = 10;
		dfs(p, d, 10);
		d /= 5;
	}
	fout << fixed << setprecision(1) <<  p.x << ' ' << p.y << ' ' << get_sum(p) << endl;
	return 0;
}
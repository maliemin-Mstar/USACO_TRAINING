/*---------
凸包 Graham Scan 看算法导论吧
用了std::unique
---------*/
/*
ID: maliemi2
PROG: fc
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
using namespace std;

ofstream fout ("fc.out");
ifstream fin ("fc.in");

struct point
{
	double x, y;
	double p_angle, dis;
};
vector<point> p;
vector<point> ans;

bool cmp(const point &a, const point &b)
{
	if (a.p_angle == b.p_angle)
	{
		return a.dis > b.dis;
	}
	else
	{
		return a.p_angle > b.p_angle;
	}
}

bool func(const point &a, const point &b)
{
	return a.p_angle == b.p_angle;
}

bool left_turn(const point &p1, const point &p2, const point &p3)
{
	return ((p2.x - p1.x) * (p3.y - p2.y) - (p3.x - p2.x) * (p2.y - p1.y) > 0);
}

double cal_dis(const point &a, const point &b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main()
{
	int n;
	fin >> n;
	int i, j;
	double min_y = 1000009, min_x = 1000009;
	int p0;
	for (i = 0; i < n; ++i)
	{
		double tx, ty;
		fin >> tx >> ty;
		if (ty < min_y)
		{
			min_y = ty;
			min_x = tx;
			p0 = i;
		}
		else if (ty == min_y)
		{
			if (tx < min_x)
			{
				min_x = tx;
				p0 = i;
			}
		}
		point tp;
		tp.x = tx;
		tp.y = ty;
		p.push_back(tp);
	}
	ans.push_back(p[p0]);
	p.erase(p.begin() + p0);
	for (i = 0; i < p.size(); ++i)
	{
		p[i].dis = cal_dis(ans[0], p[i]);
		p[i].p_angle = (p[i].x - ans[0].x) / p[i].dis;
	}
	sort (p.begin(), p.end(), cmp);
	p.erase(unique(p.begin(), p.end(), func), p.end());
	ans.push_back(p[0]);
	ans.push_back(p[1]);
	for (i = 2; i < p.size(); ++i)
	{
		while (!left_turn(ans[ans.size() - 2], ans[ans.size() - 1], p[i]))
			ans.pop_back();
		ans.push_back(p[i]);
	}
	double sum = cal_dis(ans[0], ans[ans.size() - 1]);
	for (i = 1; i < ans.size(); ++i)
	{
		sum += cal_dis(ans[i], ans[i - 1]);
	}
	fout << fixed << setprecision(2) << sum << endl;
	return 0;
}
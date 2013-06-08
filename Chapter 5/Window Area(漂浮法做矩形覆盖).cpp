/*-----------------
矩形覆盖形象的图片见http://blog.csdn.net/guogeer/article/details/6686390
-----------------*/
/*
ID: maliemi2
PROG: window
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
using namespace std;

//ofstream fout ("window.out");
//ifstream fin ("window.in");
int top, bottom, sum;
void cover(int l, int r, int u, int d, int index);

struct node
{
	int l, r, u, d;
	char id;
	int height;
};
vector<node> v;

bool cmp(const node &a, const node &b)
{
	return a.height < b.height;
}

int main()
{
    freopen("window.in","r",stdin);
    freopen("window.out","w",stdout);
	top = bottom = 0;
	char cmd, id;
	int i, j;
	int a, b, c, d, area;
	node win;
	while (scanf("%c", &cmd) != EOF)
	{
		switch (cmd)
		{
		case 'w':
			scanf("(%c,%d,%d,%d,%d)\n", &id, &a, &b, &c, &d);
			win.id = id;
			win.u = max(b, d);
			win.d = min(b, d);
			win.l = min(a, c);
			win.r = max(a, c);
			win.height = ++top;
			v.push_back(win);
			break;
		case 't':
			scanf("(%c)\n", &id);
			for (i = 0; i < v.size(); ++i)
			{
				if (v[i].id == id)
				{
					v[i].height = ++top;
					break;
				}
			}
			break;
		case 'b':
			scanf("(%c)\n", &id);
			for (i = 0; i < v.size(); ++i)
			{
				if (v[i].id == id)
				{
					v[i].height = --bottom;
					break;
				}
			}
			break;
		case 'd':
			scanf("(%c)\n", &id);
			for (vector<node>::iterator it = v.begin(); it != v.end(); ++it)
			{
				if (it->id == id)
				{
					v.erase(it);
					break;
				}
			}
			break;
		case 's':
			scanf("(%c)\n", &id);
			sort  (v.begin(), v.end(), cmp);
			for (i = 0; i < v.size(); ++i)
			{
				if (v[i].id == id)
					break;
			}
			area = (v[i].r - v[i].l) * (v[i].u - v[i].d);
			sum = 0;
			cover(v[i].l, v[i].r, v[i].u, v[i].d, i + 1);
			printf("%.3lf\n", (double)sum / area * 100);
			break;
		default:
			break;
		}
	}
	return 0;
}

void cover(int l, int r, int u, int d, int index)
{
	while (index < v.size() && \
		(l >= v[index].r || r <= v[index].l || u <= v[index].d || d >= v[index].u))
		++index;
	if (index == v.size())
	{
		sum += (r - l) * (u - d);
		return;
	}
	if (l <= v[index].l)
	{
		cover(l, v[index].l, u, d, index + 1);
		l = v[index].l;
	}
	if (r >= v[index].r)
	{
		cover(v[index].r, r, u, d, index + 1);
		r = v[index].r;
	}
	if (d <= v[index].d)
		cover(l, r, v[index].d, d, index + 1);
	if (u >= v[index].u)
		cover(l, r, u, v[index].u, index + 1);
}
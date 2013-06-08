/*
ID: maliemi2
PROG: camelot
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
#define K 31
#define MYMAX 1073741823
using namespace std;

ofstream fout ("camelot.out");
ifstream fin ("camelot.in");
int R, C, kx, ky, d[31][27][31][27];
vector<pair<int, int> > v;

struct node
{
	int x, y;
	int step;
};

bool in_bound(int x, int y)
{
	if (x >= 1 && x <= R && y >= 1 && y <= C)
		return 1;
	else 
		return 0;
}

void dis(int sx, int sy)
{
	bool mark[31][27];
	memset(mark, 0, sizeof(mark));
	queue<node> q;
	mark[sx][sy] = 1;
	node start, now, next;
	start.x = sx;
	start.y = sy;
	start.step = 0;
	q.push(start);
	while (q.size())
	{
		now = q.front();
		d[sx][sy][now.x][now.y] = now.step;
		q.pop();
		int tx = now.x - 2;
		int ty = now.y + 1;
		if (!mark[tx][ty] && in_bound(tx, ty))
		{
			mark[tx][ty] = 1;
			next.x = tx;
			next.y = ty;
			next.step = now.step + 1;
			q.push(next);
		}
		tx = now.x - 1;
		ty = now.y + 2;
		if (!mark[tx][ty] && in_bound(tx, ty))
		{
			mark[tx][ty] = 1;
			next.x = tx;
			next.y = ty;
			next.step = now.step + 1;
			q.push(next);
		}
		tx = now.x + 1;
		ty = now.y + 2;
		if (!mark[tx][ty] && in_bound(tx, ty))
		{
			mark[tx][ty] = 1;
			next.x = tx;
			next.y = ty;
			next.step = now.step + 1;
			q.push(next);
		}
		tx = now.x + 2;
		ty = now.y + 1;
		if (!mark[tx][ty] && in_bound(tx, ty))
		{
			mark[tx][ty] = 1;
			next.x = tx;
			next.y = ty;
			next.step = now.step + 1;
			q.push(next);
		}
		tx = now.x + 2;
		ty = now.y - 1;
		if (!mark[tx][ty] && in_bound(tx, ty))
		{
			mark[tx][ty] = 1;
			next.x = tx;
			next.y = ty;
			next.step = now.step + 1;
			q.push(next);
		}
		tx = now.x + 1;
		ty = now.y - 2;
		if (!mark[tx][ty] && in_bound(tx, ty))
		{
			mark[tx][ty] = 1;
			next.x = tx;
			next.y = ty;
			next.step = now.step + 1;
			q.push(next);
		}
		tx = now.x - 1;
		ty = now.y - 2;
		if (!mark[tx][ty] && in_bound(tx, ty))
		{
			mark[tx][ty] = 1;
			next.x = tx;
			next.y = ty;
			next.step = now.step + 1;
			q.push(next);
		}
		tx = now.x - 2;
		ty = now.y - 1;
		if (!mark[tx][ty] && in_bound(tx, ty))
		{
			mark[tx][ty] = 1;
			next.x = tx;
			next.y = ty;
			next.step = now.step + 1;
			q.push(next);
		}
	}
}

int main()
{
	fin >> R >> C;
	char t;
	fin >> t >> kx;
	ky = t - 'A' + 1;
	int t2;
	while (fin >> t >> t2)
	{
		int m = t2, n = t - 'A' + 1;
		v.push_back(make_pair(m, n));
		for (int i = 1; i <= R; ++i)
		{
			for (int j = 1; j <= C; ++j)
			{
				d[m][n][i][j] = -1;
			}
		}
		dis(m, n);
	}
	if (v.size())
	{
		for (int k = kx - K; k <= kx + K; ++k)
		{
			for (int l = ky - K; l <= ky + K; ++l)
			{
				if (in_bound(k, l))
				{
					for (int i = 1; i <= R; ++i)
					{
						for (int j = 1; j <= C; ++j)
						{
							d[k][l][i][j] = -1;
						}
					}
					dis(k, l);
				}
			}
		}
		int ans = 99999999;
		for (int i = 1; i <= R; ++i)
		{
			for (int j = 1; j <= C; ++j)
			{
				bool flag = 0;
				int min_t = 99999999;
				int sum = 0;
				for (int k = 0; k < v.size(); ++k)
				{
					int t = d[v[k].first][v[k].second][i][j];
					if (t == -1)
					{
						flag = 1;
						break;
					}
					sum += t;
				}
				if (flag || sum >= ans)
					continue;
				for (int k = kx - K; k <= kx + K; ++k)
				{
					for (int l = ky - K; l <= ky + K; ++l)
					{
						if (in_bound(k, l))
						{
							int k_to_pick = max(abs(kx - k), abs(ky - l));
							for (int m = 0; m < v.size(); ++m)
							{
								int sum_t = 0;
								if (d[v[m].first][v[m].second][k][l] == -1 || d[k][l][i][j] == -1)
									continue;
								sum_t = d[v[m].first][v[m].second][k][l] + d[k][l][i][j] + k_to_pick - d[v[m].first][v[m].second][i][j];
								if (sum_t < min_t)
									min_t = sum_t;
							}
						}
					}
				}
				if (sum + min_t < ans)
					ans = sum + min_t;
			}
		}
		fout << ans << endl;
	}
	else
	{
		fout << 0 << endl;
	}
	return 0;
}
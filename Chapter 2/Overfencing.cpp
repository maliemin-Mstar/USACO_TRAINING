/*
ID: maliemi2
PROG: maze1
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
using namespace std;

ofstream fout ("maze1.out");
ifstream fin ("maze1.in");
int W, H;
char map[400][400];
bool mark[400][400];

struct node
{
	int x, y, step;
};

int bfs(int x, int y)
{
	node start;
	start.x = x;
	start.y = y;
	start.step = 0;
	queue<node> q;
	q.push(start);
	mark[x][y] = 1;
	node now, next;
	while (q.size())
	{
		now = q.front();
		q.pop();
		if (now.x == 0 || now.x == 2 * H + 2 || now.y == 0 || now.y == 2 * W + 2)
			return now.step;
		if (map[now.x - 1][now.y] != '-' && !mark[now.x - 2][now.y])
		{
			next.x = now.x - 2;
			next.y = now.y;
			next.step = now.step + 1;
			mark[next.x][next.y] = 1;
			q.push(next);
		}
		if (map[now.x + 1][now.y] != '-' && !mark[now.x + 2][now.y])
		{
			next.x = now.x + 2;
			next.y = now.y;
			next.step = now.step + 1;
			mark[next.x][next.y] = 1;
			q.push(next);
		}
		if (map[now.x][now.y - 1] != '|' && !mark[now.x][now.y - 2])
		{
			next.x = now.x;
			next.y = now.y - 2;
			next.step = now.step + 1;
			mark[next.x][next.y] = 1;
			q.push(next);
		}
		if (map[now.x][now.y + 1] != '|' && !mark[now.x][now.y + 2])
		{
			next.x = now.x;
			next.y = now.y + 2;
			next.step = now.step + 1;
			mark[next.x][next.y] = 1;
			q.push(next);
		}
	}
}

int main()
{
	fin >> W >> H;
	int i, j;
	memset (map, 0, sizeof(map));
	char temp[400];
	fin.getline(temp, 400);
	for (i = 1; i <= 2 * H + 1; ++i)
	{
		fin.getline(temp, 400);
		for (j = 1; j <= 2 * W + 1; ++j)
		{
			map[i][j] = temp[j - 1];
		}
	}
	int max = -1;
	for (i = 2; i <= 2 * H ; i += 2)
	{
		for (j = 2; j <= 2 * W; j += 2)
		{
			memset (mark, 0, sizeof(mark));
			int t = bfs(i, j);
			if (t > max)
				max = t;
		}
	}
	fout << max << endl;
	return 0;
}
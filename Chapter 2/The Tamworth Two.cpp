/*
ID: maliemi2
PROG: ttwo
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

ofstream fout ("ttwo.out");
ifstream fin ("ttwo.in");
char map[11][11];

struct node
{
	int x, y, dir;
};
node far, cow;

bool ok(int x, int y)
{
	if (x >= 1 && x <= 10 && y >= 1 && y <= 10 && map[x][y] != '*')
		return 1;
	return 0;
}

void walk(node &who)
{
	int tx = who.x, ty = who.y;
	switch (who.dir)
	{
	case 0:
		tx--;
		if (ok(tx, ty))
			who.x = tx;
		else who.dir = 1;
		break;
	case 1:
		ty++;
		if (ok(tx, ty))
			who.y = ty;
		else who.dir = 2;
		break;
	case 2:
		tx++;
		if (ok(tx, ty))
			who.x = tx;
		else who.dir = 3;
		break;
	case 3:
		ty--;
		if (ok(tx, ty))
			who.y = ty;
		else who.dir = 0;
		break;
	default:
		break;
	}
}

int main()
{
	int i, j, time = 0;
	for (i = 1; i <= 10; ++i)
	{
		for (j = 1; j <= 10; ++j)
		{
			fin >> map[i][j];
			if (map[i][j] == 'F')
			{
				far.x = i;
				far.y = j;
				far.dir = 0;
			}
			else if (map[i][j] == 'C')
			{
				cow.x = i;
				cow.y = j;
				cow.dir = 0;
			}
		}
	}
	for (; ; ++time)
	{
		if (time > 1000)
		{
			fout << 0 << endl;
			return 0;
		}
		if (far.x == cow.x && far.y == cow.y)
			break;
		walk(far);
		walk(cow);
	}
	fout << time << endl;
	return 0;
}
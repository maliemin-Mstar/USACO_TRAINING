/*
ID: maliemi2
PROG: fence8
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

ofstream fout ("fence8.out");
ifstream fin ("fence8.in");
int N, R, board[51], rail[1024], v[51], max_waste, rail_sum[1024], curwaste;

bool cmp(int a, int b)
{
	return a > b;
}

bool dfs(int k, int deep, int s)
{
	if (deep == k)
		return 1;
	int waste = 0, ns;
	if (deep != 0 && rail[k - deep - 1] == rail[k - deep])
		ns = s;
	else 
		ns = 0;
	for (int i = ns; i < N; ++i)
	{
		if (v[i] >= rail[k - deep - 1])
		{
			v[i] -= rail[k - deep - 1];
			if (v[i] < rail[0])
			{
				curwaste += v[i];
				if (curwaste > max_waste)
				{
					curwaste -= v[i];
				}
				else
				{
					if (dfs(k, deep + 1, i))
						return 1;
					curwaste -= v[i];
				}
			}
			else if(dfs(k, deep + 1, i))
				return 1;
			v[i] += rail[k - deep - 1];
		}
	}
	return 0;
}

int main()
{
	fin >> N;
	int i, j, max_l = -1, board_sum = 0;
	for (i = 0; i < N; ++i)
	{
		fin >> board[i];
		board_sum += board[i];
		if (board[i] > max_l)
			max_l = board[i];
	}
	fin >> R;
	for (i = 0; i < R; ++i)
	{
		fin >> rail[i];
		if (rail[i] > max_l)
		{
			--i;
			--R;
		}
	}
	sort(board, board + N, cmp);
	sort(rail, rail + R);
	rail_sum[0] = rail[0];
	for (i = 1; i < R; ++i)
	{
		rail_sum[i] = rail_sum[i - 1] + rail[i];
		if (rail_sum[i] > board_sum)
			break;
	}
	R = i;
	int l = 0, r = R, mid, now = 0;
	while (l <= r)
	{
		for (int i = 0; i < N; ++i)
		{
			v[i] = board[i];
		}
		mid = (l + r) / 2;
		max_waste = board_sum - rail_sum[mid - 1];
		curwaste = 0;
		if (dfs(mid, 0, 0))
		{
			l = mid + 1;
			now = mid;
		}
		else 
			r = mid - 1;
	}
	fout << now << endl;
	return 0;
}
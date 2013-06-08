/*
ID: maliemi2
PROG: castle
LANG: C++
*/
#include <iostream>
#include <queue>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SIZE 1010
using namespace std;

ofstream fout ("castle.out");
ifstream fin ("castle.in");
int M, N, map[52][52], neighbor[2510][5], which_group[2510], group_cnt, room_size[2510];

void dfs(int a)
{
	if (which_group[a])
		return;
	which_group[a] = group_cnt;
	for (int i = 1; i <= neighbor[a][0]; ++i)
	{
		dfs(neighbor[a][i]);
	}
}

int main()
{
	memset (room_size, 0, sizeof(room_size));
	memset (which_group, 0, sizeof(which_group));
	memset (neighbor, 0, sizeof(neighbor));
	group_cnt = 0;
	
	fin >> M >> N;
	
	int i, j;
	
	for (i = 1; i <= N; i++)
		for (j = 1; j <= M; j++)
			fin >> map[i][j];
	
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j < M; j++)
		{
			if (!(map[i][j] & 0x04))
			{
				int t = (i - 1) * M + j;
				neighbor[t][++neighbor[t][0]] = t + 1;
			}
		}
	}

	for (i = 1; i <= N; i++)
	{
		for (j = 2; j <= M; j++)
		{
			if (!(map[i][j] & 0x01))
			{
				int t = (i - 1) * M + j;
				neighbor[t][++neighbor[t][0]] = t - 1;
			}
		}
	}

	for (i = 1; i < N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			if (!(map[i][j] & 0x08))
			{
				int t = (i - 1) * M + j;
				neighbor[t][++neighbor[t][0]] = t + M;
			}
		}
	}

	for (i = 2; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			if (!(map[i][j] & 0x02))
			{
				int t = (i - 1) * M + j;
				neighbor[t][++neighbor[t][0]] = t - M;
			}
		}
	}

	for (i = 1; i <= M * N; i++)
	{
		if (!which_group[i])
			group_cnt++;
		dfs(i);
	}

	for (i = 1; i <= M * N; i++)
		room_size[which_group[i]]++;

	int max_room = 1;

	for (i = 1; i <= group_cnt; i++)
	{
		if (room_size[i] > max_room)
			max_room = room_size[i];
	}

	int new_max = 1, new_x, new_y;
	char new_dir;

	for (j = 1; j <= M; j++)
	{
		for (i = N; i > 0; i--)
		{
			int t = (i - 1) * M + j;
			if (i != 1 && (map[i][j] & 0x02) && which_group[t] != which_group[t - M] && room_size[which_group[t]] + room_size[which_group[t - M]] > new_max)
			{
				new_x = i;
				new_y = j;
				new_dir = 'N';
				new_max = room_size[which_group[t]] + room_size[which_group[t - M]];
			}
			if (j != M && (map[i][j] & 0x04) && which_group[t] != which_group[t + 1] && room_size[which_group[t]] + room_size[which_group[t + 1]] > new_max)
			{
				new_x = i;
				new_y = j;
				new_dir = 'E';
				new_max = room_size[which_group[t]] + room_size[which_group[t + 1]];
			}
		}
	}
	fout << group_cnt << endl << max_room << endl << new_max << endl << new_x << ' ' << new_y << ' ' << new_dir << endl;
	return 0;
}
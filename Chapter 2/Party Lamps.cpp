/*
ID: maliemi2
PROG: lamps
LANG: C++
*/
#include <iostream>
#include <queue>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#define SIZE 1010
using namespace std;

ofstream fout ("lamps.out");
ifstream fin ("lamps.in");
bool button[5][101];
int N, C, on[102], off[102], button_cnt[5];
string light, temp;
vector<string> configuration;

void init()
{
	memset(button, 0, sizeof(button));
	int i;
	for (i = 1; i <= N; ++i)
		button[1][i] = 1;
	for (i = 1; i <= N; i += 2)
		button[2][i] = 1;
	for (i = 2; i <= N; i += 2)
		button[3][i] = 1;
	for (i = 1; i <= N; i += 3)
		button[4][i] = 1;
	light = string(N, '1');
}

bool cmp (const string &a, const string &b)
{
	return a < b;
}

void change()
{
	temp = light;
	int i, j;
	for (i = 1; i <= 4; ++i)
	{
		for (j = 1; j <= N; ++j)
		{
			temp[j - 1] = temp[j - 1] + button_cnt[i] * button[i][j];
			temp[j - 1] = (temp[j - 1] - '0') % 2 + '0';
		}
	}
}

bool check()
{
	int i;
	for (i = 1; on[i] != -1; ++i)
	{
		if (temp[on[i] - 1] != '1')
			return 0;
	}
	for (i = 1; off[i] != -1; ++i)
	{
		if (temp[off[i] - 1] != '0')
			return 0;
	}
	return 1;
}

int main()
{
	fin >> N >> C;
	int i, j;
	for (i = 1; fin >> on[i], on[i] != -1; i++);
	for (i = 1; fin >> off[i], off[i] != -1; i++);
	init();
	for (button_cnt[1] = 0; button_cnt[1] < 2; button_cnt[1]++)
	{
		for (button_cnt[2] = 0; button_cnt[2] < 2; button_cnt[2]++)
		{
			for (button_cnt[3] = 0; button_cnt[3] < 2; button_cnt[3]++)
			{
				for (button_cnt[4] = 0; button_cnt[4] < 2; button_cnt[4]++)
				{
					int total = 0;
					for (i = 1; i <= 4; ++i)
						total += button_cnt[i];
					if (total > C || ((total & 1) != (C & 1)))
						continue;
					change();
					if (check())
						configuration.push_back(temp);
				}
			}
		}
	}
	if (!configuration.size())
		fout << "IMPOSSIBLE" << endl;
	else
	{
		sort(configuration.begin(), configuration.end(), cmp);
		for (vector<string>::iterator i = configuration.begin(); i != configuration.end(); ++i)
			fout << *i << endl;
	}
	return 0;
}
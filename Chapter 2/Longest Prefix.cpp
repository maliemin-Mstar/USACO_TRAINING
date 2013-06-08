/*
ID: maliemi2
PROG: prefix
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

ofstream fout ("prefix.out");
ifstream fin ("prefix.in");
string primitives[202], S, temp;
int dp[210002];

bool ok(int s_index, int p_index)
{
	int i, j;
	for (i = s_index, j = 0; i != S.size() && j != primitives[p_index].size(); ++i, ++j)
	{
		if (S[i] != primitives[p_index][j])
			return 0;
	}
	if (j == primitives[p_index].size())
		return 1;
	return 0;
}

int main()
{
	memset(dp, 0, sizeof(dp));
	int i = 0, j;
	while (fin >> primitives[i], primitives[i++][0] != '.');
	while (fin >> temp)
		S += temp;
	for (i = S.size() - 1; i >= 0; --i)
	{
		int max = 0;
		for (j = 0; primitives[j][0] != '.'; ++j)
		{
			if (ok(i, j))
			{
				int t = primitives[j].size() + dp[i + primitives[j].size()];
				if (t > max)
					max = t;
			}
		}
		dp[i] = max;
	}
	fout << dp[0] << endl;
	return 0;
}
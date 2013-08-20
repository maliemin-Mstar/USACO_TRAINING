/*
ID: maliemi2
PROG: shopping
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
using namespace std;

ofstream fout ("shopping.out");
ifstream fin ("shopping.in");

int main()
{
	int offer[100][6], s, dp[6][6][6][6][6], original_price[6], amount[6];
	//dpΪ��i����Ʒ1��j����Ʒ2��k����Ʒ3��l����Ʒ4��m����Ʒ5ʱ�����������ټ۸�
	//分为两种情况 不用任何offer和用一些offer
	memset(offer, 0, sizeof(offer));
	memset(dp, 0, sizeof(dp));
	memset(original_price, 0, sizeof(original_price));
	memset(amount, 0, sizeof(amount));
	map<int, int> mp;
	int i, j, index = 0;
	fin >> s;
	for (i = 0; i < s; ++i)
	{
		int n, c, k, p;
		fin >> n;
		for (j = 0; j < n; ++j)
		{
			fin >> c >> k;
			if (mp.find(c) == mp.end())
			{
				mp[c] = ++index;
			}
			offer[i][mp[c]] = k;
		}
		fin >> p;
		offer[i][0] = p;
	}
	int b;
	fin >> b;
	for (i = 0; i < b; ++i)
	{
		int c, k, p;
		fin >> c >> k >> p;
		if (mp.find(c) == mp.end())
		{
			mp[c] = ++index;
		}
		amount[mp[c]] = k;
		original_price[mp[c]] = p;
	}
	for (i = 0; i <= amount[1]; ++i)
	{
		for (j = 0; j <= amount[2]; ++j)
		{
			for (int k = 0; k <= amount[3]; ++k)
			{
				for (int l = 0; l <= amount[4]; ++l)
				{
					for (int m = 0; m <= amount[5]; ++m)
					{
						//不用任何offer的情况
						dp[i][j][k][l][m] = i * original_price[1] + j * original_price[2] + k * original_price[3] + l * original_price[4] + m * original_price[5];
						//用一些offer的情况  for循环枚举了所有情况(必用一种offer一次)
						for (int n = 0; n < s; ++n)
						{
							//必用第n种offer一次
							if (i >= offer[n][1] && j >= offer[n][2] && k >= offer[n][3] && l >= offer[n][4] && m >= offer[n][5])
							{
								dp[i][j][k][l][m] = min(dp[i][j][k][l][m], dp[i - offer[n][1]][j - offer[n][2]][k - offer[n][3]][l - offer[n][4]][m - offer[n][5]] + offer[n][0]);
							}
						}
					}
				}
			}
		}
	}
	fout << dp[amount[1]][amount[2]][amount[3]][amount[4]][amount[5]] << endl;
	return 0;
}

/*
ID: maliemi2
PROG: buylow
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
#define SIZE 220
#define NHASH 99991
#define MYMAX 1073741823
#define MYMIN -1073741823
using namespace std;

ofstream fout ("buylow.out");
ifstream fin ("buylow.in");
int num[5001], dp[5001], n;
char dp_n[5001][1010];

void add(char a[],char b[],char sum[]){
	int num[1010],i,m=strlen(a),n=strlen(b),aa[1010],bb[1010];
	char a_temp[1010], b_temp[1010];
	memset(num,0,sizeof(num));
	memset(aa,0,sizeof(aa));
	memset(bb,0,sizeof(bb));
	//strrev(a);strrev(b);
	memcpy(a_temp, a, 1010);
	memcpy(b_temp, b, 1010);
	for (i = 0; a_temp[i]; ++i)
		a[i] = a_temp[strlen(a_temp) - i - 1];
	for (i = 0; b_temp[i]; ++i)
		b[i] = b_temp[strlen(b_temp) - i - 1];
	for(i=0;i<m;i++){
		aa[i]=a[i]-'0';
	}
	for(i=0;i<n;i++){
		bb[i]=b[i]-'0';
	}
	if(m<n)m=n;
	for(i=0;i<m;i++){
		num[i]=aa[i]+bb[i]+num[i];
		if(num[i]>9){num[i]-=10;num[i+1]=1;}
	}
	if(num[m]==1)m++;
	for(i=0;i<m;i++){
		sum[i]=num[m-i-1]+'0';
	}
	sum[m]='\0';
	memcpy(a_temp, a, 1010);
	memcpy(b_temp, b, 1010);
	for (i = 0; a_temp[i]; ++i)
		a[i] = a_temp[strlen(a_temp) - i - 1];
	for (i = 0; b_temp[i]; ++i)
		b[i] = b_temp[strlen(b_temp) - i - 1];
	//strrev(a);strrev(b);
}

int main()
{
	int i, j;
	fin >> n;
	for (i = 0; i < n; ++i)
	{
		fin >> num[i];
	}
	for (i = 0; i < n; ++i)
	{
		int max_pre = 0;
		for (j = 0; j < i; ++j)
		{
			if (num[j] > num[i] && dp[j] > max_pre)
				max_pre = dp[j];
		}
		dp[i] = max_pre + 1;
		if (dp[i] == 1)
		{
			dp_n[i][0] = '1';
			dp_n[i][1] = '\0';
		}
		else
		{
			set<int> st;
			for (j = i - 1; j >= 0; --j)                 //从后往前 遇到的第一个必定是最大的
			{
				if (num[j] > num[i] && dp[j] == dp[i] - 1)
				{
					if (st.find(num[j]) == st.end())
					{
						st.insert(num[j]);
						char temp[1010];
						add(dp_n[i], dp_n[j], temp);
						memcpy(dp_n[i], temp, 1010);
					}
				}
			}
		}
	}
	int max_l = 1;
	char cnt[1010] = {'0'};
	for (i = 0; i < n; ++i)
	{
		if (dp[i] > max_l)
			max_l = dp[i];
	}
	set<int> st;
	for (i = n - 1; i >= 0; --i)       //同理
	{
		if (dp[i] == max_l)
		{
			if (st.find(num[i]) == st.end())
			{
				st.insert(num[i]);
				char temp[1010];
				add(cnt, dp_n[i], temp);
				memcpy(cnt, temp, 1010);
			}
		}
	}
	fout << max_l << ' ' << cnt << endl;
	return 0;
}
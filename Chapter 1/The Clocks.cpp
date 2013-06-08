/*
ID: maliemi2
PROG: clocks
LANG: C++
*/
#include<iostream>
#include<queue>
#include <fstream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define SIZE 22
using namespace std;

int times[10], myclock[10], min_t, ans[100];
int change[10][10] = 
{
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 1, 0, 1, 1, 0, 0, 0, 0},
	{0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
	{0, 0, 1, 1, 0, 1, 1, 0, 0, 0},
	{0, 1, 0, 0, 1, 0, 0, 1, 0, 0},
	{0, 0, 1, 0, 1, 1, 1, 0, 1, 0},
	{0, 0, 0, 1, 0, 0, 1, 0, 0, 1},
	{0, 0, 0, 0, 1, 1, 0, 1, 1, 0},
	{0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
	{0, 0, 0, 0, 0, 1, 1, 0, 1, 1}
};

void copy(int a[])
{
	for (int i = 1; i < 10; i++)
		a[i] = myclock[i];
}

void turn(int a[])
{
	for (int i = 1; i < 10; i++)
	{
		if(!times[i])
			continue;
		for (int j = 1; j < 10; j++)
		{
			a[j] += times[i] * change[i][j];
		}
	}
	for (int i = 1; i < 10; i++)
	{
		a[i] %= 4;
	}
}

int total()
{
	int sum = 0;
	for (int i = 1; i < 10; i++)
		sum += times[i];
	return sum;
}

bool finish(int a[])
{
	for (int i = 1; i < 10; i++)
	{
		if(a[i] != 3)
			return 0;
	}
	return 1;
}

void write()
{
	int k = 0;
	for (int i = 1; i < 10; i++)
	{
		if (times[i])
		{
			for (int j = 0; j < times[i]; j++)
				ans[k++] = i;
		}
	}
}

int main()
{
    ofstream fout ("clocks.out");
    ifstream fin ("clocks.in");
	int i, j;
	min_t = 100;
	for (i = 1; i < 10; i++)
	{
		fin >> myclock[i];
		myclock[i] /= 3;
		myclock[i]--;
	}
	for (times[9] = 0; times[9] < 4; times[9]++)
	{
		for (times[8] = 0; times[8] < 4; times[8]++)
		{
			for (times[7] = 0; times[7] < 4; times[7]++)
			{
				for (times[6] = 0; times[6] < 4; times[6]++)
				{
					for (times[5] = 0; times[5] < 4; times[5]++)
					{
						for (times[4] = 0; times[4] < 4; times[4]++)
						{
							for (times[3] = 0; times[3] < 4; times[3]++)
							{
								for (times[2] = 0; times[2] < 4; times[2]++)
								{
									for (times[1] = 0; times[1] < 4; times[1]++)
									{
										int temp[10];
										copy(temp);
										turn(temp);
										if(finish(temp))
										{
											int t;
											t = total();
											if (t < min_t)
											{
												min_t = t;
												write();
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for (i = 0; i < min_t - 1; i++)
		fout << ans[i] << ' ';
	fout << ans[i] << endl;
	return 0;
}
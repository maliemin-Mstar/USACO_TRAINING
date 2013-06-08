/*------------------
13个for。。
先对角线
prime要打表  草。。就是因为这个才超时的- -
------------------/*
ID: maliemi2
PROG: prime3
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

ofstream fout ("prime3.out");
ifstream fin ("prime3.in");
int sum, first;
vector<int> matrix(25, 0);
vector<vector<int> > ans;
bool prime[100000];

bool is_prime(int x)
{
	for (int i = 2; i <= sqrt(x); ++i)
	{
		if (x % i == 0)
			return 0;
	}
	return 1;
}

int get_num(int id4, int id3, int id2, int id1, int id0)//高到低
{
	return matrix[id4] * 10000 + matrix[id3] * 1000 + matrix[id2] * 100 + matrix[id1] * 10 + matrix[id0];
}

int main()
{
	fin >> sum >> first;
	matrix[0] = first;
	int i0, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i, j;
	for (i = 10001; i < 100000; i += 2)
	{
		if (is_prime(i))
			prime[i] = 1;
	}
	int s_dia0 = first;
	for (i0 = 0; i0 < 10 && i0 + s_dia0 < sum; ++i0)
	{
		s_dia0 += i0;
		matrix[6] = i0;
		for (i1 = 0; i1 < 10 && i1 + s_dia0 < sum; ++i1)
		{
			s_dia0 += i1;
			matrix[12] = i1;
			for (i2 = 0; i2 < 10 && i2 + s_dia0 < sum; ++i2)
			{
				s_dia0 += i2;
				matrix[18] = i2;
				matrix[24] = sum - s_dia0;
				if (matrix[24] > 9)
				{
					s_dia0 -= i2;
					continue;
				}
				if ((matrix[24] & 1 == 1) && matrix[24] != 5 && prime[get_num(0, 6, 12, 18, 24)])
				{
					int s_dia1 = matrix[12];
					for (i3 = 1; i3 < 10 && i3 + s_dia1 < sum; i3 += 2)
					{
						if (i3 == 5)
							continue;
						if (i3 + matrix[24] + 3 > sum || i3 + matrix[0] + 3 > sum)
							break;
						s_dia1 += i3;
						matrix[20] = i3;
						for (i4 = 0; i4 < 10 && i4 + s_dia1 < sum; ++i4)
						{
							if (i4 + matrix[18] + 2 > sum || i4 + matrix[6] + 2 > sum)
								break;
							s_dia1 += i4;
							matrix[16] = i4;
							for (i5 = 0; i5 < 10 && i5 + s_dia1 < sum; ++i5)
							{
								if (i5 + matrix[18] + 2 > sum || i5 + matrix[6] + 2 > sum)
									break;
								s_dia1 += i5;
								matrix[8] = i5;
								matrix[4] = sum - s_dia1;
								if (matrix[4] > 9 || matrix[4] + matrix[0] + 3 > sum || matrix[4] + matrix[24] + 3 > sum)
								{
									s_dia1 -= i5;
									continue;
								}
								if ((matrix[4] & 1 == 1) && matrix[4] != 5 && prime[get_num(20, 16, 12, 8, 4)])
								{
									int s_row2 = matrix[12];
									for (i6 = 1; i6 < 10 && i6 + s_row2 < sum; ++i6)
									{
										if (i6 + matrix[0] + matrix[20] + 2 > sum)
											break;
										s_row2 += i6;
										matrix[10] = i6;
										for (i7 = 0; i7 < 10 && i7 + s_row2 < sum; ++i7)
										{
											if (i7 + matrix[6] + matrix[16] + 2 > sum)
												break;
											s_row2 += i7;
											matrix[11] = i7;
											for (i8 = 0; i8 < 10 && i8 + s_row2 < sum; ++i8)
											{
												if (i8 + matrix[8] + matrix[18] + 2 > sum)
													break;
												s_row2 += i8;
												matrix[13] = i8;
												matrix[14] = sum - s_row2;
												if (matrix[14] > 9 || matrix[14] + matrix[4] + matrix[24] + 2 > sum)
												{
													s_row2 -= i8;
													continue;
												}
												if ((matrix[14] & 1 == 1) && matrix[14] != 5 && prime[get_num(10, 11, 12, 13, 14)])
												{
													int s_col0 = matrix[0] + matrix[10] + matrix[20];
													for (i9 = 1; i9 < 10 && i9 + s_col0 < sum; ++i9)
													{
														if (i9 + matrix[6] + matrix[8] + 1 > sum)
															break;
														s_col0 += i9;
														matrix[5] = i9;
														matrix[15] = sum - s_col0;
														if (matrix[15] > 9 || matrix[15] + matrix[16] + matrix[18] + 1 > sum)
														{
															s_col0 -= i9;
															continue;
														}
														if (prime[get_num(0, 5, 10, 15, 20)])
														{
															int s_col4 = matrix[4] + matrix[14] + matrix[24];
															for (i10 = 1; i10 < 10 && i10 + s_col4 < sum; i10 += 2)
															{
																if (i10 + matrix[5] + matrix[6] + matrix[8] > sum)
																	break;
																if (i10 == 5)
																	continue;
																s_col4 += i10;
																matrix[9] = i10;
																matrix[19] = sum - s_col4;
																if (matrix[19] > 9 || matrix[19] + matrix[15] + matrix[16] + matrix[18] > sum)
																{
																	s_col4 -= i10;
																	continue;
																}
																if ((matrix[19] & 1 == 1) && matrix[19] != 5 && prime[get_num(4, 9, 14, 19, 24)])
																{
																	int t = sum - matrix[5] - matrix[6] - matrix[8] - matrix[9];
																	if (t < 10 && t > -1)
																	{
																		matrix[7] = t;
																		if (prime[get_num(5, 6, 7, 8, 9)])
																		{
																			int t = sum - matrix[15] - matrix[16] - matrix[18] - matrix[19];
																			if (t < 10 && t > -1)
																			{
																				matrix[17] = t;
																				if (prime[get_num(15, 16, 17, 18, 19)])
																				{
																					int s_col1 = matrix[6] + matrix[11] + matrix[16];
																					for (i11 = 1; i11 < 10 && i11 + s_col1 < sum; i11 += 2)
																					{
																						if (i11 == 5)
																							continue;
																						s_col1 += i11;
																						matrix[21] = i11;
																						matrix[1] = sum - s_col1;
																						if (matrix[1] > 9)
																						{
																							s_col1 -= i11;
																							continue;
																						}
																						if (prime[get_num(1, 6, 11, 16, 21)])
																						{
																							int s_row4 = matrix[20] + matrix[21] + matrix[24];
																							int s_col2 = matrix[7] + matrix[12] + matrix[17];
																							for (i12 = 1; i12 < 10 && i12 + s_row4 < sum && i12 + s_col2 < sum; i12 += 2)
																							{
																								if (i12 == 5)
																									continue;
																								s_row4 += i12;
																								s_col2 += i12;
																								matrix[22] = i12;
																								matrix[23] = sum - s_row4;
																								if (matrix[23] > 9)
																								{
																									s_row4 -= i12;
																									s_col2 -= i12;
																									continue;
																								}
																								matrix[2] = sum - s_col2;
																								if (matrix[2] > 9)
																								{
																									s_row4 -= i12;
																									s_col2 -= i12;
																									continue;
																								}
																								if (prime[get_num(20, 21, 22, 23, 24)] && prime[get_num(2, 7, 12, 17, 22)])
																								{
																									int t = sum - matrix[0] - matrix[1] - matrix[2] - matrix[4];
																									if (t > 0 && t < 10)
																									{
																										matrix[3] = t;
																										if (prime[get_num(0, 1, 2, 3, 4)])
																										{
																											if (matrix[3] + matrix[8] + matrix[13] + matrix[18] + matrix[23] == sum && prime[get_num(3, 8, 13, 18, 23)])
																											{
																												ans.push_back(matrix);
																											}
																										}
																									}
																								}
																								s_row4 -= i12;
																								s_col2 -= i12;
																							}
																						}
																						s_col1 -= i11;
																					}
																				}
																			}
																		}
																	}
																}
																s_col4 -= i10;
															}
														}
														s_col0 -= i9;
													}
												}
												s_row2 -= i8;
											}
											s_row2 -= i7;
										}
										s_row2 -= i6;
									}
								}
								s_dia1 -= i5;
							}
							s_dia1 -= i4;
						}
						s_dia1 -= i3;
					}
				}
				s_dia0 -= i2;
			}
			s_dia0 -= i1;
		}
		s_dia0 -= i0;
	}
	sort(ans.begin(), ans.end());
	for (i = 0; i < ans.size() - 1; ++i)
	{
		for (int j = 0; j < 25; ++j)
		{
			fout << ans[i][j];
			if ((j + 1) % 5 == 0)
				fout << endl;
		}
		fout << endl;
	}
	for (int j = 0; j < 25; ++j)
	{
		fout << ans[i][j];
		if ((j + 1) % 5 == 0)
			fout << endl;
	}
	return 0;
}
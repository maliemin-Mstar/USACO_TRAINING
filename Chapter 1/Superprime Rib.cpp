/*
ID: maliemi2
PROG: sprime
LANG: C++
*/
#include<iostream>
#include <queue>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define SIZE 22
using namespace std;

int len;

bool is_prime(int x)
{
	if (x == 1)
		return 0;
	int i;
	for (i = 2; i <= (int)sqrt(x); i++)
	{
		if (x % i == 0)
			return 0;
	}
	return 1;
}

int main()
{
	ofstream fout ("sprime.out");
	ifstream fin ("sprime.in");
	fin >> len;
	int i, j, k, l, m, n, o, p, num, I, J, K, L, M, N, O, P;
	if (len == 4)
	{
		for (num = 2, i = 1; i < 10; i += 2)
		{
			I = num * 10 + i;
			if (is_prime(I))
			{
				for (j = 1; j < 10; j += 2)
				{
					J = I * 10 + j;
					if (is_prime(J))
					{
						for (k = 1; k < 10; k += 2)
						{
							K = J * 10 + k;
							if(is_prime(K))
								fout << K << endl;
						}
					}
				}
			}
		}
		for (num = 3, i = 1; i < 10; i += 2)
		{
			I = num * 10 + i;
			if (is_prime(I))
			{
				for (j = 1; j < 10; j += 2)
				{
					J = I * 10 + j;
					if (is_prime(J))
					{
						for (k = 1; k < 10; k += 2)
						{
							K = J * 10 + k;
							if(is_prime(K))
								fout << K << endl;
						}
					}
				}
			}
		}
		for (num = 5, i = 1; i < 10; i += 2)
		{
			I = num * 10 + i;
			if (is_prime(I))
			{
				for (j = 1; j < 10; j += 2)
				{
					J = I * 10 + j;
					if (is_prime(J))
					{
						for (k = 1; k < 10; k += 2)
						{
							K = J * 10 + k;
							if(is_prime(K))
								fout << K << endl;
						}
					}
				}
			}
		}
		for (num = 7, i = 1; i < 10; i += 2)
		{
			I = num * 10 + i;
			if (is_prime(I))
			{
				for (j = 1; j < 10; j += 2)
				{
					J = I * 10 + j;
					if (is_prime(J))
					{
						for (k = 1; k < 10; k += 2)
						{
							K = J * 10 + k;
							if(is_prime(K))
								fout << K << endl;
						}
					}
				}
			}
		}
	}
	if (len == 5)
	{
		for (num = 2, i = 1; i < 10; i += 2)
		{
			I = num * 10 + i;
			if (is_prime(I))
			{
				for (j = 1; j < 10; j += 2)
				{
					J = I * 10 + j;
					if (is_prime(J))
					{
						for (k = 1; k < 10; k += 2)
						{
							K = J * 10 + k;
							if(is_prime(K))
							{
								for (l = 1; l < 10; l += 2)
								{
									L = K * 10 + l;
									if (is_prime(L))
										fout << L << endl;
								}
							}
						}
					}
				}
			}
		}
		for (num = 3, i = 1; i < 10; i += 2)
		{
			I = num * 10 + i;
			if (is_prime(I))
			{
				for (j = 1; j < 10; j += 2)
				{
					J = I * 10 + j;
					if (is_prime(J))
					{
						for (k = 1; k < 10; k += 2)
						{
							K = J * 10 + k;
							if(is_prime(K))
							{
								for (l = 1; l < 10; l += 2)
								{
									L = K * 10 + l;
									if (is_prime(L))
										fout << L << endl;
								}
							}
						}
					}
				}
			}
		}
		for (num = 5, i = 1; i < 10; i += 2)
		{
			I = num * 10 + i;
			if (is_prime(I))
			{
				for (j = 1; j < 10; j += 2)
				{
					J = I * 10 + j;
					if (is_prime(J))
					{
						for (k = 1; k < 10; k += 2)
						{
							K = J * 10 + k;
							if(is_prime(K))
							{
								for (l = 1; l < 10; l += 2)
								{
									L = K * 10 + l;
									if (is_prime(L))
										fout << L << endl;
								}
							}
						}
					}
				}
			}
		}
		for (num = 7, i = 1; i < 10; i += 2)
		{
			I = num * 10 + i;
			if (is_prime(I))
			{
				for (j = 1; j < 10; j += 2)
				{
					J = I * 10 + j;
					if (is_prime(J))
					{
						for (k = 1; k < 10; k += 2)
						{
							K = J * 10 + k;
							if(is_prime(K))
							{
								for (l = 1; l < 10; l += 2)
								{
									L = K * 10 + l;
									if (is_prime(L))
										fout << L << endl;
								}
							}
						}
					}
				}
			}
		}
	}
	if (len == 6)
	{
		for (num = 2, i = 1; i < 10; i += 2)
		{
			I = num * 10 + i;
			if (is_prime(I))
			{
				for (j = 1; j < 10; j += 2)
				{
					J = I * 10 + j;
					if (is_prime(J))
					{
						for (k = 1; k < 10; k += 2)
						{
							K = J * 10 + k;
							if(is_prime(K))
							{
								for (l = 1; l < 10; l += 2)
								{
									L = K * 10 + l;
									if (is_prime(L))
									{
										for (m = 1; m < 10; m += 2)
										{
											M = L * 10 + m;
											if (is_prime(M))
												fout << M << endl;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		for (num = 3, i = 1; i < 10; i += 2)
		{
			I = num * 10 + i;
			if (is_prime(I))
			{
				for (j = 1; j < 10; j += 2)
				{
					J = I * 10 + j;
					if (is_prime(J))
					{
						for (k = 1; k < 10; k += 2)
						{
							K = J * 10 + k;
							if(is_prime(K))
							{
								for (l = 1; l < 10; l += 2)
								{
									L = K * 10 + l;
									if (is_prime(L))
									{
										for (m = 1; m < 10; m += 2)
										{
											M = L * 10 + m;
											if (is_prime(M))
												fout << M << endl;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		for (num = 5, i = 1; i < 10; i += 2)
		{
			I = num * 10 + i;
			if (is_prime(I))
			{
				for (j = 1; j < 10; j += 2)
				{
					J = I * 10 + j;
					if (is_prime(J))
					{
						for (k = 1; k < 10; k += 2)
						{
							K = J * 10 + k;
							if(is_prime(K))
							{
								for (l = 1; l < 10; l += 2)
								{
									L = K * 10 + l;
									if (is_prime(L))
									{
										for (m = 1; m < 10; m += 2)
										{
											M = L * 10 + m;
											if (is_prime(M))
												fout << M << endl;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		for (num = 7, i = 1; i < 10; i += 2)
		{
			I = num * 10 + i;
			if (is_prime(I))
			{
				for (j = 1; j < 10; j += 2)
				{
					J = I * 10 + j;
					if (is_prime(J))
					{
						for (k = 1; k < 10; k += 2)
						{
							K = J * 10 + k;
							if(is_prime(K))
							{
								for (l = 1; l < 10; l += 2)
								{
									L = K * 10 + l;
									if (is_prime(L))
									{
										for (m = 1; m < 10; m += 2)
										{
											M = L * 10 + m;
											if (is_prime(M))
												fout << M << endl;
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
	if (len == 7)
	{
		for (num = 2, i = 1; i < 10; i += 2)
		{
			I = num * 10 + i;
			if (is_prime(I))
			{
				for (j = 1; j < 10; j += 2)
				{
					J = I * 10 + j;
					if (is_prime(J))
					{
						for (k = 1; k < 10; k += 2)
						{
							K = J * 10 + k;
							if(is_prime(K))
							{
								for (l = 1; l < 10; l += 2)
								{
									L = K * 10 + l;
									if (is_prime(L))
									{
										for (m = 1; m < 10; m += 2)
										{
											M = L * 10 + m;
											if (is_prime(M))
											{
												for (n = 1; n < 10; n += 2)
												{
													N = M * 10 + n;
													if (is_prime(N))
														fout << N << endl;
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
		for (num = 3, i = 1; i < 10; i += 2)
		{
			I = num * 10 + i;
			if (is_prime(I))
			{
				for (j = 1; j < 10; j += 2)
				{
					J = I * 10 + j;
					if (is_prime(J))
					{
						for (k = 1; k < 10; k += 2)
						{
							K = J * 10 + k;
							if(is_prime(K))
							{
								for (l = 1; l < 10; l += 2)
								{
									L = K * 10 + l;
									if (is_prime(L))
									{
										for (m = 1; m < 10; m += 2)
										{
											M = L * 10 + m;
											if (is_prime(M))
											{
												for (n = 1; n < 10; n += 2)
												{
													N = M * 10 + n;
													if (is_prime(N))
														fout << N << endl;
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
		for (num = 5, i = 1; i < 10; i += 2)
		{
			I = num * 10 + i;
			if (is_prime(I))
			{
				for (j = 1; j < 10; j += 2)
				{
					J = I * 10 + j;
					if (is_prime(J))
					{
						for (k = 1; k < 10; k += 2)
						{
							K = J * 10 + k;
							if(is_prime(K))
							{
								for (l = 1; l < 10; l += 2)
								{
									L = K * 10 + l;
									if (is_prime(L))
									{
										for (m = 1; m < 10; m += 2)
										{
											M = L * 10 + m;
											if (is_prime(M))
											{
												for (n = 1; n < 10; n += 2)
												{
													N = M * 10 + n;
													if (is_prime(N))
														fout << N << endl;
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
		for (num = 7, i = 1; i < 10; i += 2)
		{
			I = num * 10 + i;
			if (is_prime(I))
			{
				for (j = 1; j < 10; j += 2)
				{
					J = I * 10 + j;
					if (is_prime(J))
					{
						for (k = 1; k < 10; k += 2)
						{
							K = J * 10 + k;
							if(is_prime(K))
							{
								for (l = 1; l < 10; l += 2)
								{
									L = K * 10 + l;
									if (is_prime(L))
									{
										for (m = 1; m < 10; m += 2)
										{
											M = L * 10 + m;
											if (is_prime(M))
											{
												for (n = 1; n < 10; n += 2)
												{
													N = M * 10 + n;
													if (is_prime(N))
														fout << N << endl;
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
	}
	if (len == 8)
	{
		for (num = 2, i = 1; i < 10; i += 2)
		{
			I = num * 10 + i;
			if (is_prime(I))
			{
				for (j = 1; j < 10; j += 2)
				{
					J = I * 10 + j;
					if (is_prime(J))
					{
						for (k = 1; k < 10; k += 2)
						{
							K = J * 10 + k;
							if(is_prime(K))
							{
								for (l = 1; l < 10; l += 2)
								{
									L = K * 10 + l;
									if (is_prime(L))
									{
										for (m = 1; m < 10; m += 2)
										{
											M = L * 10 + m;
											if (is_prime(M))
											{
												for (n = 1; n < 10; n += 2)
												{
													N = M * 10 + n;
													if (is_prime(N))
													{
														for (o = 1; o < 10; o += 2)
														{
															O = N * 10 + o;
															if (is_prime(O))
																fout << O << endl;
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
			}
		}
		for (num = 3, i = 1; i < 10; i += 2)
		{
			I = num * 10 + i;
			if (is_prime(I))
			{
				for (j = 1; j < 10; j += 2)
				{
					J = I * 10 + j;
					if (is_prime(J))
					{
						for (k = 1; k < 10; k += 2)
						{
							K = J * 10 + k;
							if(is_prime(K))
							{
								for (l = 1; l < 10; l += 2)
								{
									L = K * 10 + l;
									if (is_prime(L))
									{
										for (m = 1; m < 10; m += 2)
										{
											M = L * 10 + m;
											if (is_prime(M))
											{
												for (n = 1; n < 10; n += 2)
												{
													N = M * 10 + n;
													if (is_prime(N))
													{
														for (o = 1; o < 10; o += 2)
														{
															O = N * 10 + o;
															if (is_prime(O))
																fout << O << endl;
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
			}
		}
		for (num = 5, i = 1; i < 10; i += 2)
		{
			I = num * 10 + i;
			if (is_prime(I))
			{
				for (j = 1; j < 10; j += 2)
				{
					J = I * 10 + j;
					if (is_prime(J))
					{
						for (k = 1; k < 10; k += 2)
						{
							K = J * 10 + k;
							if(is_prime(K))
							{
								for (l = 1; l < 10; l += 2)
								{
									L = K * 10 + l;
									if (is_prime(L))
									{
										for (m = 1; m < 10; m += 2)
										{
											M = L * 10 + m;
											if (is_prime(M))
											{
												for (n = 1; n < 10; n += 2)
												{
													N = M * 10 + n;
													if (is_prime(N))
													{
														for (o = 1; o < 10; o += 2)
														{
															O = N * 10 + o;
															if (is_prime(O))
																fout << O << endl;
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
			}
		}
		for (num = 7, i = 1; i < 10; i += 2)
		{
			I = num * 10 + i;
			if (is_prime(I))
			{
				for (j = 1; j < 10; j += 2)
				{
					J = I * 10 + j;
					if (is_prime(J))
					{
						for (k = 1; k < 10; k += 2)
						{
							K = J * 10 + k;
							if(is_prime(K))
							{
								for (l = 1; l < 10; l += 2)
								{
									L = K * 10 + l;
									if (is_prime(L))
									{
										for (m = 1; m < 10; m += 2)
										{
											M = L * 10 + m;
											if (is_prime(M))
											{
												for (n = 1; n < 10; n += 2)
												{
													N = M * 10 + n;
													if (is_prime(N))
													{
														for (o = 1; o < 10; o += 2)
														{
															O = N * 10 + o;
															if (is_prime(O))
																fout << O << endl;
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
			}
		}
	}
	return 0;
}
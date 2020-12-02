#pragma once

#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

long double const C[2] = { 12.000000000, 13.0033548350723 };
long double const C_IC[2] = { 0.98938, 0.01078 };
long double const H[2] = { 1.007825032239 , 2.0141017781212 };
long double const H_IC[2] = { 0.99988570 , 0.00011570 };
long double const O[2] = { 15.9949146195717 , 17.9991596128676 };
long double const O_IC[2] = { 0.9975716 , 0.0020514 };
long double const N[2] = { 14.0030740044320 , 15.0001088988864 };
long double const N_IC[2] = { 0.9963620 , 0.0036420 };
long double const P = 30.9737619984270;
long double const Au = 196.9665687971;
long double const Ag[2] = { 106.905091626 , 108.904755314 };
long double const Ag_IC[2] = { 0.518398 , 0.481618 };
long double const B[2] = { 10.0129369541 , 11.0093053645 };
long double const B_IC[2] = { 0.1997 , 0.8017 };
long double const F = 18.9984031627392;
long double const Cl[2] = { 34.96885268237 , 36.96590260255 };
long double const Cl_SI[2] = { 0.757610 , 0.242410 };
long double const Bi = 208.980399116;
long double const Cu[2] = {62.9295977256, 64.9277897071};
long double const Cu_SI[2] = {0.691515, 0.308515};
long double const Si[2] = { 27.9769265346544 , 28.97649466490 };
long double const Si_SI[2] = { 0.9222319 , 0.04685 };


int comb(int n, int k)
{
	if (n == k || k == 0)
	{
		return 1;
	}
	else
	{
		return comb(n - 1, k) + comb(n - 1, k - 1);
	}
}

long double GetMaxMw(long double const Mw[], long double const SI[], int n)
{
	if (n == 0)
	{
		return 0.000000000000000;
	}
	long double data[10000];
	for (int i = 0; i < n + 1; i++)
	{
		data[i] = pow(SI[0], n - i) * pow(SI[1], i) * comb(n, i);
		if (((pow(SI[0],n-i-1)*pow(SI[1],i+1)* comb(n, i+1))<(pow(SI[0],n-i)*pow(SI[1], i)* comb(n,i))) && (i<n))
		{
			data[i + 1] = 0;
			break;
		}
	}
	for (int i = 0; i < n + 1; i++)
	{
		if ((data[i + 1] < data[i]) && (i<n))
		{
			return (n - i) * Mw[0]+i * Mw[1];
		}
		else if (i == n)
		{
			return n * Mw[1];
		}
	}
}

bool cp_decimal(long double value1, long double value2, int n)
{
	long double result;
	result = (fabs(value1-value2))*pow(10, n);
	return (result < 1);
}
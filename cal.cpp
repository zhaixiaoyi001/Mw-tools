#include"Binomial_correction.h"
#include<fstream>


long double elec = 0.0005484;
long double Mw;
int decimal_n;


long double C_cal = 0.00000000000;
long double H_cal = 0.00000000000;
long double O_cal = 0.00000000000;
long double N_cal = 0.00000000000;
long double P_cal = 0.00000000000;
long double Au_cal = 0.00000000000;
long double Ag_cal = 0.00000000000;
long double B_cal = 0.00000000000;
long double F_cal = 0.00000000000;
long double Cl_cal = 0.00000000000;
long double Bi_cal = 0.00000000000;
long double Cu_cal = 0.00000000000;
long double Si_cal = 0.00000000000;

int C_max = 0;
int H_max = 0;
int O_max = 0;
int N_max = 0;
int P_max = 0;
int Au_max = 0;
int Ag_max = 0;
int B_max = 0;
int F_max = 0;
int Cl_max = 0;
int Bi_max = 0;
int Cu_max = 0;
int Si_max = 0;

int C_min = 0;
int H_min = 0;
int O_min = 0;
int N_min = 0;
int P_min = 0;
int Au_min = 0;
int Ag_min = 0;
int B_min = 0;
int F_min = 0;
int Cl_min = 0;
int Bi_min = 0;
int Cu_min = 0;
int Si_min = 0;

ofstream result_txt("result.txt");

int main()
{
	cout << "请分别输入C H O N P Au Ag B F Cl Bi Cu Si 最大原子数"<<endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	cin >> C_max >> H_max >> O_max >> N_max >> P_max >> Au_max >> Ag_max >> B_max >> F_max >> Cl_max >> Bi_max >> Cu_max >> Si_max;
	C_max++;
	H_max++;
	O_max++;
	N_max++;
	P_max++;
	Au_max++;
	Ag_max++;
	B_max++;
	F_max++;
	Cl_max++;
	Bi_max++;
	Cu_max++;
	Si_max++;
	cout << "请分别输入C H O N P Au Ag B F Cl Bi Cu Si最小原子数" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	cin >> C_min >> H_min >> O_min >> N_min >> P_min >> Au_min >> Ag_min >> B_min >> F_min >> Cl_min >> Bi_min >> Cu_min >> Si_min;
	cout << "请输入待枚举最高丰度质谱峰分子量" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	cin >> Mw;
	cout << "请输入精确小数位数" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	cin >> decimal_n;
	for (int a = C_min; a < C_max; a++)
	{
		cout << "枚举C原子数为" << a << "的分子式" << endl;
		cout << "-------------------------------------------------------------------------------" << endl;
		C_cal = GetMaxMw(C, C_IC, a);
		for (int b = H_min; b < H_max; b++)
		{
			H_cal = GetMaxMw(H, H_IC, b);
			for (int c = O_min; c < O_max; c++)
			{
				O_cal = GetMaxMw(O, O_IC, c);
				for (int d = N_min; d < N_max; d++)
				{
					N_cal = GetMaxMw(N, N_IC, d);
					for (int e = P_min; e < P_max; e++)
					{
						P_cal = P * e;
						for (int f = Au_min; f < Au_max; f++)
						{
							Au_cal = Au * f;
							for (int g = Ag_min; g < Ag_max; g++)
							{
								Ag_cal = GetMaxMw(Ag, Ag_IC, g);
								for (int h = B_min; h < B_max; h++)
								{
									B_cal = GetMaxMw(B, B_IC, h);
									for (int i = F_min; i < F_max; i++)
									{
										F_cal = F * i;
										for (int j = Cl_min; j < Cl_max; j++)
										{
											Cl_cal = GetMaxMw(Cl, Cl_SI, j);
											for (int k = Bi_min; k < Bi_max; k++)
											{
												Bi_cal = Bi * k;
												for (int l = Cu_min; l < Cu_max; l++)
												{
													Cu_cal = GetMaxMw(Cu, Cu_SI, l);
													for (int m = Si_min; m < Si_max; m++)
													{
														Si_cal = GetMaxMw(Si, Si_SI, m);
														if (b > 2 * a + 2)
														{
															continue;
														}
														long double sum = C_cal + H_cal + O_cal + N_cal + P_cal + Au_cal + Ag_cal + B_cal + F_cal + Cl_cal + Bi_cal + Cu_cal + Si_cal - elec;
														if (cp_decimal(sum,Mw,decimal_n))
														{
															cout << "C" << a << " H" << b << " O" << c << " N" << d << " P" << e << " Au" << f << " Ag" << g << " B" << h << " Cl" << j << " Bi" << k << " Cu" << l << " Si" << m << endl;
															result_txt << a << " " << b << " " << c << " " << d << " " << e << " " << f << " " << g << " " << h << " " << i << " " << j << " " << k << " " << l << " " << m << endl;
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
	result_txt.close();
	return 0;
}
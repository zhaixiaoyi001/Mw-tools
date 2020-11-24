from Binomial_correction import *


elec = Decimal(0.0005484)
Mw = Decimal(3353.45)

C_cal = Decimal(0.00000000000)
H_cal = Decimal(0.00000000000)
O_cal = Decimal(0.00000000000)
N_cal = Decimal(0.00000000000)
P_cal = Decimal(0.00000000000)
Au_cal = Decimal(0.00000000000)
Ag_cal = Decimal(0.00000000000)
B_cal = Decimal(0.00000000000)
F_cal = Decimal(0.00000000000)
Cl_cal = Decimal(0.00000000000)
Bi_cal = Decimal(0.00000000000)

C_flag = 110
H_flag = 100
O_flag = 6
N_flag = 3
P_flag = 11
Au_flag = 10
Ag_flag = 1
B_flag = 15
F_flag = 15
Cl_flag = 15
Bi_flag = 2
times = 0

save = open('result.txt', 'w')


for a in range(96, C_flag):
    print("Searching for C:", a, "\n ----------------------------------")
    C_cal = GetMaxMw(C, C_IC, a)
    for b in range(72, H_flag):
        H_cal = GetMaxMw(H, H_IC, b)
        for c in range(0, O_flag):
            O_cal = GetMaxMw(O, O_IC, c)
            for d in range(2, N_flag):
                N_cal = GetMaxMw(N, N_IC, d)
                for e in range(4, P_flag):
                    P_cal = P*e
                    for f in range(8, Au_flag):
                        Au_cal = Au*f
                        for g in range(0, Ag_flag):
                            Ag_cal = GetMaxMw(Ag, Ag_IC, g)
                            for h in range(0, B_flag):
                                B_cal = GetMaxMw(B, B_IC, h)
                                for i in range(0, F_flag):
                                    F_cal = F*i
                                    for j in range(0, Cl_flag):
                                        Cl_cal = GetMaxMw(Cl, Cl_SI, j)
                                        for k in range(0, Bi_flag):
                                            Bi_cal = Bi*k
                                            # if (d or e) and (a != 14*d+18*e):
                                            #     continue
                                            # if a < e*18:
                                            #     continue
                                            if b > 2*a+2:
                                                continue
                                            if (C_cal+H_cal+O_cal+N_cal+P_cal+Au_cal+Ag_cal+B_cal+F_cal+Cl_cal+Bi_cal-elec).quantize(Decimal('0.0')) == Mw.quantize(Decimal('0.0')):
                                                print("C", a, "H", b, "O", c, "N", d, "P", e, "Au", f, "Ag", g, "B", h, "F", i, "Cl", j, "Bi", k)
                                                save.writelines(" " + str(a) + " " + str(b) + " " + str(c) + " " + str(d) + " " + str(e) + " " + str(f) + " " + str(g) + " " + str(h) + " " + str(i) + " " + str(j) + " " + str(k) + '\n')

save.close()

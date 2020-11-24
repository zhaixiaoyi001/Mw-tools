from scipy.special import comb
from decimal import *

C = [Decimal(12.000000000), Decimal(13.0033548350723)]
C_IC = [Decimal(0.98938), Decimal(0.01078)]
H = [Decimal(1.007825032239), Decimal(2.0141017781212)]
H_IC = [Decimal(0.99988570), Decimal(0.00011570)]
O = [Decimal(15.9949146195717), Decimal(17.9991596128676)]
O_IC = [Decimal(0.9975716), Decimal(0.0020514)]
N = [Decimal(14.0030740044320), Decimal(15.0001088988864)]
N_IC = [Decimal(0.9963620), Decimal(0.0036420)]
P = Decimal(30.9737619984270)
Au = Decimal(196.9665687971)
Ag = [Decimal(106.905091626), Decimal(108.904755314)]
Ag_IC = [Decimal(0.518398), Decimal(0.481618)]
B = [Decimal(10.0129369541), Decimal(11.0093053645)]
B_IC = [Decimal(0.1997), Decimal(0.8017)]
F = Decimal(18.9984031627392)
Cl = [Decimal(34.96885268237), Decimal(36.96590260255)]
Cl_SI = [Decimal(0.757610), Decimal(0.242410)]
Bi = Decimal(208.980399116)

def GetMaxMw(Mw, SI, n):
    if n == 0:
        return Decimal('0.000000000')
    data = []
    for i in range(0, n+1):
        data.append((SI[0]**(n-i))*(SI[1]**i)*int(comb(n, i)))
        if ((SI[0]**(n-i-1))*(SI[1]**(i+1))*int(comb(n, i+1)))<((SI[0]**(n-i))*(SI[1]**i)*int(comb(n, i))):
            break
    data_max = max(data)
    data_id = data.index(data_max)
    return (n-data_id)*Mw[0]+data_id*Mw[1]



import matplotlib as matplotlib
import  numpy as np
from matplotlib import pyplot as plt
# from Ipython.display import set_matplotlib_formats
#  set_matplotlib_formats('svg')

f= np.linspace(-1, 1, 80)
h1=(f ** 1+1 ** 1)/(f ** 1) # p=1, n=1
h2=(f ** 1+2 ** 1)/(f ** 1) # p=1, n=2
h3=(f ** 2+1 ** 2)/(f ** 1) # p=2, n=1

plt.plot(f, h1, color='orange', linestyle='solid', label='z(f) with:p= 1, n=1 ')
plt.plot(f, h2, color='black',linestyle='solid',label='z(f) with:p= 2, n=1 ')
plt.plot(f, h3, color='green', linestyle='solid', label='z(f) with:p= 1, n=2 ')
plt.grid()
plt.title(r'$Graphics z(f)=(f^n+p^n)/(f^n)')
plt.legend(loc='upper left')
plt.ylabel('z(f)', fontsize=20)
plt.xlabel('f', fontsize=20)
plt.show()
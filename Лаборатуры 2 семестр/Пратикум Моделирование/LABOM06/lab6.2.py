import matplotlib.pyplot as plt
x=['Math','IT','Economics','English','Frensh']
y=[5000, 26000, 21400,12000, 8000]
plt.pie(y, labels = x , radius=1, autopct = '%.2f', explode = [0,0.15,0,0,0])
plt.title("диаграмм")
plt.show()
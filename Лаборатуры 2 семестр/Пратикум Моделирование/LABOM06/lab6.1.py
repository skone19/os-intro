import matplotlib.pyplot as plt
x=[1,2,3,4,5,6,7,8,9]
y=[50.3, 69.0, 89.6,23.5,72.4,64.55,97.70, 12.5, 8.5]
plt.plot(x, y, label='line', color="black")
plt.bar(x, y, label='fruit', color="green")
plt.xlabel=('coordonne abscisse')
plt.ylabel=('cooordonne ordonne')
plt.title("гистограмм")
plt.legend()
plt.show()
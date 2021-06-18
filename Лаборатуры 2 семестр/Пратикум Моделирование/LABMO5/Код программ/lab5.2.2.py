import math
sum = 0.0
i=1
c= float(input('Введите точность:'))
sum1 =1
while (sum1>c):
    sum1 = (math.sqrt(i + 1)) / (i* math.exp(i))
    sum+=(math.sqrt(i+1))/(i*math.exp(i))
    i+=1
print(sum)

n=int(input("Введите номер частичной суммы:"))
sum=0
while(n>=1):
    x=1/(n*(n+1))
    sum=sum+x
    n=n-1
print(sum)

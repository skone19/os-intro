n=int(input("l:"))
m=int(input("c:"))
matrix= []
list_diagonal=[]
maximum_value=0
for i in range(n):
    matrix.append([])
    for j in range(m):
        print("input [", i,"] [", j, "]")
        new = int(input())
        matrix[i].append(new)
        if new > maximum_value:
            maximum_value= new
            x = i
            y = j
print("Matrix:")
for i in range (m):
    for j in range(n):
        if j==n-1:
            print(matrix[i][j])
        else:
            print(matrix[i][j], end=' ')

print("------Main Diagonal Matrix--------")
for i in range (m):
    for j in range(n):
                 if i==j:
                    list_diagonal.append(matrix[i][j])
    print(list_diagonal)

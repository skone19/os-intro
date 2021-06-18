import random
def create_matrix(rows, columns):
    matrix = []
    for i in range(0, rows):
        inner_list = []
        for j in range(0, columns):
            inner_list.append(round(random.uniform(-10, 10), 2))
        matrix.append(inner_list)
    return matrix
def spec_subtract(matrix):
    for i in range(0, len(matrix) - 1):
        for j in range(0, len(matrix[i])):
            matrix[i][j] = matrix[i][j] - matrix[len(matrix) - 1][j]
    return matrix
def print_matrix(matrix):
    print('\n'.join([''.join([' {:.2f}'.format(item) for item in row]) for row in matrix]))

n = int(input("Input the number of rows: "))
m = int(input("Input the number of columns: "))
matrix_ = create_matrix(n, m)
print_matrix(matrix_)
print()
matrix_ = spec_subtract(matrix=matrix_)
print_matrix(matrix_)
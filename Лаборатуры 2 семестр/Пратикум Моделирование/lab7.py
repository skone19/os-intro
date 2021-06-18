simple_tuple=('a', 1,2,3, 'a', 'b','c', 1)
a=simple_tuple.index(3)
b=simple_tuple.index('a', 2, 5)
c=simple_tuple.index(1, 4)
new_tuple =(a, b, c, simple_tuple[0])

print(new_tuple)
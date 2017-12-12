# This works in Python 2

x, y, n=map(int,raw_input().split())

for p in range(2, n):
    z = y*y + x
    x = y
    y = z
print(z)
from functools import reduce
import operator
N, M = map(int, input().split())
a = 1
for i in range(2, N+1):
    a = a * (i % M)
    a %= M
print(a)
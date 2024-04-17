from functools import reduce
import operator
N, M = map(int, input().split())
print(reduce(operator.mul, [i % M for i in range(1, N + 1)]) % M)
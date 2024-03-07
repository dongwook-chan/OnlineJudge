from collections import Counter
from math import perm
n = int(input())
I = map(int, input().split())
if max(Counter(I).values()) > 1:
    print(0, 6 ** (4 - n))
else:
    p = perm(6 - n, 4 - n)
    print(p, 6 ** (4 - n) - p)

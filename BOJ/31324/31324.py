from math import factorial
N, M = map(int, input().split())
W = factorial(N) * 2 ** N
if W >= M:
    print("Harshat Mata")
else:
    print("Nope")
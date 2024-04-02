from collections import namedtuple


Cu, Du = map(int, input().split())
Cd, Dd = map(int, input().split())
Cp, Dp = map(int, input().split())
H = int(input())

t: list[int] = [0] * 5001

for T in range(0, 5001, Cu):
    t[T] += Du

for T in range(0, 5001, Cd):
    t[T] += Dd

for T in range(0, 5001, Cp):
    t[T] += Dp

for i in range(0, 5001):
    H -= t[i]
    if H <= 0:
        break

print(i)
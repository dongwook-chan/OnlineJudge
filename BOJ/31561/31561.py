M = int(input())
a = min(M, 30)
b = max(0, M - 30)
print(round(a / 2 + b * 3 / 2, 1))
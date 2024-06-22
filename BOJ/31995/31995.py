N, M = int(input()), int(input())
C = (N - 1) * (M - 1) * 2
if N - 1 <= 0 or M - 1 <= 0:
    print(0)
else:
    print(C)
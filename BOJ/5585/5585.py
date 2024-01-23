C = int(input())
D = 1000 - C
N = 0
for i in [500, 100, 50, 10, 5]:
    N += D // i
    D %= i
N += D
print(N)

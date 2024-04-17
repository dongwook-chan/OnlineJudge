M, N = map(int, input().split())
l = [0] * (M + 1)
for _ in range(N):
    i, j, k = map(int, input().split())
    l[i:j + 1] = [k] * (j - i + 1)
print(*l[1:])
N, M = map(int, input().split())
l = list(range(0, N + 1))
for _ in range(M):
    i, j = map(int, input().split())
    l[i:j + 1] = l[i:j + 1][::-1]
print(*l[1:])
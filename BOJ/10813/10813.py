def swap(l, i, j):
    t = l[i]
    l[i] = l[j]
    l[j] = t

N, M = map(int, input().split())
l = [e for e in range(1, N + 1)]
for _ in range(M):
    i, j = map(int, input().split())
    swap(l, i - 1, j - 1)

print(*l)

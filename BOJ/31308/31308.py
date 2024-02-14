n, k, p = map(int, input().split())
ans = []
for i in range(p, 0, -1):
    if n % i == 0 and n // i <= k:
        ans.append(n // i)
print(len(ans))
print('\n'.join(map(str, ans)))
r, c = map(int, input().split())
o = r
for _ in range(c - 1):
    o = (o * (r - 1)) % 998244353
print(o)

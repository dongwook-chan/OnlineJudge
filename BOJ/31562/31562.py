N, M = map(int, input().split())
d = {}
for _ in range(N):
    T, S, *a = input().split()
    first_three = ''.join(a)[:3]
    if first_three in d.keys():
        d[first_three] = '?'
    else:
        d[first_three] = S
for _ in range(M):
    b = input().split()
    first_three = ''.join(b)[:3]
    if first_three in d.keys():
        print(d[first_three])
    else:
        print('!')

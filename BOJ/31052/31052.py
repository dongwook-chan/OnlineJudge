N, Q = map(int, input().split())
l = [-1] + list(map(int, input().split()))
for _ in range(Q):
    q = list(map(int, input().split()))
    if q[0] == 1:
        l[q[1]] = q[2]
    else:
        print(abs(l[q[1]] - l[q[2]]))

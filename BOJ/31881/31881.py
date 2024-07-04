import sys
from collections import Counter
N, Q = map(int, input().split())
c = [None] + [False] * N
ctr = 10
for _ in range(Q):
    q = sys.stdin.readline()
    match q[0]:
        case "1":
            x = int(q[2:])
            if not c[x]:
                ctr -= 1
            c[x] = True
        case "2":
            x = int(q[2:])
            if c[x]:
                ctr += 1
            c[x] = False
        case "3":
            print(ctr)

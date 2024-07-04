import sys
from collections import Counter
N, Q = map(int, input().split())
c = [None] + [False] * N
for _ in range(Q):
    q = sys.stdin.readline()
    match q[0]:
        case "1" | "2":
            x = int(q[2:])
            c[x] = q[0] == "1"
        case "3":
            print(Counter(c)[False])

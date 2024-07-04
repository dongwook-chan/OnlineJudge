from collections import Counter
N, Q = map(int, input().split())
c = [None] + [False] * N
for _ in range(N):
    q, *x_ = input().split()
    match q:
        case "1" | "2":
            x = int(x_[0])
            c[x] = q == "1"
        case "3":
            print(Counter(c)[False])

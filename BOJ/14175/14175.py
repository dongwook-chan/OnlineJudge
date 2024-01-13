M, N, K = map(int, input().split())
for _ in range (M):
    line = ""
    for c in input():
        if c.isspace():
            continue
        line += c * K
    line += "\n"
    print(line * K)

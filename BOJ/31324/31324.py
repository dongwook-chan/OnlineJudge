N, M = map(int, input().split())
W = 2 ** (N * (N + 1) / 2)
if W >= M:
    print("Harshat Mata")
else:
    print("Nope")
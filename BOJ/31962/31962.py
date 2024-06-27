N, X = map(int, input().split())
S_max = 0
for _ in range(N):
    S, T = map(int, input().split())
    if S + T <= X:
        S_max = max(S_max, S)
if S_max == 0:
    print(-1)
else:
    print(S_max)
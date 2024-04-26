X, Y = [], []
for _ in range(int(input())):
    x, y = map(int, input().split())
    X.append(x), Y.append(y)
print((max(X) - min(X)) * (max(Y) - min(Y)))
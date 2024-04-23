l=[input().strip() for _ in [0]*5]
for j in range(max(map(len,l))):
    for i in range(5):
        if j<len(l[i]):
            print(l[i][j],end='')
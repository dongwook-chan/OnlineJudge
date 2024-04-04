N, M = map(int, input().split())
l = []
for _ in range(N):
    l.append(input())
for j in range(M):
    if ''.join([l[i][j] for i in range(N)]) == 'X' * N:
        print(j + 1)
        break
else:
    print('ESCAPE FAILED')

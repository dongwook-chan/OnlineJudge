N = int(input())
A = set(map(int, input().split()))
for a in A:
    if a + 3 in A and a + 6 in A:
        print('Yes')
        break
else:
    print('No')

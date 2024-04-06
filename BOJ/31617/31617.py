K = int(input())
N = int(input())
A = tuple(map(int, input().split()))
M = int(input())
B = tuple(map(int, input().split()))
c = 0
for a in A:
    for b in B:
        if a + K == b:
            c += 1
print(c)

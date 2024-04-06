K = int(input())
N = int(input())
A = list(map(int, input().split()))
M = int(input())
B = list(map(int, input().split()))
c = 0
for a in A:
    for b in B:
        if a + K == b:
            c += 1
print(c)

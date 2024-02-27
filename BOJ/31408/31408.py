from collections import Counter
N = int(input())
counter = Counter(map(int, input().split()))
# N = 7
# counter = Counter([5, 3, 3, 2, 2, 2, 2])
A = []
for a, count in counter.most_common():
    A += [a] * count

V = [False] * N
v = 0
prev_a = 0
# print(A)
while v < N:
    # print(V)
    # print(prev_a)
    for i, a in enumerate(A):
        if V[i]:
            # print(i, a)
            continue
        if a != prev_a:
            V[i] = True
            v += 1
            prev_a = a
            break
    else:
        print("NO")
        break
else:
    print("YES")

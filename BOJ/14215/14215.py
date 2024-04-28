l = list(map(int, input().split()))
l.sort()
if l[-1] >= l[0] + l[1]:
    l[-1] = l[0] + l[1] - 1
print(sum(l))
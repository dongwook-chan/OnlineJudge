from statistics import mean
l = []
for _ in range(int(input())):
    l.append(list(map(ord, input().rstrip())))

s = ''
for j in range(max(map(len, l))):
    l_ = []
    for i in range(len(l)):
        try:
            l_.append(l[i][j])
        except IndexError:
            pass
    # print(l_, mean(l_))
    s += chr(int(mean(l_)))
print(s)

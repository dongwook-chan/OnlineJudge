row, column = [set() for _ in range(10)], [set() for _ in range(10)]
for i in range(10):
    s = input().split()
    for j in range(10):
        color = s[j]
        row[i].add(color)
        column[j].add(color)

for r, c in zip(row, column):
    if len(r) == 1 or len(c) == 1:
        print(1)
        break
else:
    print(0)
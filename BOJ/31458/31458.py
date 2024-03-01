from collections import deque
for _ in range(int(input())):
    e = input()
    i = e.find('0') + e.find('1') + 1
    n = 1 if len(e) - i >= 2 else int(e[i])
    if i % 2:
        n = 1 - n
    print(n)
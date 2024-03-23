prev_c = None
s = ''
for c in input():
    # print(prev_c, c)
    if c == prev_c:
        continue
    s += c
    prev_c = c
print(s)
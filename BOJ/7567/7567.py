prev = None
ans = 0
for cur in input():
    if prev != cur:
        ans += 10
    else:
        ans += 5
    prev = cur
print(ans)
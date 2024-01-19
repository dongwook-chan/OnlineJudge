N, B = input().split()
ans = 0
for c in N:
    ans *= int(B)
    if c.isdigit():
        ans += int(c)
    elif c.isalpha():
        ans += ord(c) - 55
print(ans)
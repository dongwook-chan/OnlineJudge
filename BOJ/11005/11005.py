N, B = map(int, input().split())
ans = ''
while N > 0:
    r = N % B
    if r < 10:
        ans += str(r)
    else:
        ans += chr(ord('A') + r - 10)
    N //= B
print(ans)
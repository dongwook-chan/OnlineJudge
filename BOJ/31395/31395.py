input()
As = tuple(map(int, input().split()))
A_p = As[0]
const = 1
ans = 1
for i in range(1, len(As)):
    A_c = As[i]
    if A_p < A_c:
        const += 1
    else:
        const = 1
    ans += const
    A_p = A_c
print(ans)

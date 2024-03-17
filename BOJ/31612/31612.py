from collections import Counter
N = int(input())
S = input()

Counter(S)
ans = 0
for c, i in Counter(S).items():
    match c:
        case 'j':
            ans += 2 * i
        case 'o':
            ans += i
        case 'i':
            ans += 2 * i
print(ans)

n, k, p = map(int, input().split())


def getMyDivisor(n):
    divisorsList = []

    for i in range(1, int(n ** (1 / 2)) + 1):
        if (n % i == 0):
            divisorsList.append(i)
            if ((i ** 2) != n):
                divisorsList.append(n // i)

    divisorsList.sort()

    return divisorsList

l1 = getMyDivisor(n)
l2 = l1[::-1]

ans = []
for e1, e2 in zip(l1, l2):
    if e2 > p:
        continue
    if e1 > k:
        break
    ans.append(e1)

print(len(ans))
print('\n'.join(map(str, ans)))
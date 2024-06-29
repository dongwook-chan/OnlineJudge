F = (
    {0, 1, 2, 3},
    {4, 5, 6, 7},
    {0, 1, 4, 5},
    {2, 3, 6, 7},
    {0, 2, 4, 6},
    {1, 3, 5, 7},
)

for _ in range(int(input())):
    f = set(map(int, input().split()))
    if f in F:
        print("YES")
    else:
        print("NO")

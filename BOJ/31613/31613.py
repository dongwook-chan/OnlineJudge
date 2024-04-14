X, N = map(int, open(0))
x = X
i = 0
while x < N:
    match x % 3:
        case 0:
            x += 1
        case 1:
            x *= 2
        case 2:
            x *= 3
    i += 1
print(i)
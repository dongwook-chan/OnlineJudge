L = input()
i, j = 0, 10
while True:
    if j > len(L):
        print(L[i:])
        break
    else:
        print(L[i:j])
    i += 10
    j += 10

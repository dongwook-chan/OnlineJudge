L = input()
i = 0
while True:
    if i + 10 > len(L):
        print(L[i:])
        break
    else:
        print(L[i:i + 10])
    i += 10

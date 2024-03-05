input()
for _ in range(3):
    D = list(map(int, input().split()))
    try:
        D.index(7)
    except:
        print(0)
        break
else:
    print(777)
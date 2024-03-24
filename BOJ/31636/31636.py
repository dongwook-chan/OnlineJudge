input()
for o in input().split('x'):
    if len(o) >= 3:
        print("Yes")
        break
else:
    print("No")
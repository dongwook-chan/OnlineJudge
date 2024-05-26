code = input()[:5]
count = 0
for _ in range(int(input())):
    if input()[:5] == code:
        count += 1
print(count)
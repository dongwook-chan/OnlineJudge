from collections import Counter
input()
counter = Counter(map(lambda x: int(x) % 2, input()))
if counter[0] > counter[1]:
    print(0)
elif counter[0] < counter[1]:
    print(1)
else:
    print(-1)

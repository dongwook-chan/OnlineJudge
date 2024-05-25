N, M = map(int, input().split())
output = []
unique_reverse_streaks = set()
for _ in range(N):
    tokens = input().split()
    records = ''.join(tokens[:-1]).split('*')
    reverse_streak = max(map(len, records))
    name = tokens[-1]
    output.append([reverse_streak, name])
    unique_reverse_streaks.add(reverse_streak)
print(len(unique_reverse_streaks))
for o in output:
    print(*o)

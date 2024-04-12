_, S, T = open(0)
print(sum(map(lambda x, y: int(x != y), S, T)))
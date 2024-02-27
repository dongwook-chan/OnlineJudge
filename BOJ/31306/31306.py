s = input()
i1 = sum(s.count(v) for v in 'aeiou')
i2 = i1 + s.count('y')
print(i1, i2)
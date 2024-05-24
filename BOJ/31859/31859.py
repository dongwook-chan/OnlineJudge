N_, S = input().split()
N = int(N_)
v = set()
one = ''
for s in S:
    if s not in v:
        v.add(s)
        one += s
two = one + str(len(S) - len(one) + 4)
three = str(1906 + N) + two
four = three[::-1]
five = "smupc_" + four
print(five)

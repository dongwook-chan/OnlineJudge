# print(list(open(0))[1:])
# print(list(open(0)))
# for _, x, y in list(open(0)):
#     print(_, x, y)
print(sum(x!=y for x,y in zip(*list(open(0))[1:])))
# print(sum(x!=y for _,x,y in zip(open(0))))
l=list(map(int,open(0)))
print(int(any(sum(l)==2*x for x in l)))
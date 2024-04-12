# A,B,C=map(int,open(0))
# print(int(A+B==C or A+C==B or B+C==A))

# l=list(map(int,open(0)))
# print(0+(sum(l)==max(l)*2))

a,b,c=sorted(map(int,open(0)))
print(0+(a+b==c))

# print(any(map(lambda x: sum(l)==2*x,l:=list(map(int,open(0))))))
# A,B,C=map(int,open(0))
# print(int(A+B==C or A+C==B or B+C==A))

a,b,c=sorted(map(int,open(0)))
print(int(a+b==c))

# print(any(map(lambda x: sum(l)==2*x,l:=list(map(int,open(0))))))
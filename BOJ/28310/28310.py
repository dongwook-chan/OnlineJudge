from fractions import Fraction
for _ in range(int(input())):
    N, M = map(int, input().split())
    A = []
    for j in range(M):
        v, *Aj = map(int, input().split())
        A.append([Fraction(Aji, v) for Aji in Aj])
    A_sum = [sum([A[j][i] for j in range(M)]) for i in range(N)]
    A_max = max(A_sum)
    A_min = min(A_sum)
    print(A_max - A_min)

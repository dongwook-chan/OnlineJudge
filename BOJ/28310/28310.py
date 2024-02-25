from fractions import Fraction
for _ in range(int(input())):
    N, M = map(int, input().split())
    V, A = [], []
    for j in range(M):
        v, *Aj = map(int, input().split())
        V.append(v)
        A.append([Fraction(Aji, v) for Aji in Aj])

    A_sum = sorted([sum([A[j][i] for j in range(M)]) for i in range(N)])

    print(A_sum[-1] - A_sum[0])

from itertools import permutations


N, M, K, T, P = map(int, input().split())
mosquitoes = tuple(tuple(map(int, input().split())) for _ in range(K))
grid = {(mosquito[0], mosquito[1]): idx for idx, mosquito in enumerate(mosquitoes)}
mosquitoes_idx = list(range(K))

map(lambda x: x[0] * x[1], enumerate([]))

W = 0
for permutation in permutations(mosquitoes_idx):
    t = 0
    w = 1
    prev_idx = permutation[0]
    for idx in permutation[1:]:
        dist = (
            abs(mosquitoes[prev_idx][0] - mosquitoes[idx][0])
            + abs(mosquitoes[prev_idx][1] - mosquitoes[idx][1])
        )
        if t + dist > T:
            break

        t += dist
        w += 1
        prev_idx = idx
    W = max(W, w)

A = 0
for r1 in range(1, N):
    for c1 in range(1, M):
        a = 0
        for r2 in range(1, N):
            for c2 in range(1, M):
                dist = abs(r1 - r2) + abs(c1 - c2)
                if (r2, c2) in grid:
                    mosquito = mosquitoes[grid[(r2, c2)]]
                    if dist == 0 or mosquito[2] <= P / dist:
                        a += 1
        A = max(A, a)

print(W, A)
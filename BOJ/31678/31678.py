names = []
bingo_candidates_list = []
for n in range(int(input())):
    names.append(input())

    board = tuple(tuple(map(int, input().split())) for _ in range(5))
    bingo_candidates = []
    bingo_candidates += [set(board[i]) for i in range(5)]
    bingo_candidates += [set(board[i][j] for i in range(5)) for j in range(5)]
    bingo_candidates.append(set(board[i][i] for i in range(5)))
    bingo_candidates.append(set(board[4 - i][i] for i in range(5)))
    bingo_candidates_list.append(bingo_candidates)

input()
bingo_names = []
selected_balls = set(map(int, input().split()))
for name, bingo_candidates in zip(names, bingo_candidates_list):
    for bingo_candidate in bingo_candidates:
        if bingo_candidate <= selected_balls:
            bingo_names.append(name)
            break
print(len(bingo_names))
print('\n'.join(bingo_names))

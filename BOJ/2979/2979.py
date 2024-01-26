from dataclasses import dataclass

@dataclass
class StackElement:
    time: int
    is_push: bool

A, B, C = list(map(int, input().split()))
C = [0, A, B * 2, C * 3]

T: list[StackElement] = [StackElement(0, None)]
for _ in range(3):
    t0, t1 = map(int, input().split())
    T.append(StackElement(t0, True))
    T.append(StackElement(t1, False))
T.sort(key=lambda x: x.time)

F = 0
cnt = 0
for i in range(1, len(T)):
    t_prev = T[i - 1].time
    t_cur = T[i].time

    d = t_cur - t_prev
    f = C[cnt]
    F += f * d

    if T[i].is_push:
        cnt += 1
    else:
        cnt -= 1

print(F)

# 5, 6, 6, 6, 10
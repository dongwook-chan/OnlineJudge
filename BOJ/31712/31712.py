from collections import namedtuple

Event = namedtuple("Event", ["time", "cycle", "damage"])

Cu, Du = map(int, input().split())
Cd, Dd = map(int, input().split())
Cp, Dp = map(int, input().split())
H = int(input())

pq: list[Event] = []
pq.append(Event(0, Cp, Dp))
pq.append(Event(0, Cu, Du))
pq.append(Event(0, Cd, Dd))

while H > 0:
    pq.sort(reverse=True)
    T, C, D = pq[-1]
    pq.pop()

    H -= D
    pq.append(Event(T + C, C, D))

print(T)

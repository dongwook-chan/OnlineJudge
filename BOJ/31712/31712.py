from queue import PriorityQueue
from collections import namedtuple

Event = namedtuple("Event", ["time", "cycle", "damage"])

Cu, Du = map(int, input().split())
Cd, Dd = map(int, input().split())
Cp, Dp = map(int, input().split())
H = int(input())

pq: PriorityQueue[Event] = PriorityQueue()
pq.put(Event(0, Cu, Du))
pq.put(Event(0, Cd, Dd))
pq.put(Event(0, Cp, Dp))

while H > 0:
    T, C, D = pq.get()
    H -= D
    pq.put(Event(T + C, C, D))

print(T)

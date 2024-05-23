from enum import IntEnum, auto

class Type(IntEnum):
    INVALID = auto()
    ROCK = auto()
    SCISSORS = auto()
    PAPER = auto()


l = [Type.ROCK, Type.INVALID, Type.SCISSORS, Type.INVALID, Type.INVALID, Type.PAPER]
d = {
    (Type.INVALID, Type.ROCK): '<',
    (Type.INVALID, Type.SCISSORS): '<',
    (Type.INVALID, Type.PAPER): '<',
    (Type.ROCK, Type.INVALID): '>',
    (Type.SCISSORS, Type.INVALID): '>',
    (Type.PAPER, Type.INVALID): '>',
    (Type.ROCK, Type.SCISSORS): '>',
    (Type.SCISSORS, Type.ROCK): '<',
    (Type.SCISSORS, Type.PAPER): '>',
    (Type.PAPER, Type.SCISSORS): '<',
    (Type.PAPER, Type.ROCK): '>',
    (Type.ROCK, Type.PAPER): '<',
}
p = tuple(map(lambda t: l[int(t)], input().split()))
try:
    print(d[p])
except Exception:
    print('=')
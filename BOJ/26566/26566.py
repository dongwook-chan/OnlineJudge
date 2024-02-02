from math import pi

for _ in range(int(input())):
    A1, P1 = map(int, input().split())
    R1, P2 = map(int, input().split())
    price_slice = A1 / P1
    price_whole = pi * R1 ** 2 / P2
    if price_slice > price_whole:
        print("Slice of pizza")
    elif price_slice < price_whole:
        print("Whole pizza")

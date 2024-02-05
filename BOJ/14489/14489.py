A, B = map(int, input().split())
C = int(input())
# print(A, B, C)
if 2 * C <= A + B:
    print((A + B) - 2 * C)
else:
    print(A + B)
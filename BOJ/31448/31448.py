N = int(input())
A = list(map(int, input().split()))
a_prev = A[0]
a_local_min = A[0]
a_diff_max = 0
for a in A[1:]:
    # print(a_prev, a, a_local_min, a_diff_max)
    if a > a_prev:
        a_diff_max = max(a_diff_max, a - a_local_min)
    else:
        a_local_min = a
    a_prev = a
print(a_diff_max)

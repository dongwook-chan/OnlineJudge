A = list(map(int, input().split()))
B = list(map(int, input().split()))

A.sort(reverse=True)
B.sort(reverse=True)

if sum(A) > sum(B):
    print("Algosia")
elif sum(A) < sum(B):
    print("Bajtek")
else:
    if A > B:
        print("Algosia")
    elif A < B:
        print("Bajtek")
    else:
        print("remis")

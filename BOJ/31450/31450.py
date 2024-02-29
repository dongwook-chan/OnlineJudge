M, K = map(int, input().split())
print(["Yes", "No"][min(M % K, 1)])
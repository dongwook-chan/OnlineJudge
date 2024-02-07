sum_m = 0
for _ in range(n := int(input())):
    sum_m += int(input())
avg_m = sum_m / n

if avg_m == 3:
    print("None")
elif avg_m == 5:
    print("Named")
elif avg_m >= 4.5:
    print("High")
else:
    print("Common")

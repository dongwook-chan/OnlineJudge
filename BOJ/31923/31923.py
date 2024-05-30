# 이미 꽂혀있는 과일 개수 같은 경우
N, P, Q = map(int, input().split())
act_diff = P - Q
A = map(int, input().split())
B = map(int, input().split())
act_count = []
for a, b in zip(A, B):
    fruit_diff = a - b
    if fruit_diff == 0:
        act_count.append(0)
    else:
        if act_diff == 0 or act_diff * fruit_diff > 0:
            print("NO")
            break
        elif act_diff * fruit_diff < 0:
            quotient, remainder = divmod(abs(fruit_diff), abs(act_diff))
            if remainder == 0:
                act_count.append(quotient)
            else:
                print("NO")
                break
else:
    print("YES")
    print(*act_count)
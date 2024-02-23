for _ in range(int(input())):
    T_A, T_B, V_A, V_B = map(int, input().split())

    if T_B * V_B >= T_A * V_A:
        print(T_B * V_B)
        continue

    D = T_B * V_B
    V_B = 0

    S = (D // T_A) * T_A + (D % T_A > 0) * T_A
    V_A -= (D // T_A) + (D % T_A > 0)

    D += ((V_A // 2) + (V_A % 2 > 0)) * T_A
    S += (V_A // 2) * T_A

    print(max(D, S))

while True:
    sides = sorted(list(map(int, input().split())))

    if sides == [0] * 3:
        break

    if sides[0] + sides[1] <= sides[2]:
        print("Invalid")
        continue

    match len(set(sides)):
        case 1:
            print("Equilateral")
        case 2:
            print("Isosceles")
        case 3:
            print("Scalene")

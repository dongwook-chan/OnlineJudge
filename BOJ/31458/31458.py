from collections import deque
for _ in range(int(input())):
    expression = deque(input())
    logical_not = False
    while expression[0] == '!':
        logical_not = not logical_not
        expression.popleft()

    number = int(expression.popleft())

    if expression and expression[0] == '!':
        number = 1

    if logical_not:
        number = 1 - number

    print(number)
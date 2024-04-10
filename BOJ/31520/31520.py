input_string = input()
input_string = input_string.strip()
current_string = ''
for i in range(1,11):
    current_string += str(i)
    if input_string == current_string:
        print(i)
        break
else:
    print(-1)
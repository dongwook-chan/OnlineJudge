status = input()
robot = status.find('@')
source = status.find('#')
destination = status.find('!')
if destination < robot < source or source < robot < destination:
    print(-1)
else:
    print(abs(destination - robot) - 1)

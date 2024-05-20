status = input()
robot = status.find('@')
source = status.find('#')
destination = status.find('!')
if robot < source < destination or destination < source < robot:
    print(abs(destination - robot) - 1)
else:
    print(-1)

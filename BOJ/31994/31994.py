l = []
for line in open(0):
    seminar, attendee_ = line.split()
    attendee = int(attendee_)

    l.append((attendee, seminar))

print(sorted(l)[-1][1])



S = int(raw_input())
D = int(raw_input())

count = 0
while S >= 0:
	S -= D
	count += 1
print str(S+D) + " " + str(count-1)
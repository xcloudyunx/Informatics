S = raw_input()
D = raw_input()

previous = -1
message = ""
y = 0

for x in xrange(len(D)):
	while y < len(S):
		if y > previous:
			if D[x] == S[y]:
				previous = y
				y += 1
				break
		y += 1
	else:
		break
else:
	print "YES"
	exit()
print "NO"
total = int(raw_input())

threes = 0

for i in xrange(total):
	num = raw_input()
	if num == "3":
		threes += 1

if threes == 0:
	print "This is a sad day"
elif threes == 1:
	print "I found 1 three"
else:
	print "I found", threes, "threes"
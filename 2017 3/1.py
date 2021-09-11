actions = []
length = int(raw_input())
for i in xrange(length):
	actions.append(raw_input())
	
for i in xrange(length):
	if i != length-1:
		if actions[i] == "S" and (actions[i+1] in ("S", "E")):
			continue
		elif actions[i] == "E" and (actions[i+1] == "N"):
			continue
		elif actions[i] == "N" and (actions[i+1] in ("E", "S")):
			continue
		else:
			break
else:
	print "plausible"
	exit()
print "impossible"
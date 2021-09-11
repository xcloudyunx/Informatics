t = int(raw_input())

if t % 4 == 0:
	print "$%i.00" % (t/4)
elif t % 4 == 2:
	print "$%i.50" % (t/4)
elif t % 4 == 1:
	print "$%i.25" % (t/4)
elif t % 4 == 3:
	print "$%i.75" % (t/4)
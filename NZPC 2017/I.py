import math

P = int(raw_input())

for _ in xrange(P):
	R, N = map(int, raw_input().split())
	instructions = []
	used = []
	for __ in xrange(N):
		t, b = raw_input().split()
		t = float(t)
		b = math.radians(90-abs(int(b)))
		ls = int(round((t+R/400.0)*120))
		while ls in used:
			ls += 1
		used.append(ls)
		slotstart = (ls-t*120.0)*10/3
		opp = R*math.cos(b)
		adj = slotstart - R*math.sin(b)
		hyp = (opp**2 + adj**2)**(0.5)
		theta = math.atan(opp/adj)
		distance = str(round(slotstart - hyp/(2*math.cos(theta)), 4))
		while len(distance)<6:
			distance += "0"
		time = str(round(t+slotstart/400, 4))
		while len(time)<6:
			time += "0"
		
		instructions.append("Slot "+str(ls)+", joining at "+distance+"km south, final approach at "+time)
	
	print "Scenario", _+1
	for line in instructions:
		print line
n, z, t = raw_input().split(" ")
n = int(n)
z = int(z)
t = int(t)

nurseries = []

for i in xrange(n):
	if i == z:
		nurseries.append(True)
	else:
		nurseries.append(False)

journeys = []

for i in xrange(t):
	x, y = raw_input().split(" ")
	journeys.append([int(x), int(y)])

sub = True
for i in journeys:
	if i[0]+1 != i[1]:
		if i[1] != 0:
			sub = False
			break
if not sub:
	for i in journeys:
		if i[0]-1 != i[1]:
			if i[1] != n-1:
				break
	else:
		sub = True
	
days = 0
while True:
	nurseriesO = []
	for i in nurseries:
		nurseriesO.append(i)
	
	for i in xrange(t):
		if nurseriesO[journeys[i][0]]:
			nurseries[journeys[i][1]] = True

	days += 1
	if False not in nurseries:
		if days == 1 and sub:
			print days-1
		else:
			print days
		exit()
		
	if nurseries == nurseriesO:
		print "-1"
		exit()
N, M, F, C = map(int, raw_input().split())
output = []

while N and M:
	paths = {}
	for _ in xrange(M):
		i, j, T = map(int, raw_input().split())
		paths[(min(i, j), max(i, j))] = T
	journeys = [999999 for _ in xrange(N+1)]
	journeys[F] = 0
	while True:
		for x in xrange(N):
			for p in paths:
				if x in p:
					y = list(p)
					y.remove(x)
					journeys[y[0]] = min(journeys[x]+paths[p], journeys[y[0]])
		
	
	N, M, F, C = map(int, raw_input().split())
	
for i in output:
	print i
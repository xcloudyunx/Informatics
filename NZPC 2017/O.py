N, M, K = map(int, raw_input().split())

while N and M and K:
	skill = map(int, raw_input().split())
	for _ in xrange(M):
		i, j = map(int, raw_input().split())
		eligible = skill[i-1:j]
		eligible.sort()
		teams = 0
		x = 0
		y = -1
		while eligible[x] <= eligible[y]:
			if eligible[x] + eligible[y] > K:
				y -= 1
			elif eligible[x] + eligible[y] < K:
				x += 1
			else:
				teams += 1
				x += 1
				y -= 1
		print teams
	
	N, M, K = map(int, raw_input().split())
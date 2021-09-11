N, K = raw_input().split(" ")
N = int(N)
K = int(K)
H = map(int, raw_input().split())
cost = 1000000000

for i in xrange(N-K+1):
	maximum = 0
	minimum = 1000000000
	heights = H[i:i+K]
	for i in heights:
		maximum = max(i, maximum)
		minimum = min(i, minimum)
		
	cost = min(maximum-minimum, cost)

print cost
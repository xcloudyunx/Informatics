MAX_TIME = 123
MAX_MANA = 123

t, s, r = map(int, raw_input().split())

dps = [[0 for _ in xrange(MAX_TIME)] for _ in xrange(MAX_MANA)]

for i in xrange(s):
	mana, time, dmg = map(int, raw_input().split())
	
	for j in xrange(t-time, -1, -1):
		for k in xrange(100, -1, -1):
			if k - mana >= 0:
				dps[j+time][min(100, k-mana+r*time)] = max(dps[j+time][min(100, k-mana+r*time)], dps[j][k] + dmg)
	
	for j in xrange(1, t):
		for k in range(100, -1, -1):
			dps[j][min(100, k+r)] = max(dps[j][min(100, k+r)], dps[j-1][k])
			
for i in range(100, 0, -1):
	dps[t][i-1] = max(dps[t][i-1], dps[t][i])
	
print dps[t][0]
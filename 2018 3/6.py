import itertools

T, S, R = raw_input().split(" ")
T = int(T)
S = int(S)
R = int(R)
M = 100

spells = []

for i in xrange(S):
	m, t, h, = raw_input().split(" ")
	m = int(m)
	t = int(t)
	h = int(h)
	spells.append([m, t, h])

totalDamage = 0
S = 9
while True:
	for i in itertools.permutations(spells, S):
		mana = M
		time = T
		for j in i:
			mana -= j[0]
			time -= j[1]
			if mana < 0 or time < 0:
				break
		else:
			damage = 0
			for j in i:
				damage += j[2]
			totalDamage = max(totalDamage, damage)
	if S != 1:
		S -= 1
	else:
		break
			
print totalDamage
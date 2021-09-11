sites = [1, 2, 3, 4, 5, 6, 7, 8]
vsites = []

s = int(raw_input())
vsites.append(str(s))

n = raw_input()
while "#" not in n:
	d, m = list(n)
	m = int(m)
	if d == "A":
		s = sites[(sites.index(s)-m)%8]
		vsites.append(str(s))
	else:
		s = sites[(sites.index(s)+m)%8]
		vsites.append(str(s))
	n = raw_input()

if len(vsites) >= 5 and len(list(set(vsites))) == len(vsites):
	print " ".join(vsites)
else:
	print " ".join(vsites), "reject"
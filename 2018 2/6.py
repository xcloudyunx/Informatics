N = int(raw_input())
ids = []
for i in xrange(N):
	ids.append(int(raw_input()))
	
for i in xrange(N):
	for j in xrange(i+1, N):	#Doesn't include current or before as already checked
		if ids[i] == ids[j]:
			print ids[i]
			exit()
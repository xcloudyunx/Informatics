N = int(raw_input())
array1 = raw_input().split()
array2 = raw_input().split()

print array1[0]

dict = {}
dodgy = []

for i in xrange(N):
	if array1[i] != array2[i]:
		integer = False
		new = False
		try:
			int(array1[i])
			integer = True
		except:
			try:
				array1[i] = dict[array1[i]]
			except:
				new = True
			
		try:
			int(array2[i])
			if integer:
				print "NE"
				break
			if new:
				dict[array1[i]] = array2[i]
				array1[i] = array2[i]
		except:
			try:
				array2[i] = dict[array2[i]]
				if not new:
					if array1[i] != array2[i]:
						print "NE"
						break
				else:
					dict[array1[i]] = array2[i]
					array1[i] = array2[i]
			except:
				if not new:
					dict[array2[i]] = array1[i]
					array2[i] = array1[i]
				else:
					dodgy.append(i)
else:
	length = len(dodgy)
	while dodgy:
		for i in dodgy:
			fail = False
			try:
				array1[i] = dict[array1[i]]
				dodgy[dodgy.index(i)] = False
			except:
				fail = True
			
			try:
				array2[i] = dict[array2[i]]
				if fail:
					dodgy[dodgy.index(i)] = False
					dict[array1[i]] = array2[i]
					array1[i] = array2[i]
			except:
				if fail:
					continue
				else:
					dict[array2[i]] = array1[i]
					array2[i] = array1[i]
				
			if array1[i] != array2[i]:
				print "NE"
				exit()
				
		while True:
			try:
				dodgy.remove(False)
			except:	
				break
		if len(dodgy) == length:
			print "DA"
			break
	else:
		print "DA"
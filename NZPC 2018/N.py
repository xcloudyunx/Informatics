from copy import deepcopy

def newCar(workChain, minutes, carNumber):
	global TF
	global N
	global M
	
	while True:
		for i in xrange(N-1):
			if workChain[i][0] < workChain[i+1][0] and workChain[i][0] > 0:
				return
	
		minutes += 1
		for i in xrange(N):
			workChain[i][0] -= 1
			
		for i in xrange(N-1, 0, -1):
			if workChain[i-1][0] == 0:
				workChain[i] = [TF[i][workChain[i-1][1]], workChain[i-1][1]]
		
		if workChain[0][0] <= 0 and carNumber != M-1:
			workChainOriginal = deepcopy(workChain)
			workChain[0] = [TF[0][carNumber+1], carNumber+1]
			newCar(workChain, minutes, carNumber+1)
			workChain = workChainOriginal
			for i in xrange(N-1):
				if workChain[i][0] < workChain[i+1][0] and workChain[i][0] > 0:
					return
		
		for i in workChain:
			if i[0] > 0:
				break
		else:
			break
			
	print minutes-1
	exit()

N, M = map(int, raw_input().split())

T = []
for _ in xrange(N):
	T.append(int(raw_input()))
	
F = []
for _ in xrange(M):
	F.append(int(raw_input()))
	
TF = []
for i in xrange(N):
	TF.append([])
	for j in xrange(M):
		TF[i].append(T[i]*F[j])
		
workChain = [[0, 0] for _ in xrange(N)]
minutes = 0
carNumber = -1

newCar(workChain, minutes, carNumber)
n,d = map(int, input().split())
bw = [i for i in range(n)]
cw = [i for i in range(n)]
br = input().split()
cr = input().split()
for remove in br:
    if int(remove) == 0:
        break
    else:
        bw.remove(int(remove)-1)

for remove in cr:
    if int(remove) == 0:
        break
    else:
        cw.remove(int(remove)-1)

for j in range(d):
    bwear, cwear = map(int, input().split())
    if bw[bwear-1] != cw[len(cw)-cwear]:
        print('Day', j+1, 'OK')
    else:
        print('Day', j+1, 'ALERT')
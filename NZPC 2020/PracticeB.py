n = int(input())
week = 0
while n != 0:
    list = set([])
    for i in range(n):
        inp = input()
        list.add(inp)
    week += 1
    print('Week', week, len(list))
    n = int(input()) 
n = input()

while n != '0 W 0':
    start, mode, end = n.split()
    if mode == 'W':
        start = int(start) - int(end)
        if start < -200:
            print('Not allowed')
        else:
            print(start)
    if mode == 'D':
        start = int(start) + int(end)
        print(start)
    n = input()
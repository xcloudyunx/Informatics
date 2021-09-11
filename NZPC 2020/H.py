from math import sqrt
n = input()
def sum(n):
    sum = 1
    for i in range(2, int(sqrt(n))+1):
        if n%i == 0:
            sum += i + n//i
    return sum

for j in range(int(n)):
    numbers = []
    l, u = map(int, input().split())
    print('Amicable numbers between',l,'and', u)
    for i in range(l+1, u):
        one = sum(i)
        if i == sum(one) and i != one:
            if (min(i, one), max(i, one)) not in numbers:
                numbers.append((min(i, one), max(i, one)))

    if len(numbers) != 0:
        for number in numbers:
            print(int(number[0]), int(number[1]))
    else:
        print('None')
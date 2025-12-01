allInput = []
with open("day1.in") as f:
    for line in f:
        allInput.append(line.strip())

init = 50
result = 0

for i in allInput:
    dir = i[0]
    value = int(i[1:])
    for j in range(value):
        if dir == 'R':
            init += 1
        else:
            init -= 1
        
        init = init % 100

        if init == 0:
            result += 1

print(result)
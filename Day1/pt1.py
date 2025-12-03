allInput = []
with open("day1.in") as f:
    for line in f:
        allInput.append(line.strip())

init = 50
result = 0

for i in allInput:
    if i[0] == 'R':
        init += int(i[1:])
    else:
        init -= int(i[1:])
    
    init = init % 100

    if init == 0:
        result += 1

print(result)
const input = require('fs').readFileSync('Day3/day3.in', 'utf-8');
const lines = input.trim().split('\n');

function getBiggerFromLine(line) {
    var max = -1;
    for (let i = 0; i < line.length; ++i) {
        for (let j = i + 1; j < line.length; ++j) {
            const stringNumber = line[i] + line[j];
            const number = parseInt(stringNumber, 10);
            if (number > max) {
                max = number;
            }
        }
    }
    return max;
}

var result = 0;
for (let i = 0; i < lines.length; ++i) {
    
    const line = lines[i];
    result += getBiggerFromLine(line);
}

console.log(result);
const input = require('fs').readFileSync('Day3/day3.in', 'utf-8');
const lines = input.trim().split('\n');

function getBiggerFromLine(line) {
    var totalDigits = 0;
    var lastIndex = 0;
    var result = '';
    
    while (totalDigits < 12) {
        var max = -1;
        for (let i = lastIndex; i < line.length - (11 - totalDigits); ++i) {
            const digit = parseInt(line[i], 10);
            if (digit > max) {
                max = digit;
                lastIndex = i + 1;
            }
        }
        totalDigits++;
        result += max.toString();
    }
    return parseInt(result, 10);
}

var result = 0;
for (let i = 0; i < lines.length; ++i) {
    const line = lines[i];
    if (line.length <= 12) {
        result += parseInt(line, 10);
        continue;
    }
    result += getBiggerFromLine(line);
}

console.log(result);
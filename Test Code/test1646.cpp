javascript
function findSolution(n) {
    if (n < 0) {
        return "Invalid input";
    } else if (n === 0) {
        return [];
    } else {
        let result = [];
        for (let i = 1; result.length < n; i++) {
            if (i % 2 === 0) {
                result.push(i);
            }
        }
        return result;
    }
}

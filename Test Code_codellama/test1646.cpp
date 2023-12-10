function findSolution(n) {
    if (n < 0) {
        return "Invalid input";
    } else if (n === 0) {
        return [];
    } else {
        let result = [];
        for (let i = 2; i <= n; i += 2) {
            result.push(i);
        }
        return result;
    }
}

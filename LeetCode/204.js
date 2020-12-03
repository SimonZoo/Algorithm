/**
 * @param {number} n
 * @return {number}
 */
var countPrimes = function(n) {
    if (n <= 1) return 0
    
    let count = Array(n).fill(0)
    for(let i = 2; i < n - 1; i++) {
        for(let j = 2; j * i < n; j++) {
            count[i * j] = 1
        }
    }
    return count.filter(it => it === 0).length - 2

};

// 质数计算
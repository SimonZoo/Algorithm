/**
 * @param {number} num
 * @return {string}
 */
var convertToBase7 = function(num) {
    // return num.toString(7)
    let n = Math.abs(num)
    if (n === 0) {
        return "0"
    }

    let result = ""
    while(n) {
        result = n % 7 + result
        n = n / 7 | 0
    }
    
    return num > 0 ? result : `-${result}`
};
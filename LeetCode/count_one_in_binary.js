/**
 * @param {number} n - a positive integer
 * @return {number}
 */
var hammingWeight = function(n) {
    // let l = 0
    // while(n !== 0) {
    //     n = n & (n - 1)
    //     l++
    // }

    // return l
    let s = n.toString(2).toString()
    let count = 0
    for(let i = 0; i < s.length; i++) {
        if (s[i] === "1")  count ++
    }
    return count
};
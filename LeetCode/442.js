/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDuplicates = function(nums) {
    let res = []
    for(let i = 0; i < nums.length; i++) {
        let curNum = Math.abs(nums[i])

        if (nums[curNum - 1] < 0) {
            res.push(curNum)
        }
        nums[curNum - 1] = -nums[curNum - 1]

    }
    return res
};

/**
 * 1. 还是需要一个额外的数组来做输出，这个空间是0～n/2的范围
 * 2. 因为数组元素的范围不会超出数组长度，且从1开始，不是出现一次就是出现两次
 * 3. 可通过对应下标，来判断数组下标对应的数字是不是已经是负数
 * 4. 已经是负数，说明是第二次出现这个数字了
 * 5. 就把这个数字放入输出数组中
 */
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    if (nums.length === 0) {
        return 0
    }
    
    let j = 0, i = 1;
    while( i < nums.length) {
        if (nums[j] === nums[i]) {
            i++;
        } else {
            j++;
            nums[j] = nums[i]
            i++;
        }
    }
    return j + 1
};
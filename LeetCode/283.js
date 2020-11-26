/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
    // 方法1：遍历数组，将0和非0的项移动到不同数组中，并合并
    // let zeroArr = []
    // let notZeroArr = []

    // for(let i = 0; i < nums.length; i++) {
    //     if (nums[i] === 0) 
    //         zeroArr.push(nums[i])
    //     else
    //         notZeroArr.push(nums[i])
    // }
    // return notZeroArr.concat(zeroArr)

    // 方法2：删除nums[i]为0的项，添加到数组末尾
    // for(let i = 0,j = 0; i < nums.length && j < nums.length; i++, j++) {
    //     if (nums[i] === 0) {
    //         nums.splice(i, 1)
    //         nums.push(0)
    //         i--
    //     }
    // }
    // return nums

    // 方法3：原地交换元素,j用来记录非零元素的个数,有待优化和思考
    let j = 0
    for(let i = 0; i < nums.length; i++) {
        if (nums[i] != 0) {
            let t = nums[i]
            nums[i] = nums[j]
            nums[j] = t
            j++
        } 
    }
    
    return nums
};



/**
 * @param {number[][]} people
 * @return {number[][]}
 */
var reconstructQueue = function(people) {
    let newPeople = people.sort((a,b) => {
        return b[0] === a[0] ?  (a[1] - b[1]) : (b[0] - a[0]) 
    })
    let res = []

    for(let i = 0; i < newPeople.length; i++) {
        
        if (res.length  <= newPeople[i][1]) {
            res.push(newPeople[i])
        } else {
            res.splice(newPeople[i][1], 0, newPeople[i])
        }

    }
    return res
    
};

/**
 * 1. 按照身高排序从高到低排序，降序
 * 2. 如果身高一样，将高于自己身高的人数大的放在后面，降序
 * 3. 遍历排序后的数组
 * 4. 额外空间数组 res
 * 5. 将高于自己身高的人数和额外数组res长度比较
 * 6. 额外数组长度 小于等于 高于自己的人数，直接放入数组（也就是说这个高于这个身高的人数还没有满足或者刚好满足，还可以在它之前插入其他
 * 7. 额外数组长度 大于 高于自己的人数，插入到下标位置为 高于自己的人数 的位置
 */
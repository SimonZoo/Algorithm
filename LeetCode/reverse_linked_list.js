/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var reverseList = function(head) {
    
    if (head === null) {
        return null
    }
    let cur = head
    let tmp = cur.next
    let pre = null

    while(cur !== null) {
        tmp = cur.next // 暂存下一个节点
        cur.next = pre // 修改指向关系
        pre = cur // 已经修改好关系的部分存起来
        cur = tmp // 改变当前结点
    }
    return pre
};


/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var countNodes = function(root) {
    if (root === null) return 0
    let q = [root]
    for(let i = 0; i < q.length; i++) {
        let curNode = q[i]
        if (curNode && curNode.left) q.push(curNode.left)
        if (curNode && curNode.right) q.push(curNode.right)
    }
    return q.length
};

// 可以利用完全二叉树的性质进行优化
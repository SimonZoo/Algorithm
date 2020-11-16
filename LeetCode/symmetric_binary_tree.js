/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var isSymmetric = function(root) {
    if (root === null) {
        return true
    } else {
        return check(root.right, root.left)
    }
};


function check(rightRoot, leftRoot) {
    if (rightRoot === null && leftRoot === null) return true
    if (rightRoot === null || leftRoot === null || leftRoot.val !== rightRoot.val)
        return false
    return check(rightRoot.left, leftRoot.right) && check(rightRoot.right, leftRoot.left) 
}

/**
 * 对称二叉树
 * 1. 特殊情况，root 为null，返回 true
 * 2. 终止条件
 *      1. 最后都回判断到null结点，同时等于null时，返回true
 *      2. 一边为空 或者 一边不相等，返回false
 */
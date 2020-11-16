/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {TreeNode}
 */
var invertTree = function(root) {
    if(root === null) {
        return null
    }
    let curRoot = root
    let tmp = curRoot.right
    curRoot.right = curRoot.left
    curRoot.left = tmp

    invertTree(curRoot.right)
    invertTree(curRoot.left)

    return curRoot
};
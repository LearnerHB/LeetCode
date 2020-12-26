/**	二叉树的下一个节点

给定一棵二叉树的其中一个节点，请找出中序遍历序列的下一个节点。

注意：
如果给定的节点是中序遍历序列的最后一个，则返回空节点;
二叉树一定不为空，且给定的节点一定不是空节点；

样例

假定二叉树是：[2, 1, 3, null, null, null, null]， 给出的是值等于2的节点。
则应返回值等于3的节点。

解释：该二叉树的结构如下，2的后继节点是3。
  2
 / \
1   3

思路：
分情况讨论：
1. 如果当前节点有右孩子，那右孩子的最左的节点就是下一个节点
2. 如果当前节点没有右孩子，那沿着父亲节点往上找，找到第一个是其父亲左孩子的节点，这个节点的父亲就是就是当前节点的后继

时间复杂度：
不论向上找还是向下找，总共遍历的节点数量不超过树的高度。
则时间复杂度为O(h)，h为树的高度
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode *father;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL), father(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* p) {
    	if (p==NULL)
    		return NULL;
        if (p->right){
        	p = p->right;
        	while (p->left)
        		p = p->left;
        	return p;
        }
        while (p->father && p==p->father->right)//找到第一个是其父亲左孩子的节点就退出循环
        	p = p->father;
        return p->father;
    }
};






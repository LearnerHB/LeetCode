/** 树的子结构

输入两棵二叉树A，B，判断B是不是A的子结构。
我们规定空树不是任何树的子结构。

样例
树A：

     8
    / \
   8   7
  / \
 9   2
    / \
   4   7
树B：

   8
  / \
 9   2
返回 true ,因为B是A的子结构。

思路
二叉树，递归
代码分为两部分：
1.遍历A树中所有的非空节点R 
—— 直接递归遍历即可，遇到非空节点就判断第二部分
2.判断树A中以R为根节点的子树是不是包含和树B一样的结构，且从根节点开始匹配 
—— 从根节点开始遍历两个子树
如果树B中的节点为空，则表示当前分支是匹配的，返回true；--> 就是已经递归到了B树的叶子节点了
如果树A中的节点为空，但树B中的节点不为空，则说明不匹配，返回false；
如果两个节点都不为空，但数值不同，则说明不匹配，返回false；
否则说明当前这个点是匹配的，然后递归判断左子树和右子树是否分别匹配即可；

时间复杂度 O(nm)

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (!pRoot1 || !pRoot2)	//空树不是任何树的子结构，也不可能是其他树的母结构
        	return false;
        if (isSame(pRoot1, pRoot2))
        	return true;
        return hasSubtree(pRoot1->left, pRoot2) || hasSubtree(pRoot1->right, pRoot2);
    }

    bool isSame(TreeNode* pRoot1, TreeNode* pRoot2){
    	if (!pRoot2)	//isSame()已经递归到B树的叶子节点
    		return true;
    	if (!pRoot1 || pRoot1->val != pRoot2->val)
    		return false;
    	return isSame(pRoot1->left, pRoot2->left) && isSame(pRoot1->right, pRoot2->right);
    }
};














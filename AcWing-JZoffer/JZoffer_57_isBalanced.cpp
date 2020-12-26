/**	平衡二叉树

输入一棵二叉树的根结点，判断该树是不是平衡二叉树。
如果某二叉树中任意结点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。
注意：
规定空树也是一棵平衡二叉树

样例
输入：二叉树[5,7,11,null,null,12,9,null,null,null,null]如下所示，
    5
   / \
  7  11
    /  \
   12   9
输出：true

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

//结合求深度的方法，可以AC，缺点是存在重复计算深度的问题
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root)	return true;
        //这句的摆放顺序暗含着，如果第一个深度条件不满足，后面就不需要判断了
        return abs(treeDepth(root->left)-treeDepth(root->right))<=1 && isBalanced(root->left) && isBalanced(root->right);
        
    }

    int treeDepth(TreeNode* root) {
    	if (!root)	return 0;
    	return max(dfs(root->left), dfs(root->right))+1;
    }
};

//对求深度的代码稍作修改，使得isBalanced部分不需要进行递归
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root)>=0;
    }
    //不平衡的时候返回-1，平衡的时候返回高度值
    int dfs(TreeNode* root) {
    	if (!root)	return 0;
    	int left = dfs(root->left);
    	if (left<0)	return -1;
    	int right = dfs(root->right);
    	if (right<0) return -1;
    	if (abs(left-right)>1)	return -1;
    	return max(left, right) + 1;
    }
};




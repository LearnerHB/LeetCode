/**	二叉搜索树的第k个结点	🌟🌟

给定一棵二叉搜索树，请找出其中的第k小的结点。
你可以假设树和k都存在，并且1≤k≤树的总结点数。

样例
输入：root = [2, 1, 3, null, null, null, null] ，k = 3
    2
   / \
  1   3
输出：3

思路
O(N)
二叉搜索树的中序遍历就是递增的序列，所以我们可以构建其中序遍历并在过程中求出答案

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
	TreeNode* ans;
    TreeNode* kthNode(TreeNode* root, int k) {
       	dfs(root, k);
       	return ans;
    }

    void dfs(TreeNode* root, int &k){
    	if (!root)	return ;
    	dfs(root->left, k);
    	k--;	//遍历到根节点的时候就让k减1来判断是否到第k个
    	if (!k)	ans = root;
    	if (k>0) dfs(root->right, k);	//剪枝，k<0时候不需要再遍历右子树
    }
};
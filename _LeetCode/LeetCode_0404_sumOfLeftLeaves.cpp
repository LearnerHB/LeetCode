/**	左孩子之和

计算给定二叉树的所有左叶子之和。

示例：
    3
   / \
  9  20
    /  \
   15   7

在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-left-leaves
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
//	DFS按部就班法
class Solution {
public:
	bool isLeafNode(TreeNode* root) {
		return !root->left && !root->right;
	}
    int dfs(TreeNode* root) {
    	int sum = 0;	//表示当前节点子树下的左叶子和
    	if (root->left)
    		sum += (isLeafNode(root->left) ? root->left->val : dfs(root->left));
    	if (root->right && !isLeafNode(root->right)) 
    		sum += dfs(root->right);
    	return sum;
    }
    int sumOfLeftLeaves(TreeNode* root) {
    	return root ? dfs(root) : 0;
    }
};

//	DFS代码少写法
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
    	if (root==NULL)	return 0;
    	return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right) + 
    		((root->left!=NULL && !root->left->left && !root->left->right)?root->left->val : 0);
    }
};

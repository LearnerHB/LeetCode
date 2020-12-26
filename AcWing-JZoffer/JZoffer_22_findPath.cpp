/**	二叉树中和为某一值的路径

输入一棵二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。

样例
给出二叉树如下所示，并给出num=22。
      5
     / \
    4   6
   /   / \
  12  13  6
 /  \    / \
9    1  5   1

输出：[[5,4,12,1],[5,6,6,5]]

思路
DFS，遍历到叶子节点，遍历过程中更改相应的条件，遍历到叶子节点的时候判断是否满足和为输入整数

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
	vector<vector<int>> res;	//最终答案
	vector<int> path;			//当前路径
    vector<vector<int>> findPath(TreeNode* root, int sum) {
        dfs(root, sum);
        return res;
    }
    void dfs(TreeNode *root, int sum){
    	if (!root)
    		return;
    	path.push_back(root->val);
    	sum -= root->val;
    	if (!root->left && !root->right && !sum)
    		res.push_back(path);
    	dfs(root->left, sum);
    	dfs(root->right, sum);
    	path.pop_back();
    }
};




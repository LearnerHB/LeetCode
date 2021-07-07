/**	二叉树的层序遍历 1 Tree / BFS
对比LeetCode_0107

给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 
（即逐层地，从左到右访问所有节点）。
示例：
二叉树：[3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：
[
  [3],
  [9,20],
  [15,7]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)	return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
        	vector<int> level;
        	int size = q.size();
        	for (int i = 0; i < size; i++) {
        		TreeNode* node = q.front();
        		q.pop();
        		level.push_back(node->val);
        		if (node->left)		q.push(node->left);
        		if (node->right) 	q.push(node->right);
        	}
        	res.push_back(level);
        }
        return res;
    }
};
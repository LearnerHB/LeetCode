/** 二叉树的中序遍历

给定一个二叉树，返回它的中序遍历。
示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-inorder-traversal
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

//	递归
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        dfs(root, res);
        return res;
    }
    void dfs(TreeNode* root, vector<int>& res) {
    	if (!root)	return;

    	dfs(root->left, res);
    	res.push_back(root->val);
    	dfs(root->right, res);
    }
};

//	迭代: 每次到节点X，先将X入栈，然后访问左子树，while循环直到没有左子树，
//	然后将X出栈，访问X，然后访问右子树
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        TreeNode* rt = root;
        while (rt || st.size()) {
        	while(rt) {
        		st.push(rt);
        		rt = rt->left;
        	}
        	rt = st.top();
        	st.pop();
        	res.push_back(rt->val);
        	rt = rt->right;
        }
        return res;
    }
};








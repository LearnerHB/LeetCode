/**		把二叉搜索树转换为累加树
给定一个二叉搜索树（Binary Search Tree），把它转换成为累加树（Greater Tree)，使得每个节点的值是原来的节点值加上所有大于它的节点值之和。

例如：
输入: 原始二叉搜索树:
              5
            /   \
           2     13
输出: 转换为累加树:
             18
            /   \
          20     13

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/convert-bst-to-greater-tree
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

//反向中序遍历 —— 递归
class Solution {
public:
	int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        if (root != nullptr) {
        	convertBST(root->right);
        	sum += root->val;
        	root->val = sum;
        	convertBST(root->left);
        }
        return root;

    }

};
//反向中序遍历 —— 迭代
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
    	int sum = 0;
		stack<TreeNode*> st;
		TreeNode* cur = root;
        while (cur) {
        	st.push_back(cur);
        	cur = cur->right;
        }
        while (!st.empty()) {
        	cur = st.top();
        	st.pop();
        	sum += cur->val;
        	cur->val = sum;
        	if (cur->left) {
        		cur = cur->left;
        		while (cur) {
        			st.push(cur);
        			cur = cur->right;
        		}
        	}
        }
        return root;

    }

};









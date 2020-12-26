/**	树中两个结点的最低公共祖先

给出一个二叉树，输入两个树节点，求它们的最低公共祖先。
一个树节点的祖先节点包括它本身。

注意：
输入的二叉树不为空；
输入的两个节点一定不为空，且是二叉树中的节点；

样例
二叉树[8, 12, 2, null, null, 6, 4, null, null, null, null]如下图所示：
    8
   / \
  12  2
     / \
    6   4
1. 如果输入的树节点为2和12，则输出的最低公共祖先为树节点8。
2. 如果输入的树节点为2和6，则输出的最低公共祖先为树节点2。

思路
1. 查找路径 O(n)
	分别找出根节点到两个节点的路径，
	找出最后一个公共节点即为最低公共祖先

2. 递归 O(n)
考虑在左子树和右子树中查找这两个节点，
如果两个节点分别位于左子树和右子树，则最低公共祖先为自己(root)，
若左子树中两个节点都找不到，说明最低公共祖先一定在右子树中，反之亦然。
考虑到二叉树的递归特性，因此可以通过递归来求得



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

//1. 查找路径
class Solution {
public:
	int findPath(TreeNode* root, TreeNode* p, vector<TreeNode*>&path){
		if (!root)
			return 0;
		if (root->val == p->val) {
			path.push_back(root);
			return 1;
		}
		int l = findPath(root->left, p, path);
		int r = findPath(root->right, p, path);
		if (l==1 || r==1)
			path.push_back(root);
		return l==1||r==1;
	}

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;
        findPath(root, p, path1);
        findPath(root, q, path2);
        if (path1.empty() || path2.empty())
        	return NULL;
        TreeNode* ans = NULL;
        for (int i = 0; i < path1.size(); i++) {
        	if (i>=path1.size() || i>=path2.size())
        		break;
        	if (path1[path1.size()-1-i]==path2[path2.size()-1-i])
        		ans = path1[path1.size()-1-i];
        	else break;
        }
        return ans;

    }
};

//2. 递归
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root==p || root==q)
        	return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left&&right)	//两个节点分别在左右子树
        	return root;
        if (left==NULL)		//节点都在右子树
        	return right;
        else 				//节点都在左子树
        	return left;
    }
};









/** 对称的二叉树

请实现一个函数，用来判断一棵二叉树是不是对称的。
如果一棵二叉树和它的镜像一样，那么它是对称的。

样例
如下图所示二叉树[1,2,2,3,4,4,3,null,null,null,null,null,null,null,null]为对称二叉树：
    1
   / \
  2   2
 / \ / \
3  4 4  3

如下图所示二叉树[1,2,2,null,4,4,3,null,null,null,null,null,null]不是对称二叉树：
    1
   / \
  2   2
   \ / \
   4 4  3

思路
递归判断两个子子树是否互为镜像
两棵子树互为镜像当且仅当：
1.两棵子树的根节点值相等；
2.第一棵子树的左子树和第二棵子树的右子树互为镜像，且第一棵子树的右子树和第二棵子树的左子树互为镜像

时间复杂度
每个节点仅遍历一遍，为O(n)
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
    bool isSymmetric(TreeNode* root) {
        if (!root)
        	return true;
        return dfs(root->left, root->right);

    }
    bool dfs(TreeNode *a, TreeNode *b){
    	if (!a || !b)
    		return !a && !b;	//若递归至两棵子树同时为空，则这部分子结构就是匹配的；否则不匹配
    	if (a->val != b->val)
    		return false;		
    	return dfs(a->left, b->right) && dfs(a->left, b->right);
    }
};










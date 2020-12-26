/**	二叉搜索树与双向链表

输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
要求不能创建任何新的结点，只能调整树中结点指针的指向。

注意：
需要返回双向链表最左侧的节点。
例如，输入下图中左边的二叉搜索树，则输出右边的排序双向链表。

思路
注意到不管是二叉搜索树还是双向排序链表，节点都是包含左右指针的。
最后的结构中，节点的左指针指向比它小的元素，也就是原来的左孩子，右指针则相反
这样的结构和原本的二叉搜索树有相似之处

分治+递归

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
	TreeNode* pre = NULL;

    TreeNode* convert(TreeNode* root) {
       	dfs(root);
       	while (root && root->left)	//处理完之后需要往左一直遍历回去
       		root = root->left;
       	return root;
    }

    void dfs(TreeNode* root){
    	if (!root)
    		return;

    	dfs(root->left);

    	root->left = pre;
    	if (pre)
    		pre->right = root;
    	pre = root;

    	dfs(root->right);
    }
};





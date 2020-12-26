/**	二叉树的镜像

输入一个二叉树，将它变换为它的镜像。

样例
输入树：
      8
     / \
    6  10
   / \ / \
  5  7 9 11
 [8,6,10,5,7,9,11,null,null,null,null,null,null,null,null] 
输出树：
      8
     / \
    10  6
   / \ / \
  11 9 7  5
 [8,10,6,11,9,7,5,null,null,null,null,null,null,null,null]

思路
可以发现镜像后的树就是将原树的所有节点的左右儿子互换，
递归遍历原树的所有节点并将左右儿子互换，借助swap交换指针

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
    void mirror(TreeNode* root) {
        if (!root)
        	return;
        swap(root->left, root->right);	//交换两个指针
        mirror(root->left);
        mirror(root->right);
    }
};








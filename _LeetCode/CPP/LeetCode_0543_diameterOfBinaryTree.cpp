/*  二叉树的直径

给定一棵二叉树，你需要计算它的直径长度。
一棵二叉树的直径长度是任意两个结点路径长度中的最大值。
这条路径可能穿过也可能不穿过根结点。 

示例 :
给定二叉树

          1
         / \
        2   3
       / \     
      4   5    
返回3, 它的长度是路径 [4,2,1,3] 或者[5,2,1,3]。

注意：两结点之间的路径长度是以它们之间边的数目表示。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/diameter-of-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Sol 1: DFS
// 1. 求直径等效于求路径经过节点数的最大值减一
// 2. 任意路径均可以看成由某个节点为起点，从其左儿子和右儿子向下遍历的路径拼接得到
class Solution {
public:
    int maxD = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return maxD;
    }

    int depth(TreeNode* node) {
        if (node == nullptr) 
            return 0;
        int l = depth(node->left);
        int r = depth(node->right);
        maxD = max(l + r, maxD);    
        return max(l, r) + 1;   //返回节点深度
    }
};
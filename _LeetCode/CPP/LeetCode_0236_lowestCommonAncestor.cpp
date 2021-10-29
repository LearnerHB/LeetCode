/*    ★★★ 二叉树的最近公共祖先 

给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

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

// Sol 1 DFS
/*
    root 是 q p 的最近公共祖先只可能是以下情况之一：
    1. p q 在root的子树中，且分列异侧
    2. p = root 且 q 在 root 的左或右子树中
    3. q = root 且 p 在 root 的左或右子树中
    
    递归解析：
    1. 终止条件：当叶节点返回null；当root等于p,q，返回root
    2. 递推工作：开启递归左子节点，返回值标记left；开启递归右子节点，返回值标记right；
    3. 返回值：根据left和right，展开为4种情况：
        1. 当left right同时为空：说明root子树中不含p,q，返回null;
        2. 当left right同时非空：说明p,q分别在root异侧，因此root为最近公共祖先，返回root;
        3. 当left为空 right非空：说明p,q都不在root左子树中，直接返回right 具体可分为两种情况：
            1. p,q其中一个在root右子树中，此时right指向p(假设);
            2. p,q两节点都在root右子树中，此时right指向最近公共祖先节点;
        4. 当left非空 right为空：与3同理
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left == nullptr && right == nullptr) return nullptr;    // 这句也可省略
        if (left == nullptr) return right;
        if (right == nullptr) return left;
        return root;
    }
};

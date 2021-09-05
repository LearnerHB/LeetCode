/*    
给你二叉树的根结点 root ，请你将它展开为一个单链表：

展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
展开后的单链表应该与二叉树 先序遍历 顺序相同。

示例
输入：root = [1,2,5,3,4,null,6]
输出：[1,null,2,null,3,null,4,null,5,null,6]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list
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
// Sol 1: 1. 左子树插入到右子树的地方； 2. 原本的右子树接到最右边的节点的右边； 3. 考虑新的右子树的根节点并重复上面流程
class Solution {
public:
    void flatten(TreeNode* root) {
        while (root != nullptr) {
            if (root->left != nullptr) {
                // 找到左子树最右边节点
                TreeNode* rightest = root->left;
                while (rightest->right != nullptr) {
                    rightest = rightest->right;
                }
                // 原本右子树插到左子树最右边节点的右边
                rightest->right = root->right;
                // 左子树插到右子树位置
                root->right = root->left;
                root->left = nullptr;
            }
            root = root->right;
        }
    }
};
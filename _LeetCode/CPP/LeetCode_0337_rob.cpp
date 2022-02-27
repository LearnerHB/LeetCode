/*    ★★★ 打家劫舍 III

在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。
这个地区只有一个入口，我们称之为“根”。 
除了“根”之外，每栋房子有且只有一个“父“房子与之相连。
一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 
如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。

计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。

示例
输入: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

输出: 7 
解释: 小偷一晚能够盗取的最高金额 = 3 + 3 + 1 = 7.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/house-robber-iii
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


/* 树形DP问题
单个节点的钱算法：4个孙子的钱+爷爷的钱 VS 两个儿子的钱，
值大的当做当前节点能偷的最大钱数，为DP的最优子结构

int method1 = root.val + rob(root.left.left) + rob(root.left.right)
            + rob(root.right.left) + rob(root.right.right)
int method2 = rob(root.left) + rob(root.right)
int result = max(method1, method2)

*/
// Sol 1: 暴力递归 超出时间限制
class Solution {
public:
    int rob(TreeNode* root) {
        if (root == nullptr) return 0;
        int money = root->val;
        if (root->left != nullptr) {
            money += (rob(root->left->left) + rob(root->left->right));
        }
        if (root->right != nullptr) {
            money += (rob(root->right->left) + rob(root->right->right));
        }
        return max(money, rob(root->left) + rob(root->right));
    }
};

/* Sol 2:
每个节点可以选择偷或者不偷，用一个数组存储
任何一个节点能偷的最多钱定义为：
1. 当前不偷的最大钱数=左孩子能拿出的最大钱数+右孩子能拿出最大钱数（不一定偷）
2. 当前偷的最大钱数=左孩子不偷时候最大钱数+右孩子不偷时候最大钱数
root[0] = max(rob(root->left)[0], rob(root->left)[1]) 
        + max(rob(root->right)[0], rob(root->right)[1])
root[1] = rob(root->left)[0] + rob(root->right)[0] + root->val
*/
class Solution {
public:
    int rob(TreeNode* root) {
       vector<int> result = robInternal(root);
       return max(result[0], result[1]); 
    }
    vector<int> robInternal(TreeNode* root) {
        if (root == nullptr) return vector<int>(2,0);
        vector<int> result(2);
        vector<int> left = robInternal(root->left);
        vector<int> right = robInternal(root->right);
        result[0] = max(left[0], left[1]) + max(right[0], right[1]);
        result[1] = left[0] + right[0] + root->val;

        return result;
    }
};
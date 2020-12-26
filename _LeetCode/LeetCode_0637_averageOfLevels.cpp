/** 	二叉树的层平均值

给定一个非空二叉树, 返回一个由每层节点平均值组成的数组。
示例 1：
输入：
    3
   / \
  9  20
    /  \
   15   7
输出：[3, 14.5, 11]
解释：
第 0 层的平均值是 3 ,  第1层是 14.5 , 第2层是 11 。因此返回 [3, 14.5, 11] 。
 

提示：

节点值的范围在32位有符号整数范围内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/average-of-levels-in-binary-tree
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
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
    	vector<double> res;
        if (!root)	return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
        	vector<int> level;
        	int size = q.size();
        	double sum = 0;	//用int的话会溢出
        	int count = 0;
        	for (int i = 0; i < size; i++) {
        		TreeNode* node = q.front();
        		sum += node->val;
        		count++;
        		q.pop();
        		level.push_back(node->val);
        		if (node->left)		q.push(node->left);
        		if (node->right) 	q.push(node->right);
        	}
        	res.push_back(sum / count);
        }
        return res;
    }
};
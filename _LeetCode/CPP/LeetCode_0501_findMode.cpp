/**	二叉搜索树中的众数

给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。

假定 BST 有如下定义：
结点左子树中所含结点的值小于等于当前结点的值
结点右子树中所含结点的值大于等于当前结点的值
左子树和右子树都是二叉搜索树
例如：
给定 BST [1,null,2,2],

   1
    \
     2
    /
   2
返回[2].

提示：如果众数超过1个，不需考虑输出顺序

进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-mode-in-binary-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
//	1. 暴力法，用哈希表统计。需要额外的存储空间
//	这种方法适用于所有二叉树，而没有利用到该树是二叉搜索树，其中序遍历是有序的这一特性
class Solution {
private:
	void dfs(TreeNode* root, unordered_map<int, int>& hash) {
		//前序遍历
		if (!root)	return;
		hash[root->val] ++;
		dfs(root->left, hash);
		dfs(root->right, hash);
		return;
	}
	bool static cmp(const pair<int, int>& a, const pair<int, int>& b) {
		return a.second > b.second;
	}
public:
	vector<int> findMode(TreeNode* root) {
		unordered_map<int, int> hash;
		vector<int> res;
		if (!root)	return res;
		dfs(root, hash);
		vector<pair<int,int>> v(hash.begin(), hash.end());
		sort(v.begin(), v.end(), cmp);	//给出现频率排序
		res.push_back(v[0].first);
		for (int i = 1; i < v.size(); i++) {
			if (v[i].second == v[0].second)
				res.push_back(v[i].first);
			else break;
		}
		return res;
	}
};







/**	二叉搜索树的后序遍历序列

输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则返回true，否则返回false。
假设输入的数组的任意两个数字都互不相同。

样例
输入：[4, 8, 6, 12, 16, 14, 10]
输出：true

思路
后序遍历的顺序是 左右根，所以一个数组序列的最后一个元素需要是这个BST的根节点。
BST的左子树的结点值都比根节点小，右结点值都比根节点大。
根据这个性质，递归判断这个数组中，属于根节点的左右子树的值是不是都满足这个条件


*/


class Solution {
public:
	vector<int> seq;
    bool verifySequenceOfBST(vector<int> sequence) {
        seq = sequence;
        return dfs(0, seq.size() - 1);
    }
    bool dfs(int l, int r){
    	if (l >= r)			//递归的返回条件
    		return true;
    	int root = seq[r];	//当前子树的根节点为当前部分数组右边界的值
    	int k = l;
    	while (k < r && seq[k] < root)
    		k++;
    	for (int i = k; i < r; i++)
    		if (seq[i] < root)	
    			return false;	//如果当前数组划分出来的右子树部分有结点值小于根节点则不符合BST
		return dfs(l, k-1) && dfs(k, r-1);

    }
};


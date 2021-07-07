/**	子集
联合学习：78子集、77组合、46全排列

给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

思路
1. 递归	时间O(N * 2^N) 空间O(N * 2^N)
每次整数数组nums加入一个新的元素，增加的子集就是原本每个子集再加上这个新元素
所以子集的数量就是2^n，n是元素个数。
如果 A = subset([1,2]) ，那么： subset([1,2,3])	= A + [A[i].add(3) for i = 1..len(A)]
这是典型的递归结构
2. 回溯 	时间O(N * 2^N) 空间O(N * 2^N)

3. 位运算
字典排序(二进制排序),二进制位1表示子集元素中有该数字，0表示子集元素中没有该数字

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subsets
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
//	1. 递归
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
    	if (nums.empty())	return {{}};
    	int n = nums.back();
    	nums.pop_back();

    	//先递归算出前面部分元素集合的所有子集
    	vector<vector<int>> res = subsets(nums);
    	int size = res.size();
    	for (int i = 0; i < size; i++) {
    		//对每个子集追加元素
    		res.push_back(res[i]);
    		res.back().push_back(n);
    	}
    	return res;
    }
};

//	2. 回溯
class Solution {
public:
	vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
    	vector<int> tmp;
    	backtrack(nums, 0, tmp);
    	return res;
    }

    void backtrack(vector<int>& nums, int start, vector<int> tmp) {
    	res.push_back(tmp);
    	for (int i = start; i < nums.size(); i++) {
    		tmp.push_back(nums[i]);
    		backtrack(nums, start+1, tmp);
    		tmp.pop_back();
    	}
    }
};


//	3. 位运算
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
    	int s = nums.size();
    	int N = 1 << s;
    	vector<vector<int>> res;
    	for (int i = 0; i < N; i++) {
    		vector<int> tmp;
    		for (int j = 0; j < s; j++) 
    			if (i & (1<<j))
    				tmp.push_back(nums[j]);
    		res.push_back(tmp);
    	}
    	return res;
    }
};
















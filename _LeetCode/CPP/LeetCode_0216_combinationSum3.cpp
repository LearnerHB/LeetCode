/**	组合总和3

找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

说明：
所有数字都是正整数。
解集不能包含重复的组合。 
示例 1:
输入: k = 3, n = 7
输出: [[1,2,4]]
示例 2:
输入: k = 3, n = 9
输出: [[1,2,6], [1,3,5], [2,3,4]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
	vector<vector<int>> res;
	vector<int> path;
    vector<vector<int>> combinationSum3(int k, int n) {
    	backtrack(n, k, 0, 0, 1);
    	return res;
    }
    void backtrack(int target, int k, int num, int sum, int startIndex) {
    	if (sum > target || num > k)	return;
    	if (num == k && sum == target) {
    		res.push_back(path);
    		return;
    	}
    	for (int i = startIndex; i <= 9; i++) {
    		sum += i;
    		path.push_back(i);
    		num++;
    		backtrack(target, k, num, sum, i+1);
    		num--;
    		sum -= i;
    		path.pop_back();
    	}
    }
};



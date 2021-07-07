/**	组合总和 	回溯+剪枝

给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的数字可以无限制重复被选取。

说明：
所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 

示例 1：
输入：candidates = [2,3,6,7], target = 7,
所求解集为：
[
  [7],
  [2,2,3]
]
示例 2：
输入：candidates = [2,3,5], target = 8,
所求解集为：
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]

提示：
1 <= candidates.length <= 30
1 <= candidates[i] <= 200
candidate 中的每个元素都是独一无二的。
1 <= target <= 500

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int len = candidates.size();
        vector<vector<int>> res;
        if (!len)	return res;

        vector<int> path;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, len, target, path, res);

        return res;
    }
	void dfs(vector<int>& candidates, int begin, int len, int target, vector<int>& path, vector<vector<int>>& res) {
		if (target == 0) {
			res.push_back(path);
			return;
		}
		for (int i = begin; i < len; i++) {
			//剪枝，前提是候选数组已经排序
			if (target - candidates[i] < 0) {
				break;
			}
			//小剪枝，重要
			if (i > begin && candidates[i]==candidates[i-1]){
				continue;
			}

			path.push_back(candidates[i]);
			//这里变成i+1
			dfs(candidates, i+1, len, target-candidates[i], path, res);
			path.pop_back();
		}
   }
};


/**	组合
联合学习：78子集、77组合、46全排列

给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

示例:
输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combinations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
//	回溯
class Solution {
public:
	vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
    	if (n <= 0 || k <= 0 || k > n) {
            return res;
        }
        vector<int> path;
        dfs(n, k, 1, path);
        return res;
    }
    void dfs(int n, int k, int start, vector<int>& path) {
    	if (path.size() == k) {
    		res.push_back(path);
    		return;
    	}
    	for (int i = start; i <= n-(k-path.size())+1; i++) {
    		path.push_back(i);
    		dfs(n, k, i+1, path);
    		path.pop_back();
    	}
     }
};



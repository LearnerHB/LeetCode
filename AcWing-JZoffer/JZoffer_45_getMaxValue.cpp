/**	礼物的最大价值		🌟动态规划🌟

在一个m×n的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于0）。
你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格直到到达棋盘的右下角。
给定一个棋盘及其上面的礼物，请计算你最多能拿到多少价值的礼物？

注意：
m,n>0

样例：
输入：
[
  [2,3,1],
  [1,7,1],
  [4,6,1]
]
输出：19
解释：沿着路径 2→3→7→6→1 可以得到拿到最大价值礼物。

思路
动态规划，O(n^2)
dp[i][j]表示走到(i, j)这个位置的最大价值，这个位置只能从左边和上边走来
则dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i][j]

*/

class Solution {
public:
    int getMaxValue(vector<vector<int>>& grid) {
    	if (grid.empty())
    		return 0;
    	int x = grid.size(), y = grid[0].size();
    	vector<vector<int>> dp(x, vector<int>(y, 0));	//初始化dp数组
    	dp[0][0] = grid[0][0];
    	//初始化第一行第一列
    	for (int i = 1; i < x; i++)
    		dp[i][0] = dp[i-1][0] + grid[i][0];
    	for (int i = 1; i < y; i++)
    		dp[0][i] = dp[0][i-1] + grid[0][i];
    	//开始遍历
    	for (int i = 1; i < x; i++){
    		for (int j = 1; j < y; j++){
    			dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i][j];
    		}
    	}
    	return dp[x-1][y-1];

    }
};
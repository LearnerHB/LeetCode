/*  不同路径

一个机器人位于一个 m x n网格的左上角 （起始点在下图中标记为 “Start” ）。
机器人每次只能向下或者向右移动一步。
机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
问总共有多少条不同的路径？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-paths
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// Sol 1: 数学方法 排列组合
// 
class Solution {
public:
    int uniquePaths(int m, int n) {
        long ans = 1;
        for (int i = 0; i < min(m-1, n-1); i++){
            ans *= (m-1)+(n-1)-i;
            ans /= i+1;
        }
    }
};

// Sol 2-0: 动态规划 也可参考杨辉三角
// 时间 O(mn) 空间 O(mn)
// dp[i][j] 定义为到达i, j的路径数量
// dp[i][j] = dp[i-1][j] + dp[i][j-1]
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m; i++) dp[i][0] = 1;
        for (int i = 0; i < n; i++) dp[0][i] = 1;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};


// Sol 2-1 优化1: 空间 O(2n)
// 由于dp[i][j] = dp[i-1][j] + dp[i][j-1]
// 因此只需要保留当前行与上一行的数据，也即pre[j]=dp[i-1][j], 两行即可
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> pre(n);
        vector<int> cur(n);
        for (int i = 0; i < n; i++) {
            pre[i] = 1;
            cur[i] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                cur[j] = cur[j-1] + pre[j];
            }
            for (int k = 0; k < n; k++){
                pre[k] = cur[k];
            }
        }
        return pre[n-1];
    }
};

// Sol 2-2 优化2: 空间 O(n)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> cur(n);
        for (int i = 0; i < n; i++) {
            cur[i] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                cur[j] += cur[j-1];
            }
        }
        return cur[n-1];
    }
};









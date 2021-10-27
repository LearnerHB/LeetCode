/*    最大正方形

在一个由 '0' 和 '1' 组成的二维矩阵内，
找到只包含 '1' 的最大正方形，并返回其面积。
*/    
// Sol 1 动态规划
// dp[i,j]表示以坐标(i,j)为右下角的最大正方形
// dp[i,j] = min(dp[i-1,j], dp[i,j-1], dp[i-1,j-1])+1
// 边界条件是当i==0或j==0 dp[i,j]=1
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        int maxSide = 0;
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min(min(dp[i-1][j], dp[i-1][j-1]), dp[i][j-1]) + 1;
                    }
                    maxSide = max(maxSide, dp[i][j]);
                }
            }
        }
        return maxSide * maxSide;
    }
};
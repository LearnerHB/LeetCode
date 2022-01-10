/*    最佳买卖股票时期含冷冻期

给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。​
设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。

示例:
输入: [1,2,3,0,2]
输出: 3 
解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
*/    

/* Sol DP 
用dp[i]表示第i天 结束之后 的累计最大收益。
关于冷冻期，只要在今天想买入的时候判断一下前一天是不是刚卖出即可。

每天结束可以有三种状态:
1. 不持股，且当天未卖出。最大收益dp[i][0]
2. 持股，且当天未卖出。最大收益dp[i][1]
3. 不持股，且当天卖出。最大收益dp[i][2]

初始化:
dp[0][0] = 0
dp[0][1] = -prices[0]   // 即第0天仅买入
dp[0][2] = 0            // 即第0天既买入又卖出

状态转移:
1. 第i天结束后不持股且无卖出的状态，前提是i-1天也不持有股票，即
    1) i-1天不持股且未卖出，dp[i-1][0]
    2) i-1天不持股且卖出，dp[i-1][2]
所以 dp[i][0] = max(dp[i-1][0], dp[i-1][2])
2. 第i天结束后持股的状态，前提是i-1天持股或i天买入，即
    1) i-1天持股且未卖出，dp[i-1][1]
    2) i-1天不持股且当天未卖出，i天买入，dp[i-1][0]-prices[i]
所以 dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[1])
3. 第i天结束后不持股且当天卖出的状态，前提是i-1天持股而i天卖出，即
    1) i-1天持股且未卖出，i天不持股且当天卖出，dp[i-1][1]+prices[i]
所以 dp[i][2] = dp[i-1][1]+prices[i]

注意：
最后一天的最大收益一定是 不持股 状态下的两种可能（即1和3）

*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        }
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(3));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[0][2] = 0;
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][2]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]);
            dp[i][2] = dp[i-1][1]+prices[i];
        }

        return max(dp[n-1][0], dp[n-1][2]);
    }
};
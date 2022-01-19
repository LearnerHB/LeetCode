/*    零钱兑换

给你一个整数数组 coins ，表示不同面额的硬币；
以及一个整数 amount ，表示总金额。

计算并返回可以凑成总金额所需的 最少的硬币个数 。
如果没有任何一种硬币组合能组成总金额，返回 -1 。

你可以认为每种硬币的数量是无限的。

示例：
输入：coins = [1, 2, 5], amount = 11
输出：3 
解释：11 = 5 + 5 + 1

思路：
DP

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/coin-change
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/    
/* Sol: DP
dp(n)代表总金额n时候最少需要硬币数量.
dp(n) = min(dp(n-m) (m来自coins数组各个数)) + 1
注意如果coins=[2], amount=3, 无法整除的情况需要返回-1
判断金额凑不出的技巧：先初始化DP table各个元素为amount+1
（代表不可能存在的情况）遍历时候如果金额凑不出则不更新，最后结果仍为amount+1
*/ 
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 初始化DP table
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        if (amount==0) return 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i - coins[j] >= 0) {
                    dp[i] = min(dp[i], dp[i - coins[j]]+1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
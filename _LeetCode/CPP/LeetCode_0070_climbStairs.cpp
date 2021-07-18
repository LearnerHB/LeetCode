/*	爬楼梯

假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。
*/

// Sol 1-0: DP 时间O(n) 空间O(n)
// dp[n] = dp[n-1] + dp[n-2];
class Solution {
public:
    int climbStairs(int n) { 
    	vector<int> dp(n+1);
    	dp[0] = 1, dp[1] = 1;
    	for (int i = 2; i <= n; i++) {
    		dp[i] = dp[i-1] + dp[i-2];
    	}
    	return dp[n];
    }
};

// Sol 1-1 优化空间O(1)
class Solution {
public:
    int climbStairs(int n) {
    	int p = 0, q = 0, r = 1;
    	for (int i = 1; i <= n; i++) {
    		p = q;
    		q = r;
    		r = p + q;
    	}
    	return r;
    }
};

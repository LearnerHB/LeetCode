/**	把数字翻译成字符串	🌟动态规划🌟

给定一个数字，我们按照如下规则把它翻译为字符串：
0翻译成”a”，1翻译成”b”，……，11翻译成”l”，……，25翻译成”z”。
一个数字可能有多个翻译。例如12258有5种不同的翻译，它们分别是”bccfi”、”bwfi”、”bczi”、”mcfi”和”mzi”。

请编程实现一个函数用来计算一个数字有多少种不同的翻译方法。

样例
输入："12258"
输出：5

思路
动态规划，O(N)
类比经典的爬楼梯算法(斐波那契数列)，每次可以走1步到2步，问n个台阶有几种走法，这题类似
dp[i] = dp[i-1]+dp[i-2]。这题加上了一些限制条件

dp[i]表示前i位数字有多少种不同的翻译方式
如果第i位翻译成单独的一个字母，那dp[i]=dp[i-1]，这部分是一定可以有的
如果第i位和第i-1位数字可以构成合法的二位数，那dp[i]可以再加上dp[i-2]
*/




class Solution {
public:
    int getTranslationCount(string s) {
    	int n = s.size();
    	vector<int> dp(n+1, 0);
    	dp[0] = 1;
    	for (int i = 1; i <= n; i++){
    		dp[i] = dp[i-1];
    		if (i > 1){	//数位两位以上才可能存在多种翻译情况
    			int tmp = s[i-1]-'0' + (s[i-2]-'0')*10;
    			if (tmp >= 10 && tmp <= 25)
    				dp[i] += dp[i-2];
    		}
    	}
    	return dp[n];
    }
};
/**	剪绳子  🌟

给你一根长度为 n 绳子，请把绳子剪成 m 段（m、n都是整数，2≤n≤58 并且 m≥2）。
每段的绳子的长度记为k[0]、k[1]、……、k[m]。k[0]k[1] … k[m] 可能的最大乘积是多少？
例如当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到最大的乘积18。

样例
输入：8
输出：18

思路
方法1：数学解释和实现
https://blog.csdn.net/qq_23594799/article/details/104060676
https://blog.csdn.net/Koala_Tree/article/details/78932316

方法2：动态规划
设置数组dp[length+1]，dp[i]存储绳长为i时候的最大乘积。
外层for循环从绳长 i 为2的情况开始依次计算，直到 n 结束
内存for循环当绳长为i时，假设第一刀剪在长度j位置，剩下的(i-j)绳子就是可剪可不剪选项
我们就比较二者算出的乘积谁更大。如果继续剪，乘积就是j*dp[i-j]；不继续剪，乘积就是j*(i-j)
依次遍历取最大值就是dp[i]的值

*/

//方法1：数学方法
class Solution {
public:
    int maxProductAfterCutting(int length) {
        if (length == 2)
        	return 1;
        else if (length == 3)
        	return 2;
        if (length % 3 == 0)
        	return (int)pow(3, length/3);
        else if (length % 3 == 1)
        	return 4*(int)pow(3, length/3-1);
        else 
        	return 2*(int)pow(3, length/3);
    }
};

//方法2：动态规划
class Solution {
public:
    int maxProductAfterCutting(int length) {
        vector<int> dp(length+1, 0);
        for (int i = 2; i <= length; i++)
        	for (int j = 1; j < i; j++)
        		dp[i] = max(dp[i], max(j*(i-j), j*(dp[i-j])));
        return dp[length];
    }
};
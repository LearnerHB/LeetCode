/**	连续子数组的最大和

输入一个 非空 整型数组，数组里的数可能为正，也可能为负。
数组中一个或连续的多个整数组成一个子数组。
求所有子数组的和的最大值。

要求时间复杂度为O(n)。

样例
输入：[1, -2, 3, 10, -4, 7, 2, -5]
输出：18 

思路
动态规划

s表示以前一个数为结尾的子数组的最大和
遍历到当前数字为x时，
如果s大于0，则s应该更新为s+x
如果s小于等于0，也就没必要考虑这个s，则s更新为x


*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, s = 0;
        for (auto x : nums){
        	if (s < 0)
        		s = 0;
        	s += x;
        	ans = max(ans, s);
        }
        return ans;
    }
};
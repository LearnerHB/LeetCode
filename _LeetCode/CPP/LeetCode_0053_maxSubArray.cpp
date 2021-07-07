/**	最大子序和   Array / DP / 分治算法

给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

进阶:
如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。

思路
1. 动态规划 时间O(n), 空间O(n) (v1) 或 O(1) (v2)
dp[i]表示以nums[i]为结尾的连续子数组的最大和，取决于是nums[i]单独作为数组还是加上前面的部分
即dp[i] = max(dp[i-1]+nums[i], nums[i]).我们可以只维护一个dp_pre值和一个max值，因为max在过程中就可以不断比较出来
由于是一维的，我们只需要保留一个以前一个数为最后数字的数组的最大和，然后迭代计算当前的最大和就可以
2. 分治算法 不是最优解

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

//	DP v1 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
       	dp[0] = nums[0];
       	int maxA = nums[0];
       	for (int i = 1; i < nums.size(); i++) {
       		dp[i] = max(dp[i-1]+nums[i], nums[i]);
       		maxA = max(dp[i], maxA);
       	}

       	return maxA;
    }
};
//	DP v2
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    	int dp_pre = 0, maxAns = nums[0];
    	for (auto x : nums) {
    		dp_pre = max(dp_pre+x, x);
    		maxAns = max(maxAns, dp_pre);
    	}
    	return maxAns;
    }
};

//
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
    }
};







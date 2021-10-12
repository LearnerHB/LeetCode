/*    乘积最大子数组
    给你一个整数数组 nums, 请你找出数组中乘积最大的连续子数组
    （该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
*/    

// Sol.1 动态规划
// 考虑以位置i的元素结尾的连续子数组的最大值
// 由于存在负数的可能性，所以也需要考虑负的绝对值最大即连续子数组的最小值
// fmax(i) = MAX(fmax(i-1)*ai, fmin(i-1)*ai, ai)
// fmin(i) = MIN(fmax(i-1)*ai, fmin(i-1)*ai, ai)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
    
        int ans = nums[0], maxF = nums[0], minF = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int mx = maxF, mn = minF;
            maxF = max(mx*nums[i], max(nums[i], mn*nums[i]));
            minF = min(mx*nums[i], min(nums[i], mn*nums[i]));
            ans = max(maxF, ans);
        }
        return ans;
    }
};
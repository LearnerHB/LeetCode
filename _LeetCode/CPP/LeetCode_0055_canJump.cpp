/*  跳跃游戏
给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
判断你是否能够到达最后一个下标。

示例 1：
输入：nums = [2,3,1,1,4]
输出：true
解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/jump-game
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

// 解法1： 动态规划 O(n^2) 超出时间限制
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) {
            return true;
        }
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (canJumpTo[j] == true && nums[j] >= i-j) {
                    canJumpTo[i] = true;
                    break;
                }
            }
        }
        return canJumpTo[nums.size()-1];
    }
};

// 解法2：贪心 O(n)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int rightmost = 0;
        for (int i = 0; i < nums.size(); i ++) {
            if (i <= rightmost) {
                rightmost = max(rightmost, i + nums[i]);
                if (rightmost >= nums.size()-1) {
                    return true;
                }
            }
        }
        return false;
    }
};
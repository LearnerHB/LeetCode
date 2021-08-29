/*  在排序数组中查找元素的第一个和最后一个位置

给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

进阶：
你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？

input
[5,7,7,8,8,10]
8

output
[3,4]
*/

// 解法1： 遍历 O(n)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0 || nums[0] > target || nums[n-1] < target) {
            return {-1, -1};
        }
        vector<int> ans;
        int ans_size = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                switch (ans_size)
                {
                case 0:
                case 1:
                    ans.push_back(i);
                    ans_size++;
                    break;
                case 2:
                    ans.pop_back();
                    ans.push_back(i);
                    break;
                default:
                    break;
                }
            }
        }
        switch (ans_size)
        {
        case 0:
            ans.push_back(-1);
            ans.push_back(-1);
            break;
        case 1:
            ans.push_back(ans[0]);
            break;
        default:
            break;
        }

        return ans;
    }
};

// 解法2： 二分法
class Solution {
public:
    // 先找 >= target的第一个位置 l 
    // 再找 > target的第一个位置 r
    // 返回[l, r-1]
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        
        int l = binarySearch(nums, target);
        int r = binarySearch(nums, target+1);
        if (l == n || nums[l] != target) {
            return {-1, -1};
        }
        return {l, r-1};
        
    }

    // 查找值 >= target 的第一个位置
    int binarySearch(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
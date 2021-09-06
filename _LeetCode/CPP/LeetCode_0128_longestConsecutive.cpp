/*    最长连续序列

给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

请你设计并实现时间复杂度为 O(n) 的算法解决此问题。

示例
输入：nums = [100,4,200,1,3,2]
输出：4
解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-consecutive-sequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/    

// Sol 1 排序后遍历 O(nlogn) 不建议
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size()==0) {
            return 0;
        } else if (nums.size()==1) {
            return 1;
        }
        sort(nums.begin(), nums.end());
        int maxLen = 1, curLen = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1] + 1) {
                curLen++;
            } else if (nums[i] == nums[i-1]) {
                continue;
            } else {
                // nums[i] > nums[i-1] + 1
                maxLen = max(maxLen, curLen);
                curLen = 1;
            }
        }
        return max(maxLen, curLen);
    }
};

// Sol 2 哈希表
// 先用哈希表做去重，然后遍历哈希表。判断如果当前数字num是连续序列的第一个数（哈希表中匹配不到num-1的数字）
// 则从这个num开始循环连续匹配序列中的数字。如果当前数字不是连续序列的第一个数（匹配得到num-1），则跳过。
// 外层循环需要O(n)，只有当数字num是连续序列的第一个数的情况下才会进入内层循环，然后在内层循环中匹配连续序列中的数
// 因此数组中的每个数只会进入到内层循环一次。由此，总时间复杂度为O(n)，符合要求
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet;
        for (auto num : nums) {
            numSet.insert(num);
        }
        int maxLen = 0;
        for (auto num : numSet) {
            if (numSet.count(num-1)==0) {
                int curNum = num;
                int curLen = 1;
                while (numSet.count(curNum+1)) {
                    curNum++;
                    curLen++;
                }
                maxLen = max(maxLen, curLen);
            }
        }
        return maxLen;
    }
};
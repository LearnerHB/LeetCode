/* 只出现一次的数字

给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。
找出那个只出现了一次的元素。

说明：
你的算法应该具有线性时间复杂度。
你可以不使用额外空间来实现吗？

示例 1:
输入: [2,2,1]
输出: 1

示例2:
输入: [4,1,2,1,2]
输出: 4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/single-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// Sol 1: 哈希表 时间O(n) 空间O(n)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        int ans;
        for (auto i : nums) {
            map[i] ++;
        }
        for (auto i : nums) {
            if (map[i] == 1)
                ans = i;
        }
        return ans;
    }
};

// Sol 2: 排序后遍历 时间O(n) 空间O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        for (; i < nums.size()-1; i+=2) {
            if (nums[i] != nums[i+1])
                break;
        }
        return nums[i];
    }
};


// Sol 3: 位运算
// 任何数和自身异或结果为0，任何数和0异或结果为自身，异或满足交换律和结合律-->
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (auto i : nums) ans ^= i;
        return ans;
    }
};


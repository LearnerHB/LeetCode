/**	多数元素 	Array / 

给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
你可以假设数组是非空的，并且给定的数组总是存在多数元素。

示例 1:
输入: [3,2,3]
输出: 3

示例 2:
输入: [2,2,1,1,1,2,2]
输出: 2

思路	
1. 排序
排序后中间的数字一定是众数
时间 O(nlogn)	空间 O(logn)	(如果用自己写的排序算法，空间就是 O(1))

2. 哈希表法
时间 O(n)	空间 O(n)

3. Boyer-Moore 投票算法
多数元素数量肯定大于其他元素的总和，即使拿多数元素和其他元素来一一抵消
最后剩下的也是多数元素。遍历数组维护一个多数元素，和多数元素的数量
遇到相同元素就数量++，不同元素就数量--，如果数量变为0就从下一个元素开始重新维护
最后剩下的就是多数元素

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/majority-element
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


*/
//	排序法
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};

//	哈希法
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;
        int maj = 0, cnt = 0;
        for (int num : nums) {
        	++counts[num];
        	if (counts[num] > cnt) {
        		maj = num;
        		cnt = counts[num];
        	}
        }
        return maj;
    }
};

//	最优解，Boyer-Moore 投票算法
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj, num = 0;
        for (int x : nums) {
        	if (!num)			maj = x, num++;
        	else if (x == maj)	num++;
        	else 				num--;
        }
        return maj;
    }
};
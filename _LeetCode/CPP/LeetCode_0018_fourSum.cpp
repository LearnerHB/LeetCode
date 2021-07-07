/**	四数之和

给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d 
使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：
答案中不可以包含重复的四元组。

示例：
给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

思路
四指针，a在最外层循环，里面嵌套b循环，再嵌套双指针c,d包夹求解
注意：需要排序。移动指针时可能出现重复数字的情况。所以要确保移动指针后，对应的数字要发生改变才行

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/4sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    	sort(nums.begin(),nums.end());
        vector<vector<int> > res;
        if(nums.size() < 4)	return res;
        int size = nums.size();
        for (int a = 0; a < size-3; a++) {
        	if (a>0 && nums[a]==nums[a-1])	continue;	//确保a指针不重复
        	for (int b = a+1; b < size-2; b++) {
        		if (b>a+1 && nums[b]==nums[b-1])	continue;	//确保b指针不重复
        		int c = b+1, d = size-1;
        		while (c < d) {
        			if (nums[a]+nums[b]+nums[c]+nums[d]	< target)		c++;
        			else if (nums[a]+nums[b]+nums[c]+nums[d] > target)	d--;
        			else {
        				res.push_back({nums[a],nums[b],nums[c],nums[d]});
        				while(c<d && nums[c+1]==nums[c])	c++;
        				while(c<d && nums[d-1]==nums[d])	d--;
        				c++, d--;
        			}
        		}
        	}
        } 
        return res;
    }
};

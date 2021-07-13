 /*	三数之和
 
给你一个包含 n 个整数的数组nums，判断nums中是否存在三个元素 a，b，c ，
使得a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

// 解法1：排序 + 双指针
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    	sort(nums.begin(), nums.end());
    	vector<vector<int>> ans;
    	if (nums.size() == 0)
    		return ans;
    	//枚举第一个数
    	for (int i = 0; i < nums.size(); i++) {
    		//需要和上一次枚举的数字不同
    		if (i > 0 && nums[i] == nums[i-1])
    			continue;
    		int j = nums.size() - 1;
    		int target = -nums[i];
    		//枚举第二个数
    		for (int k = i + 1; k < j; k++) {
    			//需要和上一次枚举的数字不同
    			if (k > i+1 && nums[k] == nums[k-1])
    				continue;
    			while (k < j && nums[k] + nums[j] > target)
    				j--;
    			if (k == j)
    				break;
    			if ((nums[k] + nums[j] == target)) {
    				ans.push_back({nums[i], nums[k], nums[j]});
    			}
    		}
    	}
    	return ans;
    }
};
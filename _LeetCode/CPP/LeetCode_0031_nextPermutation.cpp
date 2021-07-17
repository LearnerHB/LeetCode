/*	下一个排列

实现获取 下一个排列 的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须 原地 修改，只允许使用额外常数空间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/next-permutation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// 一篇优秀的题解：https://leetcode-cn.com/problems/next-permutation/solution/xia-yi-ge-pai-lie-suan-fa-xiang-jie-si-lu-tui-dao-/
// Sol 1: 
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    	int n = nums.size();
    	if (n <= 1) 
    		return;
    	int i = n - 2, j = n - 1, k = n - 1;
    	// find A[i] < A[j]
    	while (i >= 0 && nums[i] >= nums[j]) {
    		i--;
    		j--;
    	}
    	if (i >= 0) {
    		// find A[i] < A[k]
    		while (nums[i] >= nums[k])	k--;
    		// swap A[i] & A[k]
    		swap(nums[i], nums[k]);
    	}
    	// reverse A[j:end]
    	reverse(nums.begin() + j, nums.end());
    }
};
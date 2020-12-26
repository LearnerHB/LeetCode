/**	找到所有数组中消失的数字

给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。
找到所有在 [1, n] 范围之间没有出现在数组中的数字。

您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 你可以假定返回的数组不算在额外空间内。

示例:
输入:
[4,3,2,7,8,2,3,1]
输出:
[5,6]

思路
1. 哈希表		O(N), 使用额外的空间O(N)
2. 原地修改	O(N), 不使用额外空间
遍历输入数组的每个元素一次。
我们将把 |nums[i]|-1 索引位置的元素标记为负数。
然后遍历数组，若当前数组元素 nums[i] 为负数，说明我们在数组中存在数字 i+1。

作者：LeetCode
链接：https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/solution/zhao-dao-suo-you-shu-zu-zhong-xiao-shi-de-shu-zi-2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
//	原地修改
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
    	for (int i = 0; i < nums.size(); i++) {
    		int index = abs(nums[i]) - 1;
    		if (nums[index] > 0)
    			nums[index] *= -1;
    	}
    	vector<int> res;
    	for (int i = 0; i < nums.size(); i++) {
    		if (nums[i] > 0) {
    			res.push_back(i+1);
    		}
    	}
    	return res;
    }
};
/*	寻找两个正序数组的中位数

给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
请你找出并返回这两个正序数组的中位数。
进阶：你能设计一个时间复杂度为 O(log (m+n)) 的算法解决此问题吗？
示例 1：
	输入：nums1 = [1,3], nums2 = [2]
	输出：2.00000
	解释：合并数组 = [1,2,3] ，中位数 2
示例 2：
	输入：nums1 = [1,2], nums2 = [3,4]
	输出：2.50000
	解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
示例 3：
	输入：nums1 = [0,0], nums2 = [0,0]
	输出：0.00000
示例 4：
	输入：nums1 = [], nums2 = [1]
	输出：1.00000
示例 5：
	输入：nums1 = [2], nums2 = []
	输出：2.00000

思路：
1. 分别遍历，时间O(m+n)，空间O(1)
常规思路当然就是利用双指针由小到大遍历两个数组，然后过程中判断是否已经移动到了合并数组的中位数
也可以先合并数组，不过需要O(m+n)的空间，采用临时变量的话无需开辟新数组.
这种方法无法满足题目进阶要求：O(log(m+n))

如果要把时间复杂度降低到 log(n+n)，需要引入二分的思想，于是想到二分查找

2. 


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

// 分别遍历 O(m+n) 
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) { 
	int m = nums1.size(), n = nums2.size();
	bool odd = (m+n)%2==0?true:false;
	int ptr1 = 0, ptr2 = 0, index = 0, medium = (m+n)/2+1;
	int tmp = 0;
	double res = 0.0;

	while(ptr1 < m && ptr2 < n && index < medium){
		 	
		index++;
		if (index==medium){
			if (odd){
				res = ((double)(tmp + min(nums1[ptr1], nums2[ptr2]))/2.0);
			}else{
				res = (double)min(nums1[ptr1], nums2[ptr2]);
			}
			break;
		}
		tmp = min(nums1[ptr1], nums2[ptr2]);
		if (nums1[ptr1] <= nums2[ptr2]){
			ptr1++;
		}else{
			ptr2++;
		}
	}
	if (ptr1 < m && index < medium){
		while (index < medium){
			index ++;
			if (index==medium){
				if (odd){
					res = ((double)(tmp + nums1[ptr1])/2.0);
				}else{
					res = (double)nums1[ptr1];
				}
				break;
			}
			tmp = nums1[ptr1];
			ptr1++;
		}
	}else if (ptr2 < n && index < medium){
		while (index < medium){
			index ++;
			if (index==medium){
				if (odd){
					res = ((double)(tmp + nums2[ptr2])/2.0);
				}else{
					res = (double)nums2[ptr2];
				}
				break;
			}
			tmp = nums2[ptr2];
			ptr2++;
		}
	}
	return res;
}
};














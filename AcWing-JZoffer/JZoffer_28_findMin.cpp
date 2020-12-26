/**	旋转数组的最小数字

把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个升序的数组的一个旋转，输出旋转数组的最小元素。

例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
数组可能包含重复项。

注意：数组内所含元素非负，若数组大小为0，请返回-1。

样例
输入：nums=[2,2,2,0,1]
输出：0

*/

//方法1：找出第一个小于末尾的元素

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty())
        	return -1;
        int i = 0, j = nums.size() - 1;
        for (i = 0; i <= j && nums[i] >= nums[j]; i++);
        return nums[i];
    }
};

//方法2：二分法
//	二分的本质就是寻找某种性质的分界点，只要找到某种性质，使得区间的前半部分满足，后半部分不满足
//	就可以利用二分把分界点找到。我们可以发现除了旋转数组最后一段数字可能与数组前端数字相同之外
//	其余部分都满足二分性质：旋转节点前面，nums[i]>=nums[0]；旋转节点后面，不满足
//	所以考虑的时候，我们可以不用考虑旋转数组最后的一部分（和数组首元素相同的几个数）

//时间复杂度：二分时间复杂度O(logn)，删除最后一段的时间复杂度O(n)，所以最后是O(n)
class Solution {
public:
    int findMin(vector<int>& nums) {
       	int n = nums.size() - 1;
       	if (n < 0)
       		return -1;
       	while (n > 0 && nums[n] == nums[0])
       		n--;
       	if (nums[n] >= nums[0])	//旋转数组单调增
       		return nums[0];
       	int l = 0, r = n;
       	while(l < r){
       		int mid = l + r >> 1;	// [l, mid], [mid+1, r]
       		if (nums[mid] < nums[0])
       			r = mid;
       		else 
       			l = mid + 1;
       	}
       	return nums[r];
    }
};














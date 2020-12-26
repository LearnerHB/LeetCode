/**	数组中数值和下标相等的元素

假设一个单调递增的数组里的每个元素都是整数并且是唯一的。
请编程实现一个函数找出数组中任意一个数值等于其下标的元素。
例如，在数组[-3, -1, 1, 3, 5]中，数字3和它的下标相等。

样例
输入：[-3, -1, 1, 3, 5]
输出：3
注意:如果不存在，则返回-1。

思路
二分，O(logN)
如果mid数值大于下标，那在这个数字之后的所有数字，数值都大于下标，就继续看前半部分数组即可
反之，mid数值小于下标，那前面的肯定也都小于下标，就只看后半部分数组即可

*/

class Solution {
public:
    int getNumberSameAsIndex(vector<int>& nums) {
        if (nums.empty())	return -1;
        int l = 0, r = nums.size()-1;
        while (l < r) {
        	int mid = l + r >> 1;
        	if (nums[mid] == mid)	return mid;
        	if (nums[mid] > mid)	r = mid;
        	else l = mid + 1;
        }
        if (nums[l] == l)	return l;
        return -1;
    }
};
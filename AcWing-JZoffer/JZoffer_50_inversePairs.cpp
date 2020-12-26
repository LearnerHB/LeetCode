/**	数组中的逆序对	🌟🌟🌟🌟

在数组中的两个数字如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组，求出这个数组中的逆序对的总数。

样例
输入：[1,2,3,4,5,6,0]
输出：6

思路
用归并排序模板求解,数组的逆序对总数等于对半分后两个子数组的内部逆序对总数相加，再加上两个子数组之间逆序对数量
计算子数组之间逆序对可以借助归并排序的过程来巧妙运算

*/

//归并排序， O(nlogn)
class Solution{
public:
	int mergeSort(vector<int>& nums, int left, int right){
		if (left >= right)
			return 0;
		int mid = (left+right)>>1;
		int ans = mergeSort(nums, left, mid) + mergeSort(nums, mid+1, right);
		vector<int> temp;
		int i = left, j = mid + 1;
		//此时两个子数组已经有序，接下来对两个数组进行合并，同时计算之间逆序对
		while (i <= mid && j <= right){
			if (nums[i] <= nums[j])
				temp.push_back(nums[i++]);
			else {	//出现逆序对
				temp.push_back(nums[j++]);
				ans += mid - i + 1;	//在左边子数组里，从 i 到 mid 都大于 当前的 j，都存在逆序对
			}
		}
		while (i <= mid)	temp.push_back(nums[i++]);
		while (j <= right)		temp.push_back(nums[j++]);
		int k = left;
		for (auto x : temp)
			nums[k++] = x;

		return ans;
	}

	int inversePairs(vector<int>& nums){
		return mergeSort(nums, 0, nums.size()-1);
	}
};


//暴力法，n^2，不推荐
class Solution {
public:
    int inversePairs(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        	for (int j = i+1; j < nums.size(); j++)
        		if (nums[i] > nums[j])
        			ans ++;
        return ans; 
    }
};
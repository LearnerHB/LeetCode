/** 数组中出现次数超过一半的数字

数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
假设数组非空，并且一定存在满足条件的数字。

思考题：
假设要求只能使用 O(n) 的时间和额外 O(1) 的空间，该怎么做呢？

样例
输入：[1,2,1,1,3]
输出：1

思路
如果一个数在数组中的数量大于数组元素个数的一半，那么肯定大于其他所有数的数量之和
我们设置一个变量用来计数，初始为1，一个用来保存当前选取的候选数字，初始为数组首数
如果之后的数字和候选数字相同计数器就加一，否则减一，计数器减到零时说明在当前遍历过的数组部分中
候选数字数量和其他数字的数量总和相等，所以在其实可以不需要考虑前面这部分。继续遍历后面部分的时候
最终候选数的数量还是会比其他的数字总和要大

*/
//时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    int moreThanHalfNum_Solution(vector<int>& nums) {
        int count = 1, val = nums[0];
        for (int i = 1; i < nums.size(); i++){
        	if (nums[i] == val)
        		count++;
        	else count--;
        	if (count == 0){
        		val = nums[i];	//注意这里的val定义成i位置的数
        		count = 1;
        	}
        }
        return val;
    }
};




//如果没有时间和空间上的限制，可以简单粗暴使用排序
//sort基于快排，时间O(nlogn)，空间O(logn)
class Solution{
public:
	int moreThanHalfNum_Solution(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
}




/**	找出数组中重复的数字（不修改数组）

给定一个长度为 n+1 的数组nums，数组中所有的数均在 1∼n 的范围内，其中 n≥1
请找出数组中任意一个重复的数，但不能修改输入的数组。

样例
给定 nums = [2, 3, 5, 4, 3, 2, 6, 7]。
返回 2 或 3。
*/


/*
思考：如果只要用O(1)的额外空间，怎么做？

	因为该题没有像13题一样要求判断输入数据的边界问题
    默认输入数据均正常，仅考虑重复问题，无需担心重复之后数据出错需要返回-1
    可以在判断出重复的时候即刻输出

   	注：不用额外空间，又不能修改原来数组，就是不能对数组进行排序

AcWing上大佬的解答：抽屉原理+分治算法

抽屉原理：n+1 个苹果放在 n 个抽屉里，那么至少有一个抽屉中会放两个苹果。

题目中，长度n+1的数组中，数的取值范围是1~n，意味着一定至少有一个数字重复。
采用分治的思想，将取值的区间[1,n]分为[1,n/2]和[n/2+1, n]
(这里的区间指的数的取值范围而非数组下标)
由此可以将问题划分至两个子区间中的一个，如果区间中的数的个数大于区间的长度，那么肯定存在重复数字
以此类推，当我们把区间的长度缩小到1时（只有一个数值），就找到了这个重复数

时间复杂度：每次将区间缩小一般，耗费O(logn)，每次统计两个子区间中的数字时要遍历数组，是O(n)。所以是O(nlogn)
空间复杂度：没有使用额外的空间，O(1)

*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int temp;
	vector<int> nums;
	//Sublime对这部分数据的输入存在隐藏的bug，感觉不太ok
	while ( (cin.peek()!=EOF) && (cin.peek()!='\n') )
	{
		// EOF: Mac/Linux上键盘输入 Ctrl+D；Windows上输入Ctrl+Z
		// 注意： cin.get()会把回车'\n'当作字符读入；而cin>>则会跳过回车或空格
		cin >> temp;
		nums.push_back(temp);
	}
	
	int l = 1, r = nums.size()-1;
	while(l < r)
	{
		int mid = l+r >> 1;
		int s = 0;
		for (auto x : nums)
			s += x>=l && x <= mid;
		if (s > mid - l + 1)
			r = mid;
		else
			l = mid + 1;
	}
	return r;
}



/*	
AcWing提交版本1：类似JZoffer_1题（采用了额外的空间）

class Solution {
public:
    int duplicateInArray(vector<int>& nums) {
        unordered_map<int, int> map;
    	int lastDup = -1;	//用来记录最后一个出现重复的数字
    
    	for (int i = 0; i < nums.size(); i++)
    	{
    		if ( nums[i]<1 || nums[i]>(nums.size()-1) )
    			return -1;
    		if (map.count(nums[i]) <= 0)	//查看表中是否存在某键值对
    			map[nums[i]] = 1;			//标记存在该值
    		else
    			lastDup = nums[i];			//记录重复（更新到最后一次重复）
    	}
    	return lastDup;	//没有重复数字的话lastDup不被更新，返回原值-1
    					//有重复数字的话lastDup被更新为最后一个重复数
    }
};

AcWing提交版本2：排序（修改了原数组）

class Solution{
	public:
    int duplicateInArray(vector<int>& nums) {
		sort(nums.begin(), nums.end());		
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i]==nums[i-1])	
				return nums[i];
		}
		return -1;
    }
};


AcWing提交版本3：利用了抽屉原理、分治算法，不采用额外的空间、不修改原数组

class Solution{
	public:
    int duplicateInArray(vector<int>& nums) {
        int l = 1, r = nums.size()-1;
		while(l < r)
		{
			int mid = (l+r)/2;
			int s = 0;
			for (auto x : nums)
				s += x >=l && x <= mid;
			if (s > mid - l + 1)
				r = mid;
			else
				l = mid + 1;
			return r;
		}
    }
};


*/
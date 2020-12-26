/**	找出数组中重复的数字

给定一个长度为 n 的整数数组 nums，数组中所有的数字都在 0∼n−1 的范围内。
数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。
请找出数组中任意一个重复的数字。

注意：如果某些数字不在 0∼n−1 的范围内，或数组中不包含重复数字，则返回 -1；

样例
给定 nums = [2, 3, 5, 4, 3, 2, 6, 7]。
返回 2 或 3。
*/
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <unordered_map>

using namespace std;

int main(int argc, char const *argv[])
{
	vector<int> nums;
	cin >> nums;
	unordered_map<int, int> map;
	int lastDup = -1;	//用来记录最后一个出现重复的数字
	for (int i = 0; i < nums.size(); i++)
	{
		if ( nums[i]<0 || nums[i]>(nums.size()-1) )
			return -1;
		if (map.count(nums[i]) <= 0)	//查看表中是否存在某键值对
			map[nums[i]] = 1;
		else
			lastDup = nums[i];
	}
	
	return lastDup;	//没有重复数字的话lastDup不被更新，返回原值-1
					//有重复数字的话lastDup被更新为最后一个重复数
}

/*	AcWing提交版本

class Solution {
public:
    int duplicateInArray(vector<int>& nums) {
        unordered_map<int, int> map;
	int lastDup = -1;	//用来记录最后一个出现重复的数字
	for (int i = 0; i < nums.size(); i++)
	{
		if ( nums[i]<0 || nums[i]>(nums.size()-1) )
			return -1;
		if (map.count(nums[i]) <= 0)	//查看表中是否存在某键值对
			map[nums[i]] = 1;
		else
			lastDup = nums[i];
	}
	
	return lastDup;	//没有重复数字的话lastDup不被更新，返回原值-1
					//有重复数字的话lastDup被更新为最后一个重复数
    }
};

*/




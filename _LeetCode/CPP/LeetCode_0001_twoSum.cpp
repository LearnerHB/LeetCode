// Leetcode #1 两数之和

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

void test(){
	cout << "test" << endl;
	return;
}
//方法1：暴力搜索
//执行用时424ms, 内存消耗7.2MB
vector<int> twoSum_0(vector<int>& nums, int target)
{
	    int len=nums.size();

	    for(int i=0;i<len-1;i++)
	    {
	    	for(int j=i+1;j<len;j++)
		    {
		        if(nums[i]+nums[j] == target)

		        	//cout << i << " " << j << endl;

		        return {i, j};
		    }
	    }
	    
	    
	   return {};
}

//方法2：两遍哈希
//执行用时20ms，内存消耗8.4MB
vector<int> twoSum_1(vector<int>& nums, int target){

	unordered_map<int, int> m;

	for (int i = 0; i < nums.size(); i++)
	{
		m[nums[i]] = i;		//初始化hash_map
	}
	
	for (int i = 0; i < nums.size(); i++)
	{
		if (m.find(target - nums[i]) != m.end() && m[target - nums[i]] != i)
		//能在map中找到相应的记录，并且不是同一个元素
		return {i, m[target-nums[i]]};
	}
	return {};
}



//方法3：一遍哈希
//执行用时12ms，内存消耗8.1MB
vector<int> twoSum_2(vector<int>& nums, int target)
{
	unordered_map<int, int> m;

	for (int i = 0; i < nums.size(); i++)
	{
		if (m.find(target - nums[i]) != m.end() && m[target - nums[i]] != i)
		{	//能在map中找到相应的记录，并且不是同一个元素
			return {m[target-nums[i]], i}; ////因为i为较大的元素，此时添加进去的键值都还小于i，所以i在后面
		}
		m[nums[i]] = i;
	}
	return {};
}

int main(int argc, char const *argv[])
{
	vector<int>nums;

	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(11);
	nums.push_back(5);

	int tar = 9;

	twoSum_2(nums, tar);

	return 0;
}



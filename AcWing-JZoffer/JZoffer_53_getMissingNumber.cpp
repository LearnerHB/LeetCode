/**	0到n-1中缺失的数字

一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0到n-1之内。
在范围0到n-1的n个数字中有且只有一个数字不在该数组中，请找出这个数字。

样例
输入：[0,1,2,4]
输出：3

*/

//方法1：二分		O(logN)
//	缺失数字x左边的数组都满足nums[i]==i, x及其右边的数组都不满足。
//	另外，如果所有数字都满足nums[i]==i，说明缺失的是n
class Solution {
public:
    int getMissingNumber(vector<int>& nums) {
        if (nums.empty())	return 0;
        int l = 0, r = nums.size()-1;
        while (l < r){
        	int mid = l + r >> 1;
        	if (nums[mid] != mid)
        		r = mid;
        	else 
        		l = mid + 1;
        }
        if (nums[r]==r)	r++;
        return r;
    }
};

//		也是模拟，但是不需要判断边界
class Solution {
public:
    int getMissingNumber(vector<int>& nums) {
        int l = 0, r = nums.size();
        while (l < r){
        	int mid = l + r >> 1;
        	if (nums[mid] != mid)
        		r = mid;
        	else 
        		l = mid + 1;
        }
        return r;
    }
};

//方法2：等差数列求和-sum，即为缺失的数字		O(N)
class Solution {
public:
    int getMissingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (1+n)*n/2;
        int s = 0;
        for (auto x : nums)
        	s += x;
        return sum - s;
    }
};

//方法3: 模拟  O(N)
class Solution {
public:
    int getMissingNumber(vector<int>& nums) {
        int i = 0;
        for (int i; i < nums.size(); i++)
        	if (i != nums[i])
        		return i;
        return i;
    }
};


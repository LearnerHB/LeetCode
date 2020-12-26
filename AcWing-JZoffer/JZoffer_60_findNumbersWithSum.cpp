/**	和为S的两个数字

输入一个数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。
如果有多对数字的和等于s，输出任意一对即可。
你可以认为每组输入中都至少含有一组满足条件的输出。

样例
输入：[1,2,3,4] , sum=7
输出：[3,4]

思路
1. 哈希表

*/

class Solution {
public:
    vector<int> findNumbersWithSum(vector<int>& nums, int target) {
        unordered_map<int, bool> hash;
        for (auto x : nums){
        	if (hash[target-x])
        		return {x, target-x};
        	else 
        		hash[x] = true;
        }
    }
};
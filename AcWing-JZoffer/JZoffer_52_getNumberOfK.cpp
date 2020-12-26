/**	数字在排序数组中出现的次数	🌟

统计一个数字在排序数组中出现的次数。
例如输入排序数组[1, 2, 3, 3, 3, 3, 4, 5]和数字3，由于3在这个数组中出现了4次，因此输出4。

样例
输入：[1, 2, 3, 3, 3, 3, 4, 5] ,  3
输出：4



*/

//方法1: 直接遍历计数, O(n)
class Solution {
public:
    int getNumberOfK(vector<int>& nums , int k) {
        int cnt = 0;
        for (auto x : nums)
        	if (x == k)
        		cnt ++;
        return cnt;
    }
};

//方法2: 使用有序多重集合multiset, O(n)
class Solution {
public:
    int getNumberOfK(vector<int>& nums , int k) {
        multiset<int> s;
        for (int x : nums)
        	s.insert(x);

        return s.count(k);
    }
};

//方法3: 二分思想，找到数字k的上下边界, O(logN)
class Solution {
public:
    int getNumberOfK(vector<int>& nums , int k) {
        if (nums.empty())	return 0;
        int l1 = 0, r1 = nums.size()-1;
        while (l1<r1){
        	int mid = l1 + r1 >> 1;
        	if (nums[mid] >= k)
        		r1 = mid;
        	else 
        		l1 = mid + 1;
        }

        int l2 = 0, r2 = nums.size()-1;
        while (l2<r2) {
        	int mid = l2 + r2 + 1 >> 1;		//注意这里加了1 
        	if (nums[mid] <= k)
        		l2 = mid;
        	else 
        		r2 = mid - 1;
        }

        if (nums[l1] != k && nums[l2] != k)	return 0;

        return l2 - l1 + 1;
    }
};

//方法4: 借助lower_bound和upper_bound找到上下边界(上边界是最后一个k的下一个)
class Solution {
public:
    int getNumberOfK(vector<int>& nums , int k) {
        if (nums.empty())	return 0;
        int l = lower_bound(nums.begin(), nums.end(), k) - nums.begin();
		int r = upper_bound(nums.begin(), nums.end(), k) - nums.begin();

		return r-l;
    }
};
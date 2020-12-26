/**	滑动窗口的最大值	🌟🌟🌟

给定一个数组和滑动窗口的大小，请找出所有滑动窗口里的最大值。
例如，如果输入数组[2, 3, 4, 2, 6, 2, 5, 1]及滑动窗口的大小3,那么一共存在6个滑动窗口，它们的最大值分别为[4, 4, 6, 6, 6, 5]。
注意：
数据保证k大于0，且k小于等于数组长度。

样例
输入：[2, 3, 4, 2, 6, 2, 5, 1] , k=3
输出: [4, 4, 6, 6, 6, 5]

思路
模拟，双向单调队列
队列存放的是元素的下标。为了维护队列单调性，插入元素如果大于等于队尾元素下标对应值，
则当前队尾不可能再充当某个滑动窗口的最大值，故需要队尾出队
*/

class Solution {
public:
    vector<int> maxInWindows(vector<int>& nums, int k) {
    	deque<int> q;
    	vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
        	if (!q.empty() && i - q.front() >= k)	//判断队头是否需要出队
        		q.pop_front();
        	while (!q.empty() && nums[i] > nums[q.back()])	//维护队列单调性
        		q.pop_back();
        	q.push_back(i);
        	if (i >= k-1)
        		ans.push_back(nums[q.front()]);	//取队头对应元素作为窗口最大元素
        }
        return ans;
    }
};
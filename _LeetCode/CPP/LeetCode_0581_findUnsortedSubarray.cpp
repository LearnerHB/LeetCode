/** 最短无序连续子数组   Array

给定一个整数数组，你需要寻找一个连续的子数组，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。
你找到的子数组应是最短的，请输出它的长度。

示例 1:
输入: [2, 6, 4, 8, 10, 9, 15]
输出: 5
解释: 你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。

说明 :
输入的数组长度范围在 [1, 10,000]。
输入的数组可能包含重复元素 ，所以升序的意思是<=。

思路
最短的连续子数组，其左边的剩余数组有序且值都小于等于当前数组中最小值，其右边的剩余数组有序且值都大于等于当前数组中最大值

1. 先排序，然后比较元素，找到最左和最右的不匹配数字
时间O(NlogN)	空间O(N)
2. 用栈，利用选择排序的思想，先正序遍历数组，数字比前一个大就进栈，不然就是当前数字不在正确位置上，
那就不断出栈直到栈顶元素比当前数字小，假设当前栈顶位置k，那么当前数字的正确位置就是k+1
重复这个过程并遍历完整个数组找到最小的k，这个k就是最短无序连续子数组的左边界。同理逆序遍历数组找到右边界。
时间O(n) 空间O(n)
3. 不用额外空间
类似上面的2，这个算法的核心思想就是，无序子数组中最小元素的正确位置可以决定左边界，最大元素的正确位置可以决定右边界
我们遍历两遍数组可以找到顺序时降序的最小元素min和逆序时升序的最大元素max
我们再次顺逆遍历两遍数组就可以找到从头开始第一个大于min的元素和从尾开始第一个小于max的元素，就是他们的正确位置
时间O(n) 空间O(1)

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

//	1. 排序法
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> nums_sorted = nums;
        sort(nums_sorted.begin(), nums_sorted.end());
        int start = nums.size(), end = 0;
        for (int i = 0; i < nums.size(); i++) {
        	if (nums_sorted[i] != nums[i]){
        		start = min(start, i);
        		end = max(end, i);
        	}
        }
 		return ((end-start>=0)?end-start+1:0);
    }
};

//	2. 栈
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> st;
        int l = nums.size(), r = 0;
        for (int i = 0; i < nums.size(); i++) {
        	while (!st.empty() && nums[st.top()]>nums[i]){
        		l = min(l, st.top());
        		st.pop();
        	}
        	st.push(i);
        }
        st.clear();
        for (int i = nums.size()-1; i>=0; i--) {
        	while (!st.empty() && nums[st.top()]<nums[i]){
        		r = max(r, st.top());
        		st.pop();
        	}
        	st.push(i);
        }
        return r-l>0 ? r-l+1 : 0;
    }
};

//	3. 不使用额外空间
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int len =nums.size();
        int num_min=INT_MAX;
        int num_max=INT_MIN;
        //一次扫描，同时求出无序子数组中最小元素和最大元素
        for(int i=0;i<len-1;i++){
            if(nums[i+1]<nums[i]){
                num_min=min(nums[i+1],num_min);
                num_max=max(nums[i],num_max);
            }
        }
        //确定最小元素的正确位置
        int l=0;
        for(int i=0;i<len-1;i++){
            if(nums[i]>num_min) {
                l=i;
                break;
            }
        }
        //确定最大元素的正确位置
        int r=0;
        for(int i=len-1;i>-1;i--){
            if(nums[i]<num_max){
                 r=i;
                 break;
            }
        }
        //返回结果这里需要特殊处理一下数组已是升序如[1,2,3,4]，l=0，r=0的特殊情况
        if(!r&&!l) return 0;
        else return r-l+1;

    }
};

/**	最小的K个数	🌟🌟

输入n个整数，找出其中最小的k个数。

注意：
数据保证k一定小于等于输入数组的长度;
输出数组内元素请按从小到大顺序排序;

样例
输入：[1,2,3,4,5,6,7,8] , k=4
输出：[1,2,3,4]

思路
堆排序 O(nlogk)
维护一个大小k的最大堆，维护最小的k个数，每次取新的数都和堆顶元素对比
如果比堆顶元素小，就放入堆中，踢出堆顶元素，保存堆里k个最小元素

*/

class Solution {
public:
    vector<int> getLeastNumbers_Solution(vector<int> input, int k) {
    	priority_queue<int> heap;
    	vector<int> ans;
    	for (auto x : input){
    		heap.push(x);
    		if (heap.size() > k)
    			heap.pop();
    	}
    	while (heap.size()){
    		ans.push_back(heap.top());
    		heap.pop();
    	}
    	reverse(ans.begin(), ans.end());
    	return ans;
    }
};








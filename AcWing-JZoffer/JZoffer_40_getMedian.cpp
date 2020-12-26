/**	数据流中的中位数	🌟🌟

如何得到一个数据流中的中位数？
如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。

样例

输入：1, 2, 3, 4
输出：1,1.5,2,2.5
解释：每当数据流读入一个数据，就进行一次判断并输出当前的中位数。

思路
大小堆的经典应用。最大堆存放小于中位数的集合，最小堆存放大于中位数的集合
取值的时候，若总数奇数，就取最大堆的堆顶最大数，偶数则取两个堆顶平均
放入的时候，若总数偶数，就放最大堆

*/

//方法1：大小堆
class Solution{
public:
	priority_queue<int> maxheap;
	priority_queue<int, vector<int>, greater<int> > minheap;
	
	void insert(int num){
		maxheap.push(num);
		//放入之后，较小部分最大值大于较大部分最小值的话，进行交换
		//注意需要先判断最小堆中有没有元素
		if (minheap.size() && maxheap.top() > minheap.top()){
			int max_i = maxheap.top(), min_i = minheap.top();
			maxheap.pop(), minheap.pop();
			maxheap.push(min_i), minheap.push(max_i);
		}
		//数量不均衡时候调整
		if (maxheap.size() > minheap.size() + 1){
			minheap.push(maxheap.top());
			maxheap.pop();
		}
	}

    double getMedian(){
    	if (maxheap.size() + minheap.size() & 1)//总数奇数
    		return maxheap.top();
    	else 
    		return (maxheap.top() + minheap.top()) / 2.0;
    }
};



//方法2：当然如果不考虑时间复杂度的话也可以每次都sort
class Solution {
public:
	vector<int> nums;
    void insert(int num){
        nums.push_back(num);
    }

    double getMedian(){
    	int len = nums.size();
    	int mid = len/2;
        sort(nums.begin(), nums.end());
        if (nums.size() % 2 == 0)
        	return ((double)nums[mid]+(double)nums[mid-1]) / 2;
        else 
        	return nums[mid];
    }
};
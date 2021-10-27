/*     数组中的第K个最大元素

给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例
输入 [3,2,3,1,2,4,5,5,6] 和 k = 4
输出 4
*/    
// Sol 1 粗暴的直接使用标准库   时间O(logN) 默认快排
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()-k];
    }
};

// Sol 2 基于随机选择的快速排序
// 按照常规方式做快排时候，每次有一个元素会对应到其最终的正确位置上
// 如果排序过程中这个位置等于我们目标的k位次，我们可以直接返回，不需进行后续的排序
// 进一步改进，如果这个位置小于k，我们可以只递归右子区间；大于k就只递归左子区间，提高效率
class Solution {
public:
    int quickSock(vector<int>& nums, int l, int r, int index) {
        int q = randomPartition(nums, l, r);
        if (q == index) {
            return nums[q];
        } else if (q < index) {
            return quickSock(nums, q+1, r, index);
        } else {
            return quickSock(nums, l, q-1, index);
        }
    }
    int randomPartition(vector<int>& nums, int l, int r) {
        int i = rand() % (r-l+1) + l;
        swap(nums[i], nums[r]);
        return partition(nums, l, r);
    }
    int partition(vector<int>& nums, int l, int r) {
        int x = nums[r], i = l;
        for (int j = l; j < r; j++) {
            if (nums[j] <= x) {
                swap(nums[i++], nums[j]);
            }
        }
        swap(nums[i], nums[r]);
        return i;
    }
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0));
        return quickSock(nums, 0, nums.size()-1, nums.size()-k);
    }
};

// Sol 3 推荐解法 维护k个元素的小根堆 
// 优先队列 直接采用priority_queue的数据结构
#include <queue>
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // 如果是priority_queue<int>，默认大顶堆，即priority_queue<int, vector<int>, less<int> >
        priority_queue<int, vector<int>, greater<int> > small_heap; 
        for (int i = 0; i < nums.size(); i++) {
            if (i < k) {
                small_heap.push(nums[i]);
            } else if (nums[i] > small_heap.top()) {
                small_heap.pop();
                small_heap.push(nums[i]);
            }
        }
        return small_heap.top();
    }
};
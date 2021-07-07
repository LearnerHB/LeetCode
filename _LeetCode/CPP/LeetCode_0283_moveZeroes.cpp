/**	移动零     Array / 双指针

给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

示例:
输入: [0,1,0,3,12]
输出: [1,3,12,0,0]

说明:
必须在原数组上操作，不能拷贝额外的数组。
尽量减少操作次数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/move-zeroes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


*/
//	开辟另一个数组来存储, 时间O(N),空间O(N)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> ans;
        int nums_zeros = 0;

        for (int i = 0; i < nums.size(); i++)
        	nums_zeros += (nums[i]==0);

        for (int i = 0; i < nums.size(); i++)
        	if (nums[i] != 0)
        		ans.push_back(nums[i]);

        for (int i = 0; i < nums_zeros; i++)
        	ans.push_back(0);

        for (int i = 0; i < nums.size(); i++)
        	nums[i] = ans[i];
    }
};

//	双指针，空间最优，操作局部优化
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow, fast = 0;
        //	fast遍历数组，slow负责复制fast非零的数字到数组头部，不会覆盖到未遍历的非零数
        for (; fast < nums.size(); fast++) 
        	if (nums[fast] != 0) 
        		nums[slow++] = nums[fast];
        for (; slow < nums.size(); slow++)
        	nums[slow] = 0;
    }
};

//	双指针，最优化解法，类似快排，以0为中间点，非零放左，零移右; 
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //假设i快j慢，要用'交换'的思想来处理，要让j在0的位置，i在非零的位置
        for (int i = 0, j = 0; i < nums.size(); i++) {
        	if (nums[i] != 0) {
        		if (i > j) {
        			nums[j] = nums[i];
        			nums[i] = 0;
        		}
        		j++;
        	}
        }
    }
};

//	C++ STL解决方案
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        stable_partition(nums.begin(), nums.end(), [](int a) {return a!= 0;});
    }
};








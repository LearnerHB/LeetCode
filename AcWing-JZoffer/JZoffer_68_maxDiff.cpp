/**	股票的最大利润

假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖一次该股票可能获得的利润是多少？
例如一只股票在某些时间节点的价格为[9, 11, 8, 5, 7, 12, 16, 14]。
如果我们能在价格为5的时候买入并在价格为16时卖出，则能收获最大的利润11。

样例
输入：[9, 11, 8, 5, 7, 12, 16, 14]
输出：11

思路
维护一个min值，表示遍历到第i个数字的时候，前i-1个数字中最小的数字
这时候就能计算出到这个数字的时候卖出得到的利益，并不断维护这个maxDiff

*/

class Solution {
public:
    int maxDiff(vector<int>& nums) {
        if (nums.empty() || nums.size() < 2)
        	return 0;
        int min = nums[0];
        int max_diff = nums[1] - min;

        for (int i = 2; i < nums.size(); i++) {
        	if (nums[i-1] < min)
        		min = nums[i-1];
        	int cur_max_diff = nums[i] - min;
        	if (cur_max_diff > max_diff)
        		max_diff = cur_max_diff;
        }
        
        //如果最大收益小于0，那就选择”不买卖“，收益为0
        return (max_diff<0?0:max_diff);
    }
};
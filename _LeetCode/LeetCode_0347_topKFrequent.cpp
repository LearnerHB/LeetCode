/**		前k个高频元素 		哈希 / 堆

给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

示例 1:
输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
示例 2:
输入: nums = [1], k = 1
输出: [1]

提示：
你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。
题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的。
你可以按任意顺序返回答案。

思路
先遍历数组，哈希记录频率，再建立最小堆，维护k个出现频率最大的元素，堆顶为这k个当中频率最小的
遍历哈希来为最小堆添加元素，每次都和堆顶比较

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/top-k-frequent-elements
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
	static bool cmp(pair<int, int>& m, pair<int, int>& n) {
		return m.second > n.second;
	}
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for (auto num : nums) hash[num]++;
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(&cmp)> q(cmp);	//★
    	for (auto& [num, count] : hash) {
    		if (q.size() == k) {
    			if (q.top().second < count){
    				q.pop();
    				q.emplace(num, count);	//emplace自动为num,count构造pair，用push的话需要先自行为num和count创建pair，耗内存
    			}
    		}
    		else q.emplace(num, count);
    	}
    	vector<int> res;
    	while (!q.empty()) {
    		res.emplace_back(q.top().first);
    		q.pop();
    	}
    	return res;
    }
};

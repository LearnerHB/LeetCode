/**	数字排列(有重复) 🌟

输入一组数字（可能包含重复数字），输出其所有的排列方式。

样例
输入：[1,2,3]
输出：
      [
        [1,2,3],
        [1,3,2],
        [2,1,3],
        [2,3,1],
        [3,1,2],
        [3,2,1]
      ]

无重复数字求全排列
https://www.acwing.com/solution/LeetCode/content/124/
有重复数字求全排列
https://www.acwing.com/solution/LeetCode/content/126/

思路
把排列的题目，想象成一个萝卜一个坑，按一定顺序填坑
1. 先对所有数字从小到大排序，相同的数字就会放在一起
2. 左到右枚举每个数，每次将其放在一个空位上
3. 对于相同数，人为定序以避免重复计算；在dfs时候记录一个额外的状态来记录
上一个相同数字存放的位置Start。这样在枚举当前数字时候只需要枚举start+1,start+2,…,n这些位置
（也就是人为规定，对于重复数字，其在排列中所处的位置只能在上一个该数字的位置之后，这样就避免了重复排列）
4. 递归前和回溯的时候更新状态

时间复杂度：搜索树中最后一层共n!个节点，前面所有层加一起的节点数量相比与最后一层节点数是无穷小量可以忽略
最后一层节点记录方案的计算量是O(n)。所以总时间复杂度是O(n*n!)
 


*/

class Solution {
public:
	vector<bool> st;	//表示当前坑位是否已经被占
	vector<int> path;
	vector<vector<int>> ans;

    vector<vector<int>> permutation(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        st = vector<bool>(nums.size(), false);
        path = vector<int>(nums.size());
        dfs(nums, 0, 0);
        return ans;
    }

    //nums传递引用；u表示当前数字的数组序号；start表示哪个位置之后可以放入当前数
    void dfs(vector<int>& nums, int u, int start){
    	if (u == nums.size()){
    		ans.push_back(path);
    		return;
    	}

    	//i作为可以放入的坑位的起始序号
    	for (int i = start; i < nums.size(); i++){
    		if (!st[i]){//当前坑位还在
    			st[i] = true;
    			path[i] = nums[u];
    			if (u+1 < nums.size() && nums[u+1] != nums[u])
    				dfs(nums, u+1, 0);
    			else 
    				dfs(nums, u+1, i+1);
    			st[i] = false;
    		}	
    	}
    }
};

/**	数字排列(无重复) 🌟

给出一列互不相同的整数，返回其全排列。

*/

class Solution{
public:
	vector<vector<int>> ans;
	vector<bool> st;
	vector<int> path;

	vector<vector<int>> permute(vector<int>& nums) {

		st = vector<bool>(nums.size(), false);
		dfs(nums, 0);
		return ans;
	}

	void dfs(vector<int>& nums, int u){
		if (u == nums.size()){
			ans.push_back(path);
			return;
		}

		for (int i = 0; i < nums.size(); i++){
			if (!st[i]){
				st[i] = true;
				path.push_back(nums[i]);
				dfs(nums, u+1);
				st[i] = false;
				path.pop_back();
			}
		}
	}
	
};














/**	数组中只出现一次的两个数字	🌟🌟

一个整型数组里除了两个数字之外，其他的数字都出现了两次。
请写程序找出这两个只出现一次的数字。
你可以假设这两个数字一定存在。

样例
输入：[1,2,3,3,4,4]
输出：[1,2]

思路
1. 哈希表，时间复杂度O(n)，空间复杂度O(n^2)，有点浪费
2. 异或，时间复杂度O(n)，空间复杂度O(1)
任何一个数字异或他自己都等于0，从头到尾异或所有数字之后，
出现两次的数字相互异或会变成0，所以最终的结果会是x异或y，也即两个仅出现一次的数字的异或
x^y这个异或结果一定不为0，因为x不等于y，所以肯定至少有一位为1。
我们找到这个结果中第一个为1的位，在这个位上x和y的二进制表示肯定相反
所以我们可以对于原先的数组，根据该位是否为1，将其划分成两个数组，这样两个数组中
就分别存在一个仅出现一次的数字。我们再分别对两个数组进行异或运算，最后分别剩下的结果
就是x和y

*/

//方法1：哈希表
class Solution {
public:
    vector<int> findNumsAppearOnce(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> hash;
        for (auto x : nums)
        	hash[x]++;
        for (auto x : nums)
        	if (hash[x] == 1)
        		ans.push_back(x);
        return ans;
    }
};

//方法2：异或
class Solution {
public:
    vector<int> findNumsAppearOnce(vector<int>& nums) {
        int xy = 0;
        for (int k : nums)
        	xy ^= k;
        //循环结束后 xy = x^y

        int k = 0;
        while (0 == (xy >> k & 1))
        	k++;
        //循环结束之后k就是xy二进制表示中第一个为1的位

        //从xy中分离x和y
        int x = 0;
        for (int num : nums)
        	if ((num >> k & 1) == 1)
        		x ^= num;

        int y = x ^ xy;

        return {x, y};
    }
};






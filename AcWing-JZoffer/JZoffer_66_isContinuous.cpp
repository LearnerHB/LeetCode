/**	扑克牌的顺子  🌟🌟

从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。
2～10为数字本身，A为1，J为11，Q为12，K为13，大小王可以看做任意数字。
为了方便，大小王均以0来表示，并且假设这副牌中大小王均有两张。

样例1
输入：[8,9,10,11,12]
输出：true

样例2
输入：[0,8,9,11,12]
输出：true

思路
排序，去重，求空隙，计算
1. 不能出现两张相同的(除了大小王)
2. 排序后两个相邻数字的差值减去1(也就是空隙的个数)不能大于0的个数

*/

class Solution {
public:
    bool isContinuous( vector<int> numbers ) {
        if (!numbers.size())
        	return false;
        sort(numbers.begin(), numbers.end());
        int num_0 = 0;
        for (int i = 0; i < numbers.size()-1; i++) {
        	if (numbers[i] == 0)
        		num_0++;
        	else{
        		//是否连续两数相等
        		if (numbers[i]==numbers[i+1])
        			return false;
        		//正常情况
        		if (numbers[i+1]-numbers[i]==1)
        			continue;
        		//空隙个数
        		if (numbers[i+1]-numbers[i]-1 > num_0)
        			return false;
        		//维护0的个数
        		num_0 -= (numbers[i+1]-numbers[i]-1);
        	}
        }
        return true;
    }
};
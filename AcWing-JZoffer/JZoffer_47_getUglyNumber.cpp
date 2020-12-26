/**	丑数  🌟🌟

我们把只包含质因子2、3和5的数称作丑数（Ugly Number）。
例如6、8都是丑数，但14不是，因为它包含质因子7。
求第n个丑数的值。

样例
输入：5
输出：5
注意：习惯上我们把1当做第一个丑数。

思路
三路归并
1. 三指针的思想，所以定义3个指针i, j, k。
2. vector存储的是丑数数组，一开始只有1个1，后面 动态添加元素进vector。
3. t取出的是3个指针分别指向的3个子数组(2 3 5)中的最小值。如果最小值是3个子数组中的哪一个，
	就把里面的指针i j k 增1。因为可能同时出现在多个数组，所以用3个if来表示。
4. 最后输出vector的最后一位，就是第n个丑数。

*/

//三路归并
class Solution{
public:
	int getUglyNumber(int n){
		if (n == 1)	return n;
		vector<int>	ans(1,1);		//存储丑数数组，一开始只有一个1
		int i = 0, j = 0, k = 0;
		while (ans.size() < n){
			int tmp = min(ans[i]*2, min(ans[j]*3, ans[k]*5));
			ans.push_back(tmp);

			if (ans[i]*2 == tmp)	i++;
			if (ans[j]*3 == tmp)	j++;
			if (ans[k]*5 == tmp)	k++;
		}
		return ans.back();
	}
};

//粗暴法, 会超时, 千万别用，引以为戒
class Solution {
public:
    int getUglyNumber(int n) {
    	int i = 0;
        while (n){
        	i++;
        	if (isUglyNumber(i)){
        		n--;
        	}
        }
        return i;
    }

    bool isUglyNumber(int num){
    	while (!num%2)	num /= 2;
    	while (!num%3)	num /= 3;
    	while (!num%5)	num /= 5;
    	if (1==num)
    		return true;
    	else 
    		return false;
    }
};
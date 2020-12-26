/**	圆圈中最后剩下的数字	约瑟夫环 🌟🌟

0, 1, …, n-1这n个数字(n>0)排成一个圆圈，从数字0开始每次从这个圆圈里删除第m个数字。
求出这个圆圈里剩下的最后一个数字。

样例
输入：n=5 , m=3 
输出：3

思路
1. 环形链表模拟	O(mn)
用模板库中的list来模拟环形链表，当迭代器扫描到链表末尾的时候将其移到链表的头部
2. 分析规律直接找出	O(n) 剑指p302
https://www.acwing.com/solution/content/796/
f(n,m) = 
{
	0,				n=1
	[f(n-1,m)+m]%n 	n>1
}
*/

//环形列表模拟
#include <list>
class Solution {
public:
    int lastRemaining(int n, int m){
        if (n<1 || m<1)	return -1;

        list<int> nums;
        for (int i = 0; i < n; i++)
        	nums.push_back(i);
        auto it = nums.begin();

        while (nums.size() > 1) {
        	for (int i = 1; i < m; i++) {
        		it++;
        		if (it == nums.end())
        			it = nums.begin();
        	}
        	it = nums.erase(it);	//返回下一个位置的迭代器
        	if (it == nums.end())
        		it = nums.begin();
        }
        return nums.front();
    }
};

//公式
class Solution {
public:
    int lastRemaining(int n, int m){
        if (n<1 || m<1)	return -1;
        int last = 0;
        for (int i = 2; i <= n; i++)
        	last = (last+m) % i;

       	return last;
    }
};





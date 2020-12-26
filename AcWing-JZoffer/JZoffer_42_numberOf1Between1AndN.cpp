/**	从1到n整数中1出现的次数		🌟🌟🌟

输入一个整数n，求从1到n这n个整数的十进制表示中1出现的次数。
例如输入12，从1到12这些整数中包含“1”的数字有1，10，11和12，其中“1”一共出现了5次。

样例
输入： 12
输出： 5

思路
我们按数字的位来做运算，只考虑当前位是1的时候可以有几种情况，
相当于把这些所有整数中当前位上出现的1都加起来。

时间复杂度 O(logn)
空间复杂度 O(1)

*/

class Solution {
public:
    int numberOf1Between1AndN_Solution(int n) {
       	 int sum = 0;
       	 int left = n, right = 0;
       	 int digit = 1;		//表示right部分数位容纳的数字的数量(如果右边有2位，就是00~99，digit为100 (初始右边不含数位则置1
       	 while (left){
       	 	const int cur = left % 10;	//从低位开始算起，将 c 位上 1 的总个数分为两部分计算
       	 							//1. 考虑左边数位的影响: sum += left * digit; (左边是 0~left-1 的数字中可以让 c 位枚举出 0~9，也就一定包含 1
       	 							//2. 考虑右边数位与c位自身的影响: 如果 c 位是 0, sum 不加；如果 c 位是 1，sum += (right+1)，如果 c 位大于 1，sum += digit
       	 	left /= 10;
       	 	sum += left * digit;
       	 	if (cur > 1)			sum += digit;
       	 	else if (cur == 1)	sum += right + 1;
       	 	right += cur * digit;
       	 	digit *= 10;
       	 }
       	 return sum;
    }
};
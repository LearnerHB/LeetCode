/**	数字序列中某一位的数字	🌟模拟

数字以0123456789101112131415…的格式序列化到一个字符序列中。
在这个序列中，第5位（从0开始计数）是5，第13位是1，第19位是4，等等。
请写一个函数求任意位对应的数字。

样例
输入：13
输出：1

思路
逐个区间判断，循环减去之前的区间
时间复杂度 O(n)

*/


class Solution {
public:
    int digitAtIndex(int n) {
        typedef long long LL;
        LL len = 1, nums = 9;	//len表示当前所处区间每个数的长度,nums表示当前区间数字总数
        n -= 1;					//先减去第一个数0，这样一位的数也剩下9个，等于nums
        while (n > len * nums){
        	n -= len * nums;
        	len ++;
        	nums *= 10;
        }
        LL val = pow(10, len-1) + n/len;	//算出目标数位的完整数字
        string s = to_string(val);

        return s[n%len] - '0';
    }
};
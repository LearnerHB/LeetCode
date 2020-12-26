/**	求1+2+…+n 	🌟

求1+2+…+n,要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

样例
输入：10
输出：55

思路
1. 定义n*(n+1)的二维char数组(每个char只占用1)，求size，然后>>1(相当于除以2)
2. 递归？递归需要用到退出循环判断，不用用if的话，要使用&&短路运算来终止判断

*/

//方法1
class Solution {
public:
    int getSum(int n) {
        char a[n][n+1];
        return sizeof(a)>>1;
    }
};

//方法2：递归
class Solution {
public:
	int getSum(int n) {
		int ans = n;
		(n>0) && (ans += getSum(n-1));
		return ans;
	}
};
/**	不用加减乘除做加法	🌟🌟

写一个函数，求两个整数之和，要求在函数体内不得使用＋、－、×、÷ 四则运算符号。

样例
输入：num1 = 1 , num2 = 2
输出：3

思路
位运算+全加器
位运算实现的加法减法操作其实是全加器之间的操作。
在运算的过程中要具有一个sum表示a,b全加后的结果，一个carry表示进位的情况。
在算法中可以在每次结束后把sum的值赋给a，carry的值赋给b，实现类似全加器的运算。
因为b不断左移，所以总有一天会变成0，这时候while就跳出来。
答案一直存储在a里面，也就是异或(不进位加法)中，最后进位b=0，a没有必要进位了
最后a的值即为结果。

*/


class Solution {
public:
    int add(int num1, int num2){
        while (num2) {
        	int sum = num1 ^ num2;			//不进位的加法
        	int carry = (num1 & num2) << 1;	//进位
        	num1 = sum;
        	num2 = carry;
        }
        return num1;
    }
};
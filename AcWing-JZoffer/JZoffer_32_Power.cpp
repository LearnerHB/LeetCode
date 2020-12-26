/**	数值的整数次方		🌟🌟

实现函数double Power(double base, int exponent)，求base的 exponent次方。
不得使用库函数，同时不需要考虑大数问题。

注意：
不会出现底数和指数同为0的情况
当底数为0时，指数一定为正

样例1
输入：10 ，2
输出：100

样例2
输入：10 ，-2  
输出：0.01

思路
(模拟)
由于指数是int范围，可能很大，所以使用快速幂求解
注意当指数是负数的时候，需要先取指数的绝对值，然后将乘积的倒数作为答案

*/
class Solution {
public:
    double Power(double base, int exponent) {
        typedef long long LL;
        bool is_minus = exponent < 0;
        double res = 1;
        for (LL k = abs(LL(exponent)); k; k >>= 1){
        	if (k & 1)	//位运算，这句判断二进制末位是否为1
        		res *= base;
        	base *= base;
        }
        if (is_minus)
        	res = 1/res;
        return res;
    }
};
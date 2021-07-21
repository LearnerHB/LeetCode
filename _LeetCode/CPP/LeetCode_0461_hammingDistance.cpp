/*	汉明距离

两个整数之间的 汉明距离 指的是这两个数字对应二进制位不同的位置的数目。
给你两个整数 x 和 y，计算并返回它们之间的汉明距离。

0 <= x, y <= 2^31 - 1
*/

// Tips 结合 异或


// Sol 1: 内置位计数功能	时间O(1) 空间O(1)
// 大多数语言内置了计算二进制表达式中1的数量的函数
class Solution {
public:
    int hammingDistance(int x, int y) {
    	return __builtin_popcount(x ^ y);
    }
};

// Sol 2: 移位实现位计数 时间(logC) C是元素数据范围，本题中logC=log2^31=31   空间O(1)
class Solution {
public:
    int hammingDistance(int x, int y) {
    	int s = x ^ y, res = 0;
    	while (s) {
    		res += s & 1;
    		s >>= 1;
    	}
    	return res;
    }	
};

// Sol 3: Brian Kernighan 算法
// 基本思路同Sol 2. 如果能在移位过程中跳过两个1之间的0，可以减少循环的数量
// 参考：https://leetcode-cn.com/problems/hamming-distance/solution/yi-ming-ju-chi-by-leetcode-solution-u1w7/
class Solution {
public:
    int hammingDistance(int x, int y) {
    	int s = x ^ y, res = 0;
    	while (s) {
    		s &= s-1;
    		res++;
    	}
    	return res;
    }
};

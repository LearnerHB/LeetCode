/**	斐波那契数列
输入一个整数 n，求斐波那契数列的第 n 项。

假定从0开始，第0项为0。(n<=39)

样例

输入整数 n=5, 返回 5

思路：直接模拟
时间复杂度：O(n)

*/

class Solution {
public:
    int Fibonacci(int n) {
        int a = 0, b = 1;
        while(n--){
        	int c = a + b; 
        	a = b, b = c;
        }
        return a;
    }
};
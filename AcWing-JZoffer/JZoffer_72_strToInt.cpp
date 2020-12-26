/**	把字符串转换成整数

请你写一个函数StrToInt，实现把字符串转换成整数这个功能。
当然，不能使用atoi或者其他类似的库函数。

样例
输入："123"
输出：123

注意:
你的函数应满足下列条件：
1. 	忽略所有行首空格，找到第一个非空格字符，可以是 ‘+/−’ 表示是正数或者负数，
	紧随其后找到最长的一串连续数字，将其解析成一个整数；
2. 	整数后可能有任意非数字字符，请将其忽略；
3. 	如果整数长度为0，则返回0；
4. 	如果整数大于INT_MAX(2^31 − 1)，请返回INT_MAX；
	如果整数小于INT_MIN(−2^31) ，请返回INT_MIN；
*/

class Solution {
public:
    int strToInt(string str) {
        int size = str.size();
        long long number = 0;	//*3 如果整数长度为0，number也不会改变，返回0没毛病
        bool positive = true;

        if (isalpha(str[0]))	return 0;	//防止"la123"这种情况
        for (int i = 0; i < size; i++) {
        	if (str[i] != ' ') {
        		if (str[i] == '-')
        			positive = false;
        		else if (str[i] == '+');
        		else if (str[i] >= '0' && str[i] <= '9'){
        			number = (number*10 + str[i]-'0');
        		}
        	}
        }

        if (number==0)				return 0;
        else if (number < INT_MIN)	return INT_MIN;
        else if (number > INT_MAX)	return positive?INT_MAX:INT_MIN;

        return positive?number:-number;
    }
};
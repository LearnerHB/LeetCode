/**	左旋转字符串

字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
请定义一个函数实现字符串左旋转操作的功能。
比如输入字符串"abcdefg"和数字2，该函数将返回左旋转2位得到的结果"cdefgab"。

注意：
数据保证n小于等于输入字符串的长度。

样例
输入："abcdefg" , n=2
输出："cdefgab"

*/

class Solution {
public:
    string leftRotateString(string str, int n) {
        return str.substr(n)+str.substr(0, n);
    }
};
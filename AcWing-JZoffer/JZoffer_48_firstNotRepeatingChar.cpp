/**	字符串中第一个只出现一次的字符

在字符串中找出第一个只出现一次的字符。
如输入"abaccdeff"，则输出b。
如果字符串中不存在只出现一次的字符，返回#字符。

样例：
输入："abaccdeff"
输出：'b'


*/


class Solution {
public:
    char firstNotRepeatingChar(string s) {
        unordered_map<char, int> map;
        if (!s.size())	return '#';
        for (int i = 0; i < s.size(); i++){
        	map[s[i]] ++;
        }
        for (int i = 0; i < s.size(); i++){
        	if (map[s[i]] == 1)
        		return s[i];
        }
        return '#';
    }
};



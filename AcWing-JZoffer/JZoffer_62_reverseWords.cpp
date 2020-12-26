/**	翻转单词顺序

输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
为简单起见，标点符号和普通字母一样处理。
例如输入字符串"I am a student."，则输出"student. a am I"。

样例
输入："I am a student."
输出："student. a am I"

*/

//Solution 1, 枚举
class Solution {
public:
    string reverseWords(string s) {
        vector<string> data;
        string ans = "";
        string temp = "";
        for (int i = 0; i < s.size(); i++) {
        	if (s[i] != ' ') temp += s[i];
        	else data.push_back(" " + temp), temp="";
        }
        data.push_back(temp);

        for (int i = data.size()-1; i >= 0; i--) {
        	ans += data[i];
        }

        return ans;
    }
};

//Solution 2, 双指针，先翻转整串，再翻转单词
class Solution {
public:
	string reverseWords(string s) {
		reverse(s.begin(), s.end());
		for (int i = 0, j; i < s.size(); i++) {
			j = i;
			while (j < s.size() && s[j] != ' ')
				j++;
			reverse(s.begin()+i, s.begin()+j);
			i = j;
		}
		return s;
	}
};
/**	最长不含重复字符的子字符串	🌟🌟

请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。
假设字符串中只包含从’a’到’z’的字符。

样例
输入："abcabc"
输出：3

思路
双指针，哈希表，O(n)

设立 i j 两个指针，对应字符串中不重复的子字符串的左右端，可以知道 j 右移的过程中 i 一定也是单调右移的
在哈希表中保存 i j 之间的字符的重复情况，每次 j 右移一位，对应字符哈希值加一，
遇到未重复的字符就哈希值加一(使之哈希值为1)，遇到重复的字符(哈希值加一之后大于1)
则 i 开始右移，每次把 i 位置的哈希值减去 1 直到遇到重复的字符，减去 1 会让 j 所处的字符
的哈希值对应减去 1 变成 1。计算 i j 之间的距离作为本次子串的长度（子串始于i终于j

*/


class Solution {
public:
    int longestSubstringWithoutDuplication(string s) {
        unordered_map<char, int> map;
        int ans = 0;
       	for (int i = 0, j = 0; j < s.size(); j++){
       		map[s[j]] ++;
       		while (map[s[j]] > 1){
       			map[s[i]] --;
       			i++;
       		}
       		ans = max(ans, j-i+1);
       	}
       	return ans;
    }
};




/*	去除重复字母

给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。
需保证返回结果的字典序最小（要求不能打乱其他字符的相对位置）。

示例 1：
输入：s = "bcabc"
输出："abc"

示例 2：
输入：s = "cbacdcbc"
输出："acdb"
 
提示：
1 <= s.length <= 104
s 由小写英文字母组成

思路：
关键字符：
用栈管理遍历过的字符

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicate-letters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <algorithm>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
    	string st;
    	vector<int> num(26), stackExist(26);	
    	//num[] : how many char haven't been iterated
    	//stackExist[] : is there already this char in stack

    	for (char ch : s){
    		num[ch - 'a'] ++;
    	}
    	for (char ch : s){
    		if (!stackExist[ch - 'a']){
    			while(!st.empty() && st.back() > ch){
    				//top of stack be the 'key element' to delete
    				if (num[st.back()-'a'] > 0){
    				//this char will occur later, pls delete it 
    					stackExist[st.back() - 'a'] = 0;
    					st.pop_back();
    				}else{
    				//this char will not occur later, stop the loop
    					break;
    				}
    			}
    			stackExist[ch-'a'] = 1;
    			st.push_back(ch);
    		}
    		num[ch-'a']--;
    	}
    	return st;
    }
};












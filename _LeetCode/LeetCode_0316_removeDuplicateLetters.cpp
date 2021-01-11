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

最简单的情况中，如果给定一个字符串，去除其中的一个字符，使得剩下的字符串的字典序最小
我们需要做的是找出最小的满足s[i] > s[i+1]的下标i，然后去除字符s[i]。
我们将这个字符称为【关键字符】。

可以想到的做法是，从前往后遍历整个字符串，每到一个位置，尽可能地循环处理所有的关键字符
同时我们需要保证处理的过程中，题目其他条件也满足，包括：
没有重复元素、原字符中的所有字母都需要出现在结果中、不能打乱相对位置。

我们用栈的思想来维护去除关键字符后得到的字符串。对于遍历到的新的位置，
如果栈顶字符大于当前字符，那我们需要将栈顶元素出栈，然后继续比较新的栈顶元素和当前字符
直到栈顶元素不大于当前字符或者栈中没有元素，然后把当前字符加入栈中。

同时，为了保证去除关键字符的过程中满足原字符串中所有字符都出现在结果字符串中，
我们需要对算法做出一点改进：
1. 我们考虑字符s[i]时，如果其已经存在于栈中，那就不能让其入栈
————需要记录栈中已存在字符
2. 弹出栈顶字符的时候，如果后续待遍历的元素中已经没有这个元素，那么同样不能让他出栈
————需要记录每个字符的剩余数量



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












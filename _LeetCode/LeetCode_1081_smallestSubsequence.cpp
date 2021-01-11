/*	不同字符的最小子序列

返回 s 字典序最小的子序列，该子序列包含 s 的所有不同字符，且只包含一次。

示例 1：
输入：s = "bcabc"
输出："abc"
示例 2：
输入：s = "cbacdcbc"
输出："acdb"

提示：
1 <= s.length <= 1000
s 由小写英文字母组成

思路：
本题解法同LeetCode_0361

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/smallest-subsequence-of-distinct-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
#include <algorithm>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution {
public:
    string smallestSubsequence(string s) {
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
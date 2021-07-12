/* 最长回文子串

给你一个字符串 s，找到 s 中最长的回文子串。
示例 1：
输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。

示例 2：
输入：s = "cbbd"
输出："bb"

示例 3：
输入：s = "a"
输出："a"

示例 4：
输入：s = "ac"
输出："a"

提示：
1 <= s.length <= 1000
s 仅由数字和英文字母（大写和/或小写）组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindromic-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
// 解法1： DP  时间O(n^2) 空间O(n^2)
// 状态转移方程    dp(i,j) = dp(i+1,j-1) && (s[i]==s[j])
// 边界条件1      dp(i,i) = true
// 边界条件2      dp(i,i+1) = (s[i]==s[i+1])   
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2){
            return s;
        }

        int maxLen = 1;
        int begin = 0;
        // dp[i][j]表示s[i...j]是否回文串
        vector<vector<int>> dp(n, vector<int>(n));
        // 长度为1的都是回文串
        for (int i = 0; i < n; i++){
            dp[i][i] = true;
        }
        // 递推，枚举子串长度
        for (int L = 2; L <= n; L++){
            for (int i = 0; i < n; i++){
                int j = i + L -1;
                if (j >= n) break;
                if (s[i] != s[j]){
                    dp[i][j] = false;
                }else{
                    if (j - i < 3){
                        dp[i][j] = true;
                    }else{
                        dp[i][j] = dp[i+1][j-1];
                    }
                }
                // 如果上面dp[i][j]==true，即s[i][j]是回文，则记录回文长度和起始位置
                if (dp[i][j] && j-i+1>maxLen){
                    maxLen = j - i + 1;
                    begin = i;
                } 
            }
        }
        return s.substr(begin, maxLen);
    }
};


// 解法2： 中心扩展算法  时间O(n^2) 空间O(n)
// 思路：边界情况对应的子串是我们扩展出的回文串的回文中心————枚举所有回文中心并尝试扩展直到无法扩展为止
class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++){
            auto [left1, right1] = expandAroundCenter(s, i, i);
            auto [left2, right2] = expandAroundCenter(s, i, i+1);
            if (right1 - left1 > end - start){
                start = left1;
                end = right1;
            }
            if (right2 - left2 > end - start){
                start = left2;
                end = right2;
            }
        }
        return s.substr(start, end - start + 1);
    }

    pair<int,int> expandAroundCenter(const string& s, int left, int right){
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return {left+1, right-1};
    }
};






















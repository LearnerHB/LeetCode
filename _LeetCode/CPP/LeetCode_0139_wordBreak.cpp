/*    
给定一个非空字符串 s 和一个包含非空单词的列表 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

说明：

拆分时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。

示例
输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。

*/    
// Sol 1: 动态规划
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordDictSet;
        for (auto word : wordDict) {
            wordDictSet.insert(word);
        }
        // dp[j]表示字符串的前j位可以拆分成列表单词
        // dp[j] = dp[i] && s[i,j)出现在字典中
        vector<bool> dp(s.size()+1, false); 
        dp[0] = true;
        for (int i = 0; i < s.size(); i++) {
            if (!dp[i]) {
                continue;
            }
            for (auto word :wordDict) {
                if (word.size() + i <= s.size() && s.substr(i, word.size()) == word) {
                    dp[i + word.size()] = true;
                }
            }
        }
        return dp[s.size()];
    }
};






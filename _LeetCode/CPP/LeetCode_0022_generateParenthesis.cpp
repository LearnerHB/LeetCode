/*
数字 n代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

示例 1：

输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]
示例 2：

输入：n = 1
输出：["()"]

提示：
1 <= n <= 8
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/generate-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

// Sol 1 精简强大版 动态规划
// fn是在fn-1的基础上加一对括号: "(" + p*() + ")" + q*()，其中p+q=n-1
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n+1);
        dp[0] = { "" };
        dp[1] = { "()" };
        for (int i = 2; i <= n; i++){
            for (int j = 0; j < i; j++) {
                for (string p : dp[j]) {
                    for (string q : dp[i-1-j]) {
                        string str = "(" + p + ")" + q;
                        dp[i].push_back(str);
                    }
                }
            }
        }
        return dp[n];
    }
};
// Sol 2 递归
// 剩余左括号的总数要小于等于右括号
class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        if (n <= 0) return res;
        getParenthesis("", n, n);
        return res;
    }

    void getParenthesis(string str, int left, int right) {
        if (left == 0 && right == 0){
            res.push_back(str);
            return;
        }
        //剩余左右括号数量相等，只能用左括号
        if (left == right){
            getParenthesis(str+"(", left-1, right);
        } else if (left < right) {
            if (left > 0) {
                getParenthesis(str+"(", left-1, right);
            }
            getParenthesis(str+")", left, right-1);
        }
    }
};









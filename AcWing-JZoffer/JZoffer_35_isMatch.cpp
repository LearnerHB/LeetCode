/**	正则表达式匹配		🌟🌟🌟

请实现一个函数用来匹配包括'.'和'*'的正则表达式。

模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。
在本题中，匹配是指字符串的所有字符匹配整个模式。
例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配。

样例

输入：
s="aa"
p="a*"
输出:true

思路
(动态规划)
状态表示：f[i][j]表示p从j开始到结尾，是否能匹配s从i开始到结尾
状态转移：

1. 如果p[j+1]不是通配符'*'，则f[i][j]是真，当且仅当s[i]可以和p[j]匹配，且f[i+1][j+1]是真；
2. 如果p[j+1]是通配符'*'，则下面的情况只要有一种满足，f[i][j]就是真；
	f[i][j+2]是真；——> 表示 a* 枚举0个 a；
	s[i]可以和p[j]匹配，且f[i+1][j]是真；——> 表示 a* 枚举1个以及以上的 a ，各种情况都包含在f[i+1][j]中

*/

class Solution {
public:
	int n, m;
	vector<vector<int>> f;	//作为动态规划的计算数组，要求的是f[x][y]
    bool isMatch(string s, string p) {
        n = s.size();
        m = p.size();
        f = vector<vector<int>>(n+1, vector<int>(m+1, -1));
        return dp(0, 0, s, p);
    }

    bool dp(int x, int y, string &s, string &p){
    	if (f[x][y] != -1)
    		return f[x][y];
    	if (y == m)
    		return f[x][y] = x == n;	// ???


    	bool first_match = (x<n && (s[x]==p[y] || p[y]=='.'));
    	bool ans;
    	if (y + 1 < m && p[y+1]=='*')
    		ans = dp(x, y+2, s, p) || first_match && dp(x+1, y, s, p);
    	else 
    		ans = first_match && dp(x+1, y+1, s, p);
    	return f[x][y] = ans;
    }
};

/**	矩阵中的路径

请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
如果一条路径经过了矩阵中的某一个格子，则之后不能再次进入这个格子。

注意：
输入的路径不为空；
所有出现的字符均为大写英文字母；

样例
matrix=
[
  ["A","B","C","E"],
  ["S","F","C","S"],
  ["A","D","E","E"]
]
str="BCCE" , return "true" 
str="ASAE" , return "false"

思路：
深度优先搜索，O(n^2 * 3^k) 
单词起点一共有 n2 个，单词的每个字母一共有上下左右四个方向可以选择，
但由于不能走回头路，所以除了单词首字母外，仅有三种选择
这里的 k 指的是路径的平均长度

如果不考虑使用额外的数组存储字母遍历状态，可以在枚举过每个字母的时候
把这个字母改成一个特殊字符，以避免重复使用字符

*/

class Solution {
public:
    bool hasPath(vector<vector<char>>& matrix, string &str) {
    	vector<vector<char>> st = matrix;
    	for (int i = 0; i < matrix.size(); i++)
    		for (int j = 0; j < matrix[i].size(); j++)
    			if (dfs(matrix, str, 0, i, j))
    				return true;
    	return false;
    }

   	bool dfs(vector<vector<char>>& matrix, string &str, int u, int x, int y){
   		// u 表示当前已匹配字符串长度
   		if (matrix[x][y] != str[u])	//当前字母不匹配，已有串匹配失败
   			return false;
   		if (u == str.size() - 1)	//当前字母匹配且长度满足，已有串匹配成功
   			return true;
   		int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
   		char temp = matrix[x][y];	//暂时保存当前字母，以便回溯
   		matrix[x][y] = '*';
   		for (int i = 0; i < 4; i++){	//往四个方向继续枚举（其中一个方向是来时的方向，之后会无效
   			int a = x + dx[i], b = y + dy[i];
   			if (a >= 0 && a < matrix.size() && b >= 0 && b < matrix[a].size())
   				if (dfs(matrix, str, u+1, a, b))
   					return true;
   		}
   		matrix[x][y] = temp;
   		return false;
   	}
};






















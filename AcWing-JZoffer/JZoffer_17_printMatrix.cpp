/**	顺时针打印矩阵 ★★★

输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

样例
输入：
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]

思路
顺时针定义四个方向，上右下左，左上角开始遍历，按一个方向走到不能走为止就更改到下一个方向

*/

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
    	vector<int> ans;
        if (matrix.empty())
        	return ans;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<bool> > visited(n, vector<bool>(m, false));	//维护一个已访问矩阵
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};			//四个方向 左上右下
        int x = 0, y = 0, d = 1;
        for (int k = 0; k < n * m; k++){
        	ans.push_back(matrix[x][y]);
        	visited[x][y] = true;

        	int a = x + dx[d], b = y + dy[d];
        	if (a < 0 || a >= n || b < 0 || b >= m || visited[a][b]){
        		d = (d+1) % 4;
        		a = x + dx[d], b = y + dy[d];
        	}
        	x = a, y = b;
        }
        return ans;
    }
};





/** n皇后

n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

示例：
输入：4
输出：[
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],
 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]
解释: 4 皇后问题存在两个不同的解法。

提示：
皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。

思路
1. 基于集合的回溯 	时间O(N!) 空间O(N)
对数组每行，第一行有N个位置可选，第二行最多N-1个（还需要再判断斜线），依次类推，遍历这些的时间复杂度O(N!)
如何判断斜线上是否已经存在元素：
	对于左上到右下的斜线，同一斜线上的元素，横纵坐标之差相等；
	对于右上到左下的斜线，同一斜线上的元素，横纵坐标之和相等。
对每行进行放置的时候，用三个集合分别表示列方向和两个斜线方向的放置情况
每次放置皇后的时候，对于每个位置判断是否在三个集合当中

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/n-queens
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutions;
        vector<int> queens(n, -1);
        unordered_set<int> columns, diagonals1, diagonals2;
        backTrack(solutions, queens, n, 0, columns, diagonals1, diagonals2);
        return solutions;
    }
    void backTrack(vector<vector<string>>& solutions, vector<int> &queens, int n, int row, unordered_set<int> &columns, unordered_set<int>& diagonals1, unordered_set<int>& diagonals2) {
    	if (row == n) {
    		solutions.push_back(generateBoard(queens, n));
    	}
    	else {
    		for (int i = 0; i < n; i++) {
    			if (columns.find(i) != columns.end())			continue;
    			int d1 = row - i;
    			if (diagonals1.find(d1) != diagonals1.end())	continue;
    			int d2 = row + i;
    			if (diagonals2.find(d2) != diagonals2.end()) 	continue;

    			queens[row] = i;
    			columns.insert(i);
    			diagonals1.insert(d1);
    			diagonals2.insert(d2);
    			backTrack(solutions, queens, n, row+1, columns, diagonals1, diagonals2);
    			queens[row] = -1;
    			columns.erase(i);
    			diagonals1.erase(d1);
    			diagonals2.erase(d2);
    		}
    	}	
    }
    vector<string> generateBoard(vector<int> &queens, int n) {
    	vector<string> board;
    	for (int i = 0; i < n; i++) {
    		string row = string(n, '.');
    		row[queens[i]] = 'Q';
    		board.push_back(row);
    	}
    	return board;
    }
};














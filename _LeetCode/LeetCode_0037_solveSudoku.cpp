/**	解数独	Hash / 回溯

编写一个程序，通过已填充的空格来解决数独问题。
一个数独的解法需遵循如下规则：

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
空白格用 '.' 表示。

Note:
给定的数独序列只包含数字 1-9 和字符 '.' 。
你可以假设给定的数独只有唯一解。
给定数独永远是 9x9 形式的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sudoku-solver
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


*/
class Solution {
public:
	bool line[9][9];
	bool column[9][9];
	bool block[3][3][9];
	bool valid;
	vector<pair<int, int>> spaces;

	void dfs(vector<vector<char>>& board, int pos) {
		if (pos == spaces.size()) {
			valid = true;
			return;
		}

		auto [i, j] = spaces[pos]; 
		for (int digit = 0; digit < 9 && !valid; digit++) {
			if (!line[i][digit] && !column[j][digit] && !block[i/3][j/3][digit]) {
				line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = true;
				board[i][j] = digit + '0' + 1;
				dfs(board, pos+1);
				line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = false;
			}
		}
	}

    void solveSudoku(vector<vector<char>>& board) {
        memset(line, false, sizeof(line));
        memset(column, false, sizeof(column));
        memset(block, false, sizeof(block));
        valid = false;

        for (int i = 0; i < 9; i++) {
        	for (int j = 0; j < 9; j++) {
        		if (board[i][j] == '.' ) {
        			spaces.emplace_back(i, j);
        		}
        		else{
        			int digit = board[i][j] - '0' - 1;
        			line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = true;
        		} 
        	}
        }

        dfs(board, 0);
    }
};


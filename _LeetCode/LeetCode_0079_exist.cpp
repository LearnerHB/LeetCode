/**
给定一个二维网格和一个单词，找出该单词是否存在于网格中。
单词必须按照字母顺序，通过相邻的单元格内的字母构成
其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

示例:
board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
给定 word = "ABCCED", 返回 true
给定 word = "SEE", 返回 true
给定 word = "ABCB", 返回 false
 
提示：
board 和 word 中只包含大写和小写英文字母。
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-search
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


*/


class Solution {
public:
	int dir[4][4]={{-1,0},{1,0},{0,-1},{0,1}};
	bool dfs(int x,int y,int index,vector<vector<char>>& board,string &word,vector<vector<bool>>& visited){
	    if(index==word.size()-1){
	        return word[index]==board[x][y];
	    }
	    
	    if(word[index]==board[x][y]){
	        visited[x][y]=true;
	        for(int i=0;i<4;i++){
	            int new_x=x+dir[i][0];
	            int new_y=y+dir[i][1];
	            
	            if(new_x>=0&&new_x<board.size()&&new_y>=0&&new_y<board[0].size()&&!visited[new_x][new_y])
	                if(dfs(new_x,new_y,index+1,board,word,visited))
	                    return true;
	        }
	        visited[x][y]=false;
	        
	    }
	    return false;
	}
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
	    int n=board[0].size();
	    vector<vector<bool>> visited(m,vector<bool>(n));
	    
	    for(int i=0;i<m;i++){
	        for(int j=0;j<n;j++){
	            if(dfs(i,j,0,board,word,visited))
	                return true;
	        }
	    }
	    return false;
    }
};



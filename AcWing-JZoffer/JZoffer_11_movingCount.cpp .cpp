/** 机器人的运动范围

地上有一个 m 行和 n 列的方格，横纵坐标范围分别是 0∼m−1 和 0∼n−1。
一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格。
但是不能进入行坐标和列坐标的数位之和大于 k 的格子。
请问该机器人能够达到多少个格子？

样例1
输入：k=7, m=4, n=5
输出：20

样例2
输入：k=18, m=40, n=40
输出：1484

解释：当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
      但是，它不能进入方格（35,38），因为3+5+3+8 = 19。

注意:
0<=m<=50
0<=n<=50
0<=k<=100

思路：
1. 宽度优先搜索，从(0, 0)开始，向上下左右四个方向不断扩展新节点，设立一个队列来新加入节点，维护bool数组来保存遍历与否信息
时间复杂度：O(nm)
2. 深度优先搜索
时间复杂度：O(nm)

*/

class Solution_BFS {
public:
	int getSum(pair<int, int> p){
		int sum = 0;
		while (p.first){
			sum += p.first % 10;
			p.first /= 10;
		}
		while (p.second){
			sum += p.second % 10;
			p.second /= 10;
		}
		return sum;
	}
    int movingCount(int threshold, int rows, int cols){
        if (!rows || !cols)
        	return 0;
        queue<pair<int,int>> q;	//保存待查看节点
        vector<vector<bool>> status(rows, vector<bool>(cols, false));	//保存遍历状态，初始false

        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}; //各点扩展的四个方向

       	int result = 0;	
       	q.push({0, 0});	
       	while (q.size()){
       		auto cur = q.front();	//取出队列首个进行判断
       		q.pop();
       		if (status[cur.first][cur.second] || getSum(cur) > threshold)	//如果已经遍历过 或者 数位和越界，则跳过
       			continue;
       		result++;
       		status[cur.first][cur.second] = true;	//标记已遍历
       		for (int i = 0; i < 4; i++){	//向四个方向扩展
       			int x = cur.first + dx[i], y = cur.second + dy[i];
       			if (x >= 0 && x < rows && y >=0 && y < cols)
       				q.push({x, y});
       		}
       	}
       	return result;
    }
};

class Solution_DFS{
public:
	//注意函数中，由于传递的是形参，故需要在st之前添加 & 引用，代表数组被修改
	int movingCount(int threshold, int rows, int cols){
		vector<vector<bool>> status(rows, vector<bool>(cols));
		return dfs(threshold, 0, 0, status);
	}
	int dfs(int th, int i, int j, vector<vector<bool>> &status){
		if (i<0 || i>=status.size() || j<0 || j>=status[i].size() || status[i][j] || (i/10+i%10+j/10+j%10)>th)
			return 0;
		status[i][j] = true;
		return dfs(th, i+1, j, status) + dfs(th, i-1, j, status) + dfs(th, i, j+1, status) + dfs(th, i, j-1, status) + 1;
	}
};


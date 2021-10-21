/*    ★★★ 课程表 (可结合LeetCode_0210一起看
你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。
在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，
其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。
例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。

*/    
// Sol 1 拓扑排序 DFS
// 利用拓扑排序判断课程表是个有向无环图DAG
// 每个节点用0，1，2分别标记未搜索，搜索中，已完成三种状态
class Solution {
private:
    vector<vector<int>> edges;
    vector<int> visited;
    bool valid = true;
public:
    
    void dfs(int u) {
        visited[u] = 1;
        for (int v : edges[u]) {
            if (visited[v]==0) {
                dfs(v);
                if (!valid) {
                    return;
                }
            } else if (visited[v]==1) {
                // 存在环，则不存在合法拓扑结构
                valid = false;
                return;
            }
        }
        visited[u] = 2;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        // 根据前置课程情况构建节点边关系
        for (const auto& info : prerequisites) {
            edges[info[1]].push_back(info[0]);
        }
        for (int i = 0; i < numCourses; i++) {
            if (visited[i]==0) {
                dfs(i);
            }
        }
        return valid;
    }
};

// Sol 2 拓扑排序 BFS
// 用队列进行广度优先搜索，初始先放入 入度 为0的节点，作为拓扑排序最前面的节点且相对顺序无关紧要
// 取出队首节点之后，将u放入答案队列（如果需要返回一个合法拓扑排序的话），
// 然后移除u的出边，即其相邻节点的入度减少1，如果某个相邻节点的入度变成0，将其加入队列中
class Solution {
private:
    vector<vector<int>> edges;
    vector<int> indegree;
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        indegree.resize(numCourses);
        for (const auto& info : prerequisites) {
            edges[info[1]].push_back(info[0]);
            indegree[info[0]]++;
        } 
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i]==0) {
                q.push(i);
            }
        } 
        int visited = 0; // 用来记录已经被放入答案数组的节点个数，BFS结束之后判断是否等于课程数即可
                // 如果结果需要返回一个合法的拓扑排序的话就要用过程中的答案数组来记录，本题用该变量即可
        while (!q.empty()) {
            visited++;
            int u = q.front();
            q.pop();
            for (int v: edges[u]) {
                --indegree[v];
                if (indegree[v]==0) {
                    q.push(v);
                }
            }
        }
        return visited == numCourses;
    }
};
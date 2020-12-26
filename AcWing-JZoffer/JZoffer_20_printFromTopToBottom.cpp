/*  ★★打印二叉树★★   */

/**	题目1：不分行从上往下打印二叉树

从上往下打印出二叉树的每个结点，同一层的结点按照从左到右的顺序打印。

样例
输入如下图所示二叉树[8, 12, 2, null, null, 6, null, 4, null, null, null]
    8
   / \
  12  2
     /
    6
   /
  4
输出：[8, 12, 2, 6, 4]

思路
宽度优先搜索遍历整棵树，先左儿子后右儿子。用一个处理队列依次放入需要处理的节点。
时间复杂度O(n)

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> printFromTopToBottom(TreeNode* root) {
    	vector<int> res;
    	if (!root)
    		return res;
    	queue<TreeNode*> q;
    	q.push(root);

    	while (q.size()){
    		auto temp = q.front();
    		q.pop();
    		res.push_back(temp->val);
    		if (temp->left)
    			q.push(temp->left);
    		if (temp->right)
    			q.push(temp->right);
    	}

    	return res;
    }
};


/** 题目2：分行从上往下打印二叉树

从上往下打印出二叉树的每个结点，同一层的结点按照从左到右的顺序打印
每一层打印到一行

样例
输入如下图所示二叉树[8, 12, 2, null, null, 6, null, 4, null, null, null]
    8
   / \
  12  2
     /
    6
   /
  4
输出：[[8], [12, 2], [6], [4]]

思路
在上面的基础之上修改代码，每一层结束的时候在queue队列里面塞一个NULL标记
每次在queue中取数都判断是不是层结束符NULL（BFS决定了每层读完的时候下一层的也都在queue里）
是的话就再判断是否整棵树都读完（即queue中是否还有点）

时间复杂度
O(n)

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> printFromTopToBottom(TreeNode* root) {
      vector<vector<int>> res;
      if (!root)
        return res;
      queue<TreeNode*> q;
      q.push(root);
      q.push(NULL);


      vector<int> cur;  //暂存当前层的数据
      while (q.size()){
        auto temp = q.front();
        q.pop();

        if (temp){  //如果未到结束符，当前节点非NULL，则进行和之前代码一样的操作
          cur.push_back(temp->val); //注意这里是输入到当前层的数据中
          if (temp->left)
            q.push(temp->left);
          if (temp->right)
            q.push(temp->right);
        }
        else {
          if (q.size())
            q.push(NULL);
          res.push_back(cur);
          cur.clear();
        }
      }

      return res;
    }
};

/** 题目3：之字形打印二叉树

实现一个函数按照之字形顺序从上向下打印二叉树。
即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。

样例
输入如下图所示二叉树[8, 12, 2, null, null, 6, 4, null, null, null, null]
    8
   / \
  12  2
     / \
    6   4
输出：[[8], [2, 12], [6, 4]]

思路
宽度优先遍历。和上题分行打印思路类似，再此基础上，添加一个表示层数的变量，用来决定打印方向
如果需要反转打印方向，在把当层数组加入最终答案的时候，对数组进行翻转
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> reverseArray(vector<int> a){
      reverse(a.begin(), a.end());
      return a;
    }

    vector<vector<int>> printFromTopToBottom(TreeNode* root) {
      vector<vector<int>> res;
      if (!root)
        return res;
      queue<TreeNode*> q;
      
      q.push(root);
      q.push(NULL);
      int level = 1;  //层数，用来决定该层顺序

      vector<int> cur;  //暂存当前层的数据
      while (q.size()){
        auto temp = q.front();
        q.pop();

        if (temp){  //如果未到结束符，当前节点非NULL，则进行和之前代码一样的操作
          cur.push_back(temp->val); //注意这里是输入到当前层的数据中
          if (temp->left)
            q.push(temp->left);
          if (temp->right)
            q.push(temp->right);
        }
        else {
          if (q.size())
            q.push(NULL);
          if (level%2==1)
            res.push_back(cur);
          else 
            res.push_back(reverseArray(cur)); //使用STL库reverse函数，需要包含<algorithm>头文件
          cur.clear();
          level++;    //到下一层
        }
      }
      return res;
    }
};












